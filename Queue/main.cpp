#include <iostream>
using namespace std;

#define n 100

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1)
            front++;
        back++;
        arr[back] = val;
    }
    void dequeue()
    {
        if (front == -1 || front > back)
            return;
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
            return -1;
        return arr[front];
            
    }
    bool empty()
    {
        if (front == -1 || front > back)
            return true;
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
}