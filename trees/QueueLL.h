#include <iostream>
#include <stdbool.h>

using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *lchild;
    BinaryTreeNode *rchild;

    BinaryTreeNode() {}

    BinaryTreeNode(int d)
    {
        lchild = rchild = NULL;
        data = d;
    }
};

class Node
{
public:
    BinaryTreeNode *data;
    Node *next;
    Node(BinaryTreeNode *node)
    {
        data = node;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    int size;

    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        return false;
    }

    void enqueue(BinaryTreeNode *node)
    {
        Node *temp = new Node(node);
        if (!temp)
        {
            cout << "queue is full";
            return;
        }
        if (front == NULL)
        {
            front = rear = temp;
            size++;
            return;
        }
        rear = rear->next = temp;
        size++;
    }

    BinaryTreeNode *dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "queue is empty" << endl;
            return NULL;
        }

        Node *temp = front;
        BinaryTreeNode *data = temp->data;
        front = front->next;
        if (front == NULL)
        {
            // this means it is a last node
            // resetting both to NULL
            front = rear = NULL;
        }
        delete temp;
        return data;
    }

    void traverse()
    {
        Node *temp = front;
        while (temp)
        {
            temp = temp->next;
        }
    }
};

// int main()
// {
//     BinaryTreeNode *bn1 = new BinaryTreeNode(10);
//     BinaryTreeNode *bn2 = new BinaryTreeNode(20);
//     BinaryTreeNode *bn3 = new BinaryTreeNode(30);
//     BinaryTreeNode *bn4 = new BinaryTreeNode(40);
//     BinaryTreeNode *bn5 = new BinaryTreeNode(50);
//     Queue q = Queue();
//     q.enqueue(bn1);
//     q.enqueue(bn2);
//     q.enqueue(bn3);
//     q.enqueue(bn4);
//     q.enqueue(bn5);

//     cout << "this should be null: " << q.rear->next << endl;
//     cout << "this should be not be null: " << q.front->next << " -:-20? :- " << q.front->next->data->data << endl;
//     cout << "this should be what i think is: " << q.front->data << " -:- " << q.front->data->data << endl;
//     cout << "rear is what i think is: " << q.rear->data << " -:- " << q.rear->data->data << endl;

//     q.traverse();

//     cout << "dequeue 1 " << q.dequeue() << endl;
//     cout << "1-now front value: " << q.front->data->data << endl;
//     cout << "dequeue 2 " << q.dequeue() << endl;
//     cout << "2-now front value: " << q.front->data->data << endl;
//     cout << "dequeue 3 " << q.dequeue() << endl;
//     cout << "3-now front value: " << q.front->data->data << endl;
//     cout << "dequeue 4 " << q.dequeue() << endl;
//     cout << "4-now front value: " << q.front->data->data << endl;
//     cout << "now front should be null: " << q.front->next << endl;

//     q.traverse();

//     cout << "dequeue " << q.dequeue() << endl;
//     cout << "dequeue " << q.dequeue() << endl;

//     return 0;
// }