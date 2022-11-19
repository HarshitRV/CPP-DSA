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
int length = 0;

void push(int value)
{
    struct Node *temp;
    temp = new Node;

    temp->data = value;
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
        last = temp;
        length++;
        cout << value << " pushed to list, current length: " << length << endl;
        return;
    }

    last = last->next = temp;
    length++;
    cout << value << " pushed to list, current length: " << length << endl;
    return;
}

void unshift(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->next = root;
    root = temp;
    length++;
    cout << item << " inserted at beginning" << endl;
    return;
}

void insertSorted(int data)
{
    struct Node *temp;
    if (root == NULL)
    {
        root = last = temp = new Node;
        temp->data = data;
        temp->next = NULL;
        // cout << "inserting very first item to list" << root ->data <<" -temp-> "<< temp <<" - "<<root -> next <<" -root-> "<< root <<endl;
        // cout << "inserting very first item to list" << root ->data <<" -temp-> "<< temp <<" - "<<root -> next <<" -root-> "<< root <<endl;
        temp = NULL;
        length++;
        return;
    };
    // cout << "creating second item..." << endl;
    struct Node *curr = root, *tail = root;
    // cout << root << root->data << endl;
    temp = new Node;
    temp->data = data;
    temp->next = NULL;
    // cout << "curr-->"<<curr<<" --tail-->"<<tail<<"--root->"<<root<<"-->curr data-->"<<curr->data<<"temp-data-->"<<temp->data<<endl;
    while (curr && temp->data > curr->data)
    {
        // cout << "looping... -> " << temp -> data << "--> " <<curr ->data <<"curr-->"<<curr<<"temp-->"<<temp<<"curr--next-->"<<curr->next<<endl;
        tail = curr;
        curr = curr->next;
        if (curr == NULL)
            cout << "it is null" << endl;

        // cout << "looping... ->temp-data-> " << temp -> data << "-->curr " <<curr<<"--tail--> "<<tail<<endl;
    }

    if (root->next == NULL || tail->next == NULL)
    {
        temp = NULL;
        push(data);
        cout << "since only one node exist in the list, perfoming push" << endl;
        return;
    }

    if (curr == root)
    {
        unshift(data);
        temp = NULL;
        return;
    }
    cout << "inserted in sorted manner" << endl;

    temp->next = tail->next;
    tail->next = temp;
    length++;
    cout << "exiting..." << endl;
    return;
}

void deleteNode(int pos)
{
    // Check if list exists
    if (root == NULL)
        return;

    // Check if pos is valid
    if (pos < 1 || pos > length)
        return;

    // Deleting first node
    if (pos == 1)
    {
        struct Node *temp = root;
        root = root->next;

        cout << "deleted first item -> " << temp->data << endl;
        delete temp;
        length--;

        return;
    }

    int i = 1;
    struct Node *p = root;
    struct Node *q = NULL;

    while (i < pos)
    {
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    cout << "deleted item at pos " << pos << " -> " << p->data << endl;
    delete p;
    length--;
    return;
}

void traverse(struct Node *p)
{
    if (p != NULL)
    {
        cout << "\n--> " << p->data;
        return traverse(p = p->next);
    }
    return;
}

void reverse(struct Node *p)
{
    if (p != NULL)
    {
        reverse(p->next);
        cout << "\n --> " << p->data << endl;
        return;
    }
    return;
}

int countNode(struct Node *p)
{
    if (p != NULL)
    {
        return countNode(p->next) + 1;
    }
    return 0;
}

int getSumElements(struct Node *p)
{
    if (p != NULL)
    {
        return p->data + getSumElements(p->next);
    }
    return 0;
}

int getMax(struct Node *p)
{
    int max;
    if (p != NULL)
    {
        max = p->data;
        while (p->next != NULL)
        {
            if (p->next->data > max)
            {
                max = p->next->data;
            }
            p = p->next;
        }
        return max;
    }
    return -1;
}

struct Node *search(struct Node *p, struct Node *q, int item)
{
    if (p != NULL)
    {
        if (item == p->data)
        {
            q = p;
            p->next = root;
            root = p;
            return p;
        }

        return search(p->next, p, item);
    }
    return NULL;
}

void instructions()
{
    cout << "0. To reprint instructions" << endl;
    cout << "1. Push to list" << endl;
    cout << "2. Traverse" << endl;
    cout << "3. Reverse" << endl;
    cout << "4. Count nodes" << endl;
    cout << "5. Sum of all elements in node" << endl;
    cout << "6. Get max" << endl;
    cout << "7. Search an element" << endl;
    cout << "8. Insert at beginning" << endl;
    cout << "9. Insert sorted item" << endl;
    cout << "10. Delete item from the list" << endl;
    return;
}

int main()
{
    struct Node *node;
    int data;
    int count;
    int sum = 0;
    bool run = true;
    instructions();
    while (run)
    {
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            instructions();
            break;
        case 1:
            cout << "\nEnter data: ";
            cin >> data;
            push(data); // O(1)
            break;

        case 2:
            traverse(root); // O(n)
            break;

        case 3:
            reverse(root); // O(n)
            break;

        case 4:
            count = countNode(root); // O(n)
            cout << "\n Nodes --> " << count << endl;
            break;

        case 5:
            sum = getSumElements(root);
            cout << "\n Sum --> " << sum << endl;
            break;

        case 6:
            data = getMax(root);
            if (data != -1)
            {
                cout << "\n Max element is " << data << endl;
            }
            else
            {
                cout << "\n List is empty " << data << endl;
            }
            break;

        case 7:
            cout << "Enter data to search: ";
            cin >> data;
            node = search(root, NULL, data);
            if (node != NULL)
            {
                cout << "Node address is " << node << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;

        case 8:
            cout << "Enter item: ";
            cin >> data;
            unshift(data);
            break;

        case 9:
            cout << "Enter item: ";
            cin >> data;
            insertSorted(data);
            break;

        case 10:
            cout << "Enter postion of node to delete: ";
            cin >> data;
            deleteNode(data);
            break;

        default:
            run = false;
        }
    }
    return 0;
}