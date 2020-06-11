#include<iostream>
using namespace std;

inline double square(double x){return x*x;}

void swap(int &a, int &b);

int main(void){
    cout << square(1+2) <<endl;
    cout << square(3) << endl;

    int a=1,b=2;
    
    swap(a, b);
    printf("a=%d, b=%d", a, b);
    return 0;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}