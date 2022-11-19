#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int element)
    {
        prev = NULL;
        data = element;
        next = NULL;
    }
};

class DoubleLL
{
public:
    Node *root;
    Node *last;
    int length;

    DoubleLL()
    {
        root = last = NULL;
        length = 0;
    }

    void push(struct Node *p, int data)
    {
        Node *newNode = new Node(data);
        if (p == NULL)
        {
            root = last = newNode;
            length++;
            return;
        }
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        length++;
    }

    void insertAtBegin(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = root;
        root->prev = newNode;
        root = newNode;
        length++;
        return;
    }

    void insertAfter(struct Node *root, int data, int pos)
    {
        if (pos < 0 || pos > length)
            return;

        if (pos == 0)
        {
            insertAtBegin(data);
            return;
        }
        if (pos == length)
        {
            insertAtLast(data);
            return;
        }

        Node *p = root;
        cout << "p at:- " << p << endl;

        Node *q = NULL;
        Node *newNode = new Node(data);
        cout << "newNode at:- " << newNode << endl;

        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        cout << "p now at:- " << p << endl;

        newNode->next = p;
        p->prev = newNode;
        newNode->prev = q;
        q->next = newNode;
        length++;
        return;
    }

    void insertAtLast(int data)
    {
        struct Node *newNode = new Node(data);
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        length++;
        return;
    }

    int deleteFirstNode()
    {
        if (root == NULL)
            return -1;
        int deletedData;

        Node *temp = root;
        root = root->next;
        root->prev = NULL;

        deletedData = temp->data;
        delete temp;

        length--;

        return deletedData;
    }

    int deleteLastNode()
    {
        if (last == NULL)
            return -1;
        int deletedData;

        Node *temp = last;
        last = last->prev;
        temp->prev = NULL;
        last->next = NULL;

        deletedData = temp->data;
        delete temp;

        length--;
        return deletedData;
    }

    int deleteAtGivenPos(int pos)
    {
        int deletedData;
        if (pos < 0 || pos > length)
            return -1;

        if (pos == 1)
            return deleteFirstNode();

        if (pos == length)
            return deleteLastNode();

        Node *p = root;
        Node *q = NULL;

        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        p->next->prev = q;
        deletedData = p->data;

        delete p;
        length--;
        return deletedData;
    }

    void reverserDll()
    {
        Node *p = root;
        Node *temp = NULL;
        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;

            if (p!= NULL && p->next == NULL)
            {
                root = p;
            }
        }
    }

    void traverseLinear(struct Node *p)
    {
        while (p)
        {
            cout << p->data << " --> at -: " << p << endl;
            p = p->next;
        }
        return;
    }

    void traverseReverse(struct Node *p)
    {
        while (p)
        {
            cout << p->data << " <--" << endl;
            p = p->prev;
        }
        return;
    }
};

int main()
{
    DoubleLL dll = DoubleLL();
    dll.push(dll.root, 10);
    dll.push(dll.root, 20);
    dll.push(dll.root, 30);

    dll.traverseLinear(dll.root);
    cout << "-------------------------" << endl;

    // dll.traverseReverse(dll.last);
    // cout << "-------------------------" << endl;

    dll.insertAfter(dll.root, 25, 0);
    dll.traverseLinear(dll.root);
    cout << "-------------------------" << endl;

    dll.deleteAtGivenPos(1);
    dll.traverseLinear(dll.root);
    cout << "-------------------------" << endl;

    dll.reverserDll();
    dll.traverseLinear(dll.root);

    return 0;
}