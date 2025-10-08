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
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int deleteAllOccurrences(Node *&head, int key)
{
    int count = 0;

    while (head != NULL && head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            Node *temp = curr;
            curr = curr->next;
            delete temp;
            count++;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return count;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int i = 0; i < 7; i++)
    {
        insertAtTail(head, tail, arr[i]);
    }

    cout << "Original List: ";
    print(head);

    int key = 1;
    int count = deleteAllOccurrences(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    print(head);

    return 0;
}