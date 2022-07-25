#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseDisplay(Node *head, int pos)
{
    int count = 1;
    while (head != NULL && count < pos)
    {
        head = head->next;
        count++;
    }
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 22);
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtHead(head, 8);
    display(head);

    return 0;
}