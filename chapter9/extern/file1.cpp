#include<iostream>
using namespace std;
extern int tom;

void show_access(){
    cout << &tom << "=&tom";
}