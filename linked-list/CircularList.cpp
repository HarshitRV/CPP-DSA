#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularList
{
public:
    Node *root, *last;
    int length;
    CircularList()
    {
        root = last = NULL;
        length = 0;
    }

    Node *createNode(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    void push(int data)
    {
        Node *temp = createNode(data);

        if (root == NULL)
        {
            root = last = temp;
            temp->next = root;
            length++;
            return;
        }

        temp->next = root;
        last->next = temp;
        last = temp;
        length++;
        return;
    }

    void traverse()
    {
        if (root == NULL)
            return;

        Node *temp = root;

        do
        {
            cout << temp->data << "--> " << endl;
            temp = temp->next;
        } while (temp != root);
        cout << "Traversed :" << length << " items" << endl;
        return;
    }

    void insertAtBegin(int data)
    {
        if (root == NULL)
        {
            push(data);
            return;
        }

        Node *newNode = createNode(data);
        // Root must be moved in my opinion
        // as if I insert another node or delete before root
        // it will overwrite previous one.
        newNode->next = root;
        root = newNode;
        last->next = root;
        length++;
    }

    void insertAfterGivenPostion(int data, int pos)
    {
        if (root == NULL)
            return;
        if (pos < 0 || pos > length)
            return;
        if (pos == 0)
        {
            insertAtBegin(data);
            return;
        }

        Node *temp = root;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = createNode(data);
        newNode->next = root;
        temp->next = newNode;
        last = newNode;
        length++;
    }

    int deleteFirstNode()
    {
        if (root == NULL)
            return -1;

        Node *temp = root;
        last->next = root->next;
        root = root->next;

        int data = temp->data;
        delete temp;
        length--;

        return data;
    }

    int deleteAtGivenPos(int pos)
    {
        if (root == NULL)
            return -1;
        if (pos < 0 || pos > length)
            return -1;

        Node *p = root;
        Node *q = NULL;
        int data;

        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        data = p->data;

        if (p == last)
            last = q;

        delete p;
        length--;
        return data;
    }

    void traverseRecursively(Node *p)
    {
        static int flag = 0;
        if (p != root || flag == 0)
        {
            cout << p->data << " --> " << endl;
            flag = 1;
            traverseRecursively(p->next);
        }
        flag = 0;
    }
};

int main()
{
    CircularList cl = CircularList();
    cl.push(10);
    cl.push(20);
    cl.push(30);

    cl.traverseRecursively(cl.root);

    cout << " --------------------------------------------" << endl;

    cl.insertAfterGivenPostion(25, 3);
    cl.traverseRecursively(cl.root);

    cout << " --------------------------------------------" << endl;

    cl.insertAtBegin(5);
    cl.traverse();

    cout << " --------------------------------------------" << endl;
    int data = cl.deleteAtGivenPos(2);
    cout << data << " deleted..." << endl;
    cl.traverse();

    cout << " --------------------------------------------" << endl;
    int first = cl.deleteFirstNode();
    cout << first << " deleted..." << endl;
    cl.traverse();

    return 0;
}