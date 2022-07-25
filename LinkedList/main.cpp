#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *n);
void push(Node **head_ref, int new_data);
void insertAfter(Node *prev_node, int new_data);
void append(Node **head_ref, int new_data);
void deleteNode(Node **headref, int key);
void deleteNodePos(Node **headref, int pos);

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    printList(head);

    push(&head, 1);
    cout << endl;
    printList(head);

    insertAfter(second, 4);
    cout << endl;
    printList(head);

    append(&head, 6);
    cout << endl;
    printList(head);

    deleteNode(&head, 5);
    cout << endl;
    printList(head);

    deleteNodePos(&head, 0);
    cout << endl;
    printList(head);
    return 0;
}

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref); // Make the new node point to the address value stored in head
                                  // through *headref.
    (*head_ref) = new_node;       // finally change the value of head to point towards new node.
}

void insertAfter(Node *prev_node, int new_data)
{

    if (prev_node == NULL)
    {
        cout << "Cannot be inserted after Null." << endl;
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) // If LL is empty make new_node as head
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) // the last pointer pointing to the head will traverse
    {                          // the list until it hits null, that is the last node and then
                               // makes the last node pointing to the new last node created above
        last = last->next;
    }
    last->next = new_node;
    return;
}

void deleteNode(Node **headref, int key)
{
    Node *temp = *headref;
    Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *headref = temp->next;
        delete temp;
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}

void deleteNodePos(Node **headref, int pos)
{

    if (*headref == NULL)
        return;

    Node *temp = *headref;

    if (pos == 0)
    {
        *headref = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}