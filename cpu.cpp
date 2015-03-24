//
//  cpu.cpp
//  
//
//  Created by Xianzhi Ruan on 15/2/10.
//
//

#include <queue>
#include "cpu.h"
#include <ucontext.h>



void timer_handler(){
    interrupt_disable();
    while(guard.exchange(1)){};
    
    if (!readyQueue.empty()){
        ucontext_t* nextthread = readyQueue.front();
        ucontext_t* curthread = new ucontext_t;
        
        readyQueue.pop();
        readyQueue.push(curthread);
        
        swapcontext(curthread, nextthread);
        delete nextthread;
        guard.store(0);
        
    }
    
    interrupt_enable();
}

void ipi_handler(){
    interrupt_disable();
    while(guard.exchange(1)){};
    if (readyQueue.empty()){
        guard.store(0);
        cpu* temp = cpu::self();
        suspendedCpu.push(temp);
        interrupt_enable_suspend();
    }
    guard.store(0);
    interrupt_enable();
}


void cpu::init(thread_startfunc_t funptr, void *arg){
    
    ucontext_t * ucontext_ptr = new ucontext_t;
    getcontext(ucontext_ptr);
    impl_ptr->savedContext = ucontext_ptr;
    interrupt_vector_table[0] = &timer_handler;
    interrupt_vector_table[1] = &ipi_handler;
    if (thread_startfunc_t == nullptr ) {
        cpu* temp = cpu::self();
        suspendedCpu.push(temp);
        interrupt_enable_suspend();
    }
    else{
        makecontext(ucontext_ptr, (void (*)()) funptr, 1, arg);
    }
    
    while (1){
        if (readyQueue.empty()) {
            cpu* temp = cpu::self();
            suspendedCpu.push(temp);
            interrupt_enable_suspend();
        }
        else{
            ucontext_t* nextthread = readyQueue.front();
            readyQueue.pop();
            ucontext_t* temp = new ucontext_t;
            swapcontext(temp, nextthread);
            delete nextthread;
        }
    }
}




