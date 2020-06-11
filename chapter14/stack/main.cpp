#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);

    while (!s.isempty())
    {
        /* code */
        int num;
        s.pop(num);
        cout << num << " ";
    }
    cout << endl;
    return 0;
}