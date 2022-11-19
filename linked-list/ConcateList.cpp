#include <iostream>
#include <stdbool.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *root = NULL;
struct Node *last = NULL;

void createList(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        struct Node *temp = new Node;
        if (root == NULL)
        {
            temp->data = arr[i];
            temp->next = NULL;
            root = last = temp;
        }
        else
        {
            temp->data = arr[i];
            temp->next = NULL;
            last = last->next = temp;
        }
    }
}

void traverse(struct Node *first)
{
    if (first == NULL)
        return;
    cout << first->data << " -->" << endl;
    traverse(first->next);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int len = 5;
    createList(arr, len);
    traverse(root);

    return 0;
}