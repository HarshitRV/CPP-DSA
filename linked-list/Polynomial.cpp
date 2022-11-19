#include <iostream>
using namespace std;
class Node
{
public:
    int coeff;
    Node *next;
    int pow;
    Node(int ele, int pow)
    {
        coeff = ele;
        this->pow = pow;
        next = NULL;
    }
};

void push(Node **head, int coeff, int pow)
{
    Node *new_Node = new Node(coeff, pow);
    Node *temp = *head;
    if (*head == NULL)
    {
        *head = new_Node;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_Node;
}
void display(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    cout << temp->coeff << "x^" << temp->pow << "+";
    display(temp->next);
}
Node *sum(Node *l1, Node *l2)
{
    Node *res = NULL;
    while (l1 && l2)
    {
        if (l1->pow > l2->pow)
        {
            push(&res, l1->coeff, l1->pow);
            l1 = l1->next;
        }

        else if (l1->pow == l2->pow)
        {
            push(&res, l1->coeff + l2->coeff, l1->pow);
            l1 = l1->next;
            l2 = l2->next;
            cout << endl;
        }
        else
        {
            push(&res, l2->coeff, l2->pow);
            l2 = l2->next;
        }
    }
    while (l2)
    {
        push(&res, l2->coeff, l2->pow);
        l2 = l2->next;
    }
    while (l1)
    {
        push(&res, l1->coeff, l1->pow);
        l1 = l1->next;
    }
    return res;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    Node *res = NULL;

    int deg;

    cout << "enter degree of 1st polynomial:";
    cin >> deg;
    while ((deg--) != -1)
    {
        int coeff;
        cout << "Enter coeff of x^" << deg + 1 << ": ";
        cin >> coeff;
        push(&list1, coeff, deg + 1);
    }
    cout << "\n=============================\n";

    cout << "enter degree of 1st polynomial:";
    cin >> deg;
    while ((deg--) != -1)
    {
        int coeff;
        cout << "Enter coeff of x^" << deg + 1 << ": ";
        cin >> coeff;
        push(&list2, coeff, deg + 1);
    }

    res = sum(list1, list2);
    display(res);
}