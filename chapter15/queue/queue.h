#ifndef QUEUE_H_
#define QUEUE_H_

template <class Item>
class QueueTP
{
private:
    enum
    {
        Q_SIZE = 10
    };
    class Node
    {
    public:
        Item item;
        Node *next;
        Node(const Item &item) : item(item), next(0) {}
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;
    QueueTP(const QueueTP &q) : qsize(0) {}
    QueueTP &operator=(const QueueTP &q) { return *this; }

public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int queueCount() const;
    bool enqueue(const Item &);
    bool dequeue(Item &);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = 0;
    items = 0;
}

template<class Item>
QueueTP<Item>::~QueueTP(){
    Node *temp;
    while (front != 0)
    {
        /* code */
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<class Item>
bool QueueTP<Item>::isempty() const{
    return items==0;
}

template<class Item>
bool QueueTP<Item>::isfull() const{
    return items >= qsize;
}

template<class Item>
int QueueTP<Item>::queueCount() const{
    return items;
}

template<class Item>
bool QueueTP<Item>::enqueue(const Item &item){
    if(isfull()) return false;

    Node *add = new Node(item);

    if(front == 0){
        front = add;
    }else{
        rear->next = add;
    }
    rear = add;
    items ++;
    return true;
}

template<class Item>
bool QueueTP<Item>::dequeue(Item &item){
    if(isempty()) return false;

    item = front->item;
    Node *temp = front;
    front = front->next;
    delete temp;
    items --;
    return true;
}
#endif