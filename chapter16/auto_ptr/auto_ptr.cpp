#include <iostream>
#include<memory>

using namespace std;

void auto_ptr_demo1();

int main(){
    auto_ptr_demo1();
}

void auto_ptr_demo1(){
    shared_ptr<double> p(new double(3.0));
}