#include <iostream>
using namespace std;


#define CALL_WITH_MAX(a, b) f(a>b?a:b)

int main(){
    int a = 5, b = 0;
    CALL_WITH_MAX(++a, b);
}