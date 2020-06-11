#include<iostream>
using namespace std;

template <typename T>

void Swap(T &a, T &b);

int main(void){
    int a=1, b =2;
    Swap(a, b);

    cout << a << " " << b << endl;

    double c=1.1, d =1.2;
    Swap(c, d);

    cout << c << " " << d << endl;

    return 0;
}

template<typename T>
void Swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}