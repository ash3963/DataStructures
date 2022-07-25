#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int val)
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
}

void insertAtHead(Node* &head, int val){

    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }

    n->next=head;
    head=n;
}

bool search(Node* head, int key){

    Node* temp= head;
    if(temp==NULL)
        return false;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){ 
        return false;
    }
    return true;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(Node* &head, int key){

    Node* temp=head;
    if(head->data==key){
        head=head->next;
        delete temp;
        return;
    }
    Node* prev=temp;
    while(temp->next!=NULL & temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}

void deletionPos(Node* &head, int pos){
    Node* temp=head;
    if(pos==0){
        head=head->next;
        delete temp;
        return;
    }
    Node* prev = temp;
    for(int i=0;temp!=NULL && i<pos;i++){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    delete temp;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head,6);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtHead(head,5);
    display(head);
    deletionPos(head,4);
    display(head);
    
    return 0;
}