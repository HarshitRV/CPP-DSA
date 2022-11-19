/**
 * @file LLStack.cpp
 *
 * @details Stack using LinkedList
 */
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string element)
    {
        data = element;
        next = NULL;
    }
};

class LLStack
{
public:
    Node *top;

    LLStack()
    {
        top = NULL;
    }

    void push(string data)
    {
        Node *temp = new Node(data);

        if (temp == NULL)
        {
            cout << "Stack is full" << endl;
            return;
        }
        temp->next = top;
        top = temp;
    }

    string pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return NULL;
        }
        Node *p = top;
        string data = p->data;
        top = p->next;
        return data;
    }

    string peek()
    {
        if (top == NULL)
            return NULL;
        return top->data;
    }

    void traverse()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            cout << "--------" << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    LLStack ls = LLStack();
    ls.push("A");
    ls.push("B");
    ls.push("C");

    ls.traverse();
    string data = ls.peek();
    cout << "Top item -: " << data << endl;
    return 0;
}