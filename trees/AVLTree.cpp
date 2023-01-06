#include <iostream>

using namespace std;

class BinaryNode
{
public:
    BinaryNode *lchild;
    int data;
    int height;
    BinaryNode *rchild;

    BinaryNode(int d, int h)
    {
        lchild = rchild = NULL;
        data = d;
        height = h;
    }
};
class AVLTree
{
public:
    BinaryNode *root;

    AVLTree()
    {
        root = NULL;
    }

    int heightNode(BinaryNode *p)
    {
        int x, y;
        if (p == NULL)
            return 0;
        x = heightNode(p->lchild);
        y = heightNode(p->rchild);
        return x > y ? x + 1 : y + 1;
    }

    int balanceFactor(BinaryNode *p)
    {
        int heightLeftSubtree = heightNode(p->lchild);
        int heightRightSubtree = heightNode(p->rchild);

        return heightLeftSubtree - heightRightSubtree;
    }

    BinaryNode *LLRotation(BinaryNode *p)
    {
        
    }
    BinaryNode *LRRotation(BinaryNode *p)
    {
        
    }
    BinaryNode *RRRotation(BinaryNode *p)
    {
        
    }
    BinaryNode *RLRotation(BinaryNode *p)
    {
        
    }
    

    BinaryNode *insertNode(BinaryNode *p, int data)
    {
        BinaryNode *temp = NULL;
        if (p == NULL)
        {
            temp = new BinaryNode(data, 1);
            if (root == NULL)
                root = temp;

            return temp;
        }
        else if (data > p->data)
        {
            p->lchild = insertNode(p->lchild, data);
        }
        else
        {
            p->rchild = insertNode(p->rchild, data);
        }
        // at returning time we should update the height
        // height should be maximum of left subtree or rightsubtree
        // which ever is higher.
        p->height = heightNode(p);

        // now here we perform rotations
        if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        {
            // perform LL rotation.
            return LLRotation(p);
        }
        else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        {
            // perform LR rotation
            return LRRotation(p);
        }
        else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        {
            return RRRotation(p);
        }
        else
        {
            return RLRotation(p);
        }
        return p;
    }
};

int main()
{
    return 0;
}