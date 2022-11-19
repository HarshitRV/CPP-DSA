#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

class ArrayQueue
{
    int front;
    int rear;
    int capacity;
    string *queue;

public:
    ArrayQueue(int size)
    {   
        this->front = this->rear = -1;
        this->capacity = size;
        this->queue = new string[size];
    }

    bool isQueueFull()
    {
        if (this->rear == this->capacity - 1)
        {
            return true;
        }
        return false;
    }

    bool isQueueEmpty()
    {
        if (this->rear == this->front)
        {
            return true;
        }
        return false;
    }

    void enqueue(string item)
    {
        if (!isQueueFull())
        {
            this->queue[++this->rear] = item;
            return;
        }
        cout << "Queue is full" << endl;
        return;
    }

    string dequeue()
    {
        if (!isQueueEmpty())
        {
            string deletedItem = this->queue[++this->front];
            return deletedItem;
        }
        return "";
    }

    string firstItem()
    {
        if (!isQueueEmpty())
        {
            int frontIndex = this->front + 1;
            return this->queue[frontIndex];
        }
        return "";
    }

    string lastItem()
    {
        if (!isQueueEmpty())
        {
            return this->queue[this->rear];
        }
        return "";
    }

    void instructions() {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Get first item"<<endl;
        cout<<"4. Get last item"<<endl;
    }
};

int main()
{
    ArrayQueue q = ArrayQueue(5);
    q.instructions();

    bool run = true;
    string item;

    while(run) {
        int choice;
        cout<<"Enter option: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"\nEnter item: ";
                cin>>item;
                q.enqueue(item);
                break;

            case 2:
                item = q.dequeue();
                if(item.length() > 0) 
                    cout<<"\n Deleted item -->"<<item<<endl;
                else    
                    cout<<"\nQueue empty"<<endl;

                break;
            
            case 3:
                item = q.firstItem();
                if(item.length() != 0)
                    cout<<item<<" is at front"<<endl;
                else
                    cout<<"Queue empty"<<endl;
                
                break;

            case 4:
                item = q.lastItem();
                if(item.length() != 0)
                    cout<<item<<" is at last"<<endl;
                else
                    cout<<"Queue empty"<<endl;

                break;
            
            default:
                run = false;
        }
    }
    return 0;
}