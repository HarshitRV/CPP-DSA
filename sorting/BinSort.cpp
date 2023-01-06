#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class List
{
public:
    Node *root;
    Node *last;
    int len;

    List()
    {
        root = last = NULL;
        len = 0;
    }

    void append(int data)
    {
        if (!root)
        {
            root = last = new Node(data);
            len++;
            return;
        }
        last = last->next = new Node(data);
        len++;
        return;
    }
};

void binSort(int arr[], int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    Node **binArr = new Node *[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        binArr[i] = NULL;
    }

    for (int i = 0; i < len; i++)
    {
        Node *temp = new Node(arr[i]);
        if (binArr[arr[i]] == NULL)
        {
            binArr[arr[i]] = temp;
        }
        else
        {
            Node *p = binArr[arr[i]];
            if (p->next)
            {
                Node *q;
                while (p)
                {
                    q = p;
                    p = p->next;
                }
                q->next = temp;
            }
            else
            {
                p->next = temp;
                p = temp;
            }
        }
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (binArr[i])
        {
            Node *p = binArr[i];
            while (p)
            {
                cout << "p->data: " << p->data << endl;
                arr[j++] = p->data;
                p = p->next;
            }
        }
    }
}

int main()
{
    int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};

    binSort(A, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}