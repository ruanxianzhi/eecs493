#include <iostream>
#include <vector>

using namespace std;

const int flyminus = 52;
int alreadyfinish = 0;
vector<int> baseaddr = {0, -1, -2, -3};
vector<int> baseadding = {0, 14, 28, 42};
vector<int> turnaroundpoint = {50, 11, 24, 37};
vector<int> turnaroundadding = {20, 41, 34, 27};
vector<int> flybase1 = {14, 27, 40, 1};
vector<int> flybase2 = {18, 31, 44, 5};
vector<int> flyend = {30, 43, 4, 17};
vector<int> colorjump = {2, 3, 0, 1};
vector<int> endpoint = {76, 58, 64, 70};