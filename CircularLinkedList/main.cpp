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

void insertAtHead(Node *&head, int val)
{

    Node *n = new Node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteAtHead(Node* &head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

void deletion(Node *&head, int pos)
{

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

bool search(Node* head, int key){
    
    if(head->data==key){
        return true;
    }
    
    Node* temp=head;
    do{
         temp=temp->next;
    }
    while(temp!=head && temp->data!=key);
    if(temp==head)
        return false;
    return true;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 0);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);
    cout<<search(head, 0)<<endl;
    cout<<search(head, 6)<<endl;
    cout<<search(head, 3)<<endl;
    cout<<search(head, 9)<<endl;


    return 0;
}