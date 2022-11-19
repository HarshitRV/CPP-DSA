#include <iostream>
#include <stdbool.h>

using namespace std;

class CircularQueue
{
    int front;
    int rear;
    int capacity;
    int *queue;

public:
    CircularQueue(int size)
    {
        front = 0;
        rear = 0;
        capacity = size;
        queue = new int[capacity];
    }

    bool isFull()
    {
        if ((this->rear + 1) % this->capacity == this->front)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (this->front == this->rear)
        {
            return true;
        }
        return false;
    }

    void enqueue(int item)
    {
        if (!isFull())
        {
            this->rear = (this->rear + 1) % this->capacity;
            this->queue[this->rear] = item;
            return;
        }
        cout << "Queue is full" << endl;
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            this->front = (this->front + 1) % this->capacity;
            return this->queue[this->front];
        }
        return -1;
    }

    void traverse()
    {
        if (!isEmpty())
        {
            int i = (front + 1) % this->capacity;
            do
            {
                cout << "--- " << this->queue[i] << " ---" << endl;
                i = (i + 1) % this->capacity;
            } while (i != (this->rear + 1) % this->capacity);

            return;
        }
        cout << "Queue is empty" << endl;
        return;
    }

    void destroy()
    {
        delete[] this->queue;
        cout << "Destroyed queue and exited..." << endl;
        return;
    }

    void instructions()
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Press any other key to exit..." << endl;
        return;
    }
};

int main()
{
    // CircularQueue q = CircularQueue(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // q.enqueue(60);
    // q.traverse();
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    // incrementing size as the queue stores one less element
    // than the actual size.
    size++;

    CircularQueue q = CircularQueue(size);
    q.instructions();

    bool run = true;
    int item;

    while (run)
    {
        int choice;
        cout << "Enter option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter item: ";
            cin >> item;
            q.enqueue(item);
            break;

        case 2:
            item = q.dequeue();
            if (item != -1)
                cout << "\n Deleted item -->" << item << endl;
            else
                cout << "\nQueue empty" << endl;

            break;

        case 3:
            q.traverse();
            break;

        default:
            run = false;
            q.destroy();
        }
    }
    return 0;
}
