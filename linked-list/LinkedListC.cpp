#include <iostream>
#include <stdbool.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedListC
{

public:
    Node *root, *last;
    int length;
    LinkedListC()
    {
        root = NULL;
        last = NULL;
    }

    void insert(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;

        if (root == NULL)
        {
            root = last = temp;
            length++;
            return;
        }

        last = last->next = temp;
        length++;
    }

    void traverse()
    {
        if (root == NULL)
            return;

        Node *temp = root;

        while (temp != NULL)
        {
            cout << temp->data << " --> " << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    LinkedListC linkedList = LinkedListC();

    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);

    linkedList.traverse();

    return 0;
}