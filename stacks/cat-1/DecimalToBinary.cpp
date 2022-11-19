#include <iostream>
#include <cmath>

using namespace std;

class Node
{
public:
    int data;
    int power;
    Node *next;
    Node(int element, int pow)
    {
        data = element;
        power = pow;
        next = NULL;
    }
};

class BinaryStack
{
public:
    Node *top;
    int length;
    BinaryStack()
    {
        top = NULL;
        length = 0;
    }
    void push(int data)
    {
        Node *temp = new Node(data, length++);

        if (temp == NULL)
        {
            cout << "Stack is full" << endl;
            return;
        }

        temp->next = top;
        top = temp;
        return;
    }
    int pop()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }

    void traverse()
    {
        if (top == NULL)
        {
            return;
        }
        Node *temp = top;
        while (temp)
        {
            cout << "------------------" << endl;
            cout << temp->data << " : " << temp->power << endl;
            cout << "------------------" << endl;
            temp = temp->next;
        }
    }

    void convertToBinary()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int convertToDecimal()
    {
        if (top == NULL)
            return -1;

        Node *temp = top;
        int decimal = 0;

        while (temp)
        {
            if (temp->data == 1)
            {
                decimal += pow(2, temp->power);
            }
            temp = temp->next;
        }
        return decimal;
    }
};

int main()
{

    BinaryStack bs = BinaryStack();

    int decimal;
    cout << "Enter decimal value: ";
    cin >> decimal;

    int r, q = decimal;
    while (q > 0)
    {
        r = q % 2;
        bs.push(r);
        q = q / 2;
    }

    cout << decimal << " : ";

    bs.convertToBinary();
    cout << endl;

    int res = bs.convertToDecimal();
    cout << "Back to decimal: " << res;
    cout << endl;

    return 0;
}