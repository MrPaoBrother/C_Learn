#ifndef BANK_QUEUE_H
#define BANK_QUEUE_H

#include "customer.h"
#include "event.h"

template <typename T>
class Queue
{
public:
    Queue() : _front(nullptr), _rear(nullptr), length(0) {}
    ~Queue();
    void enqueue(T *node);
    void dequeue();

    T *front() const
    {
        return _front;
    }

    void clear();

    const int size() const { return length; }

private:
    T *_front;
    T *_rear;
    int length;
};

template <typename T>
Queue<T>::~Queue()
{
    clear();
}

template <typename T>
void Queue<T>::enqueue(T *node)
{
    if (_rear->next != nullptr)
    {
        _rear->next = node;
        _rear = node;
    }
    else
    {
        _front = node;
        _rear = node;
    }
    length++;
}

template <>
void Queue<Event>::enqueue(Event *event){
    Event *cur = _front, *prev = nullptr;
    while (cur != nullptr)
    {
        /* code */
        if(cur->occurTime < event->occurTime){
            prev = cur;
            cur = cur->next;
        }
    }

    // TODO 这一块有点画蛇添足
    if(prev == nullptr){
        event->next = _front;
        _front = event;
        if(_rear == nullptr){
            _rear = event;
        }
    }else{
        event->next = cur;
        prev->next = event;
        if(prev == _rear){
            _rear = event;
        }
    }

    length ++;
}

template <>
void Queue<Customer>::enqueue(Customer *customer)
{
    customer->next = nullptr;
    if (_rear->next != nullptr)
    {
        _rear->next = customer;
        _rear = customer;
    }
    else
    {
        _front = customer;
        _rear = customer;
    }
    length++;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (_front != nullptr)
    {
        T *tmp = _front;
        _front = _front->next;
        --length;
        free(tmp);
    }

    if (_front == nullptr)
        _rear = nullptr;
}

template <typename T>
void Queue<T>::clear()
{
    while (_front != nullptr)
    {
        /* code */
        dequeue();
    }
}
#endif