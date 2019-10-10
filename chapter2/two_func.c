#include<stdio.h>

void output(void);/* ANSI/IOS标准 */

int main(void){
    printf("begin\n");
    output();
    printf("end\n");
}

void output(void){
    printf("process\n");
}