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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
    if (tail == NULL)
    {
        tail = head;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteFromHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    if (head == NULL)
        tail = NULL;
}

void deleteFromTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
}

void deleteByValue(Node *&head, Node *&tail, int key)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->data == key)
    {
        deleteFromHead(head, tail);
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    prev->next = curr->next;
    if (curr == tail)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void search(Node *head, int key)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << key << " not found in the list\n";
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int choice, val, pos;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete by value\n";
        cout << "7. Search element\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtHead(head, tail, val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtTail(tail, head, val);
            break;

        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> val;
            insertAtPosition(head, tail, pos, val);
            break;

        case 4:
            deleteFromHead(head, tail);
            break;

        case 5:
            deleteFromTail(head, tail);
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteByValue(head, tail, val);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            search(head, val);
            break;

        case 8:
            cout << "Linked List: ";
            print(head);
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 9);

    return 0;
}