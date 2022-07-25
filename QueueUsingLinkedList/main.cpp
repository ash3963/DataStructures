#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{

    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    void enqueue(int val)
    {
        Node *n = new Node(val);
        if (front == NULL)
        {
            back=n;
            front=n;
            return;
        }
        back->next = n;
        back = n;
    }
    void dequeue(){
        if(front==NULL){
            cout<<"Not possible"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }
    int peek(){
        if(front==NULL){
            cout<<"Not possible"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;

    }
};

int main(){


    return 0;
}