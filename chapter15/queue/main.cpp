#include "queue.h"

#include <iostream>
using namespace std;

int main()
{
    QueueTP<int> queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    if (!queue.enqueue(4))
    {
        cout << "current qsize is:" << queue.queueCount() << " full now" << endl;
    }

    while (!queue.isempty())
    {
        /* code */
        int num;
        queue.dequeue(num);
        cout << num << " ";
    }
    cout << endl;
    return 0;
}