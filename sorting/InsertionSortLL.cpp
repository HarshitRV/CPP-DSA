#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedListSort
{
public:
    Node *root;
    Node *last;
    int len;

    LinkedListSort()
    {
        root = last = NULL;
        len = 0;
    }

    void firstNode(Node *first)
    {
        root = last = first;
        len++;
        return;
    }
    // Normal append.
    void append(int data)
    {
        Node *temp = new Node(data);
        if (root == NULL)
        {
            firstNode(temp);
            return;
        }

        last = last->next = temp;
        len++;
        return;
    }

    void insertionSort(int arr[])
    {
        int j;
        for (int i = 1; i < len; i++)
        {
            j = i - 1;
            int x = arr[i];
            while (j > -1 && arr[j] > x)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = x;
        }
    }

    // InsertionSort in LL
    void insertSortLL()
    {
        int *arr = new int[len];
        Node *temp = root;

        if (!temp)
            return;

        int i = 0;
        while (temp)
        {
            arr[i++] = temp->data;
            temp = temp->next;
        }

        insertionSort(arr);
    
        // back to square 1
        // repopulating the linked list with
        // sorted array
        Node *temp2 = root;
        for (int i = 0; i < len; i++)
        {
            temp2->data = arr[i];
            temp2 = temp2->next;
        }
        return;
    }

    void traverse()
    {
        Node *temp = root;
        if (!root)
            return;
        while (temp != NULL)
        {
            cout << temp->data << " - ";
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    LinkedListSort LLS = LinkedListSort();
    LLS.append(20);
    LLS.append(10);
    LLS.append(15);
    LLS.append(32);
    LLS.traverse();

    // traverse after sorting
    cout << endl;
    LLS.insertSortLL();
    LLS.traverse();
    return 0;
}