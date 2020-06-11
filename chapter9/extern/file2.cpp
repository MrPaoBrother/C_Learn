#include <iostream>
using namespace std;

void remote_access();
int tom = 3;

int main(void){
    cout << &tom << "=&tom" << endl;

    remote_access();
    return 0;
}
