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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findMiddle(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        insertAtTail(head, tail, arr[i]);
    }

    cout << "Linked List: ";
    print(head);

    cout << "Middle element: " << findMiddle(head) << endl;

    return 0;
}