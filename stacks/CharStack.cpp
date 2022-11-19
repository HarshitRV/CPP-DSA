
#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
    char ch;
    Node *next;

    Node(char c)
    {
        ch = c;
        next = NULL;
    }
};

class CharStack
{
public:
    Node *top;
    CharStack()
    {
        top = NULL;
    }

    void push(char ch)
    {

        Node *temp = new Node(ch);
        if (temp == NULL)
        {
            cout << "Stack is full" << endl;
        }
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return 'e';
        }
        char ch = top->ch;
        top = top->next;
        return ch;
    }

    char peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return 'e';
        }
        return top->ch;
    }

    void traverse()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->ch << endl;
            cout << "---------------" << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    CharStack cs = CharStack();
    string input;
    cout << "Enter expression: ";
    cin >> input;

    int i = 0;
    char ch;
    bool match = true;
    while (i < input.length())
    {
        if (input[i] == '(')
        {
            cs.push(input[i]);
        }
        if (input[i] == ')')
        {
            if (cs.top == NULL)
            {
                match = false;
                break;
            }
            cs.pop();
        }
        i++;
    }

    if (match)
    {
        cout << "Matched paranethesis";
    }
    else
    {
        cout << "NOT Matched paranethesis";
    }

    return 0;
}