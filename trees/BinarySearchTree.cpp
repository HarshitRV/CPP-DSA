#include <iostream>

using namespace std;

class BinaryNode
{
public:
    BinaryNode *lchild;
    BinaryNode *rchild;
    int data;

    BinaryNode(int d)
    {
        lchild = rchild = NULL;
        data = d;
    }
};

class BinarySearchTree
{
public:
    BinaryNode *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    BinaryNode *addToNode(BinaryNode *p, int data)
    {
        if (!p)
            return NULL;

        BinaryNode *currentNode = p;

        if (data < currentNode->data)
        {
            if (currentNode->lchild)
                return addToNode(currentNode->lchild, data);
            return currentNode;
        }
        else
        {
            if (currentNode->rchild)
                return addToNode(currentNode->rchild, data);
            return currentNode;
        }
    }

    void create(int d)
    {
        if (root == NULL)
        {
            // this is the first node
            root = new BinaryNode(d);
            return;
        }
        BinaryNode *temp = new BinaryNode(d);
        BinaryNode *currentNode = addToNode(root, d);

        // if the data is already there don't do anything
        if (d == currentNode->data)
            return;
        if (d < currentNode->data)
        {
            currentNode->lchild = temp;
            return;
        }
        currentNode->rchild = temp;
        return;
    }

    // recursive insert in binary search
    BinaryNode *recrusiveInsert(BinaryNode *p, int data)
    {
        if (root == NULL)
        {
            root = new BinaryNode(data);
            return NULL;
        }
        if (p == NULL)
        {
            return new BinaryNode(data);
        }
        if (data < p->data)
        {
            p->lchild = recrusiveInsert(p->lchild, data);
        }
        if (data > p->data)
        {
            p->rchild = recrusiveInsert(p->rchild, data);
        }

        return p;
    }

    void preorder(BinaryNode *p)
    {
        if (p)
        {
            cout << p->data << " - ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    BinaryNode *binarySearch(BinaryNode *p, int target)
    {
        if (!p)
            return NULL;
        if (p->data == target)
            return p;
        if (p->data > target)
            return binarySearch(p->lchild, target);
        return binarySearch(p->rchild, target);
    }

    int height(BinaryNode *p)
    {
        int x, y;
        if (p == NULL)
            return 0;
        x = height(p->lchild);
        y = height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }

    BinaryNode *inorderPre(BinaryNode *p)
    {
        while (p && p->rchild != NULL)
            p = p->rchild;
        return p;
    }

    BinaryNode *inorderSucc(BinaryNode *p)
    {
        while (p && p->lchild != NULL)
            p = p->lchild;
        return p;
    }

    BinaryNode *deleteNode(BinaryNode *p, int target)
    {
        BinaryNode *q;
        if (p == NULL)
            return NULL;
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            delete p;
        }

        if (target < p->data)
            p->lchild = deleteNode(p->lchild, target);
        else if (target > p->data)
            p->rchild = deleteNode(p->rchild, target);
        else
        {
            if (height(p->lchild) > height(p->rchild))
            {
                q = inorderPre(p->rchild);
                p->data = q->data;
                p->lchild = deleteNode(p->lchild, q->data);
            }
            else
            {
                q = inorderSucc(p->rchild);
                p->data = q->data;
                p->rchild = deleteNode(p->rchild, q->data);
            }
        }
        return p;
    }
};

int main()
{
    BinarySearchTree bst = BinarySearchTree();

    // this will not be added as it is already present.
    //                       👇
    int arr[] = {30, 15, 50, 50, 20, 40, 60};
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        bst.create(arr[i]);
    }
    bst.preorder(bst.root);

    BinaryNode *foundNode = bst.binarySearch(bst.root, 50);
    if (foundNode)
        cout << "\nfound " << foundNode->data << endl;
    else
        cout << "not found :(" << endl;

    bst.deleteNode(bst.root, 30);
    bst.preorder(bst.root);


    // testing recursive insert in binary search tree.
    BinarySearchTree bst2 = BinarySearchTree();
    int arr[] = {5, 11, 6, 9, 12};
     for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        bst2.recrusiveInsert(bst2.root,arr[i]);
    }
    bst2.preorder(bst.root);
    return 0;
}