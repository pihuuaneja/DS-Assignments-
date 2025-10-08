#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head, tail, arr[i]);
    }

    cout << "Original List: ";
    print(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}