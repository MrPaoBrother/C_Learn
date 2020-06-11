#include "crab.h"
#include<iostream>
using namespace std;

// typedef Crab<Stack> crab_stack;
using crab_stack = Crab<Stack>;
int main(){
    crab_stack crab;
    crab.push(1);
    int num;
    crab.pop(num);
    cout << num << endl;
    return 0;
}