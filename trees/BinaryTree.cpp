#include <iostream>
#include "QueueLL.h"

using namespace std;

class BinaryTree
{
public:
    BinaryTreeNode *root;
    Queue queue;

    void create()
    {
        BinaryTreeNode *p, *t;
        int data;
        cout << "enter root data: ";
        cin >> data;

        // 1. create a root node
        root = new BinaryTreeNode(data);
        // 2. Insert root node address in queue;
        queue.enqueue(root);

        // 3. Dequeue and ask :-
        p = queue.dequeue();

        while (p != NULL)
        {
            // 3.1 ask data for left child
            cout << "enter data for left child " << p->data << " : ";
            cin >> data;
            if (data != -1)
            {
                t = new BinaryTreeNode(data);
                // 3.1.1 link the parent node to lchild
                p->lchild = t;
                queue.enqueue(t);
            }
            // 3.2 ask data for right child
            cout << "enter data for right child " << p->data << " : ";
            cin >> data;
            if (data != -1)
            {
                t = new BinaryTreeNode(data);
                // 3.2.2 link the parent node to rchild
                p->rchild = t;
                queue.enqueue(t);
            }
            p = queue.dequeue();
        }
        cout << "exit create " << endl;
    }

    void preorder(BinaryTreeNode *p)
    {
        if (p)
        {
            cout << p->data << " - ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }
};

int main()
{
    BinaryTree b = BinaryTree();
    b.create();
    b.preorder(b.root);
    return 0;
}