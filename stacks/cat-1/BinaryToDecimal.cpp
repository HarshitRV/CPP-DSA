#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class CharNode
{
public:
    char data;
    CharNode *next;
    int power;
    CharNode(char element, int pow)
    {
        data = element;
        next = NULL;
        power = pow;
    }
};
class BinaryCharStack
{
public:
    CharNode *top;
    int power;
    BinaryCharStack()
    {
        top = NULL;
        power = 0;
    }

    void push(char data)
    {
        CharNode *temp = new CharNode(data, power++);

        if (temp == NULL)
        {
            cout << "Stack is full" << endl;
            return;
        }

        temp->next = top;
        top = temp;
        return;
    }
    char pop()
    {
        if (top == NULL)
            return 'e';

        top = top->next;
        return top->data;
    }
    int binaryToDecimal()
    {
        CharNode *temp = top;
        int result = 0;
        while (temp)
        {
            if (temp->data == '1')
            {
                result += pow(2, temp->power);
            }
            temp = temp->next;
        }
        return result;
    }
    void traverse()
    {
        CharNode *temp = top;
        while (temp)
        {
            cout << temp->data << " --pow--> " << temp->power << endl;
            cout << "------" << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    string binary;
    BinaryCharStack ds = BinaryCharStack();

    cout << "Enter binary data: ";
    cin >> binary;

    for (int i = binary.length() - 1; i >= 0; i--)
    {
        ds.push(binary[i]);
    }

    cout<<binary<<" : " << ds.binaryToDecimal();
    cout << endl;
    return 0;
}