#include <iostream>
#include <stdbool.h>

using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int CAPACITY;
    int *queue;

    Queue(int size)
    {
        front = 0;
        rear = 0;
        CAPACITY = size;
        queue = new int[size];
    }

    bool isQueueFull()
    {
        if (rear == CAPACITY - 1)
            return true;
        return false;
    }

    bool isQueueEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    void insertItem(int item)
    {
        if (!isQueueFull())
        {
            queue[rear] = item;
            rear++;
            return;
        }
        cout << "Queue is full" << endl;
    }

    int deleteItem()
    {
        if (!isQueueEmpty())
        {
            int deletedItem = queue[front];
            for(int i = 0; i < rear; i++) {
                queue[i] = queue[i+1];
            }
            rear--;
            return deletedItem;
        }
        return -1;
    }

    void traverse()
    {
        if (!isQueueEmpty())
        {
            for (int i = 0; i < CAPACITY; i++)
            {
                cout << queue[i] << " | " << endl;
            }
            return;
        }
        cout<<"Queue empty"<<endl;
    }

    void instructions() {
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Traverse"<<endl;
    }
};

int main() {

    return 0;
}