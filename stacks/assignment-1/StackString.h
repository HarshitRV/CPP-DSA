
#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <iostream>

using namespace std;

class StackString
{
public:
    int top;
    int CAPACITY;
    string *stack;

    StackString() {}

    StackString(int size)
    {
        top = -1;
        CAPACITY = size;
        stack = new string[size];
    };

    bool isStackEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool isStackFull()
    {
        if (top == CAPACITY - 1)
            return true;
        return false;
    }

    void push(string item)
    {
        if (!isStackFull())
        {
            top++;
            stack[top] = item;
            return;
        }
        cout << "Stack overflow" << endl;
    }

    string pop()
    {
        if (!isStackEmpty())
        {
            return stack[top--];
        }
        return "";
    }

    string peek()
    {
        if (!isStackEmpty())
        {
            return stack[top];
        }
        return "";
    }

    void viewItems()
    {
        if (!isStackEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
                cout << "--------------" << endl;
            }
            return;
        }
        cout << "Stack undeflow" <<endl;
    }

    void instruction()
    {
        cout << "1. Push an item" << endl;
        cout << "2. Pop an item" << endl;
        cout << "3. Peek" << endl;
        cout << "4. View items" << endl;
    }
};

