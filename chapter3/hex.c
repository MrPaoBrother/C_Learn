#include<stdio.h>
/*
    以8进制 16进制输出100  P.124
*/
int main(void){
    int a = 100;
    printf("dec:%d; octal:%o; hex:%x;\n", a, a, a);
    printf("dec:%d; octal:%#o; hex:%#x", a, a, a);
    return 0;
}