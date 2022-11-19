#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5
int stack[CAPACITY];
int top = -1;

bool isFull()
{
    if (top == CAPACITY - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void push(int item)
{
    if (!isFull())
    {
        top++;
        stack[top] = item;
        return;
    }
    printf("Stack is full\n");
}

int pop()
{
    if (!isEmpty())
    {
        int item = stack[top];
        top--;
        return item;
    }
    return -1;
}

int peek()
{
    return stack[top];
}

void traverse()
{
    for (int i = top; i >= 0; i--)
    {
        printf("     %d    \n", stack[i]);
        printf("-----------\n");
    }
}

void instructions()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Traverse\n");
}

int main()
{
    instructions();

    int choice;
    int item;

    bool run = true;

    while (run)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter item to push: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            item = pop();
            if (item != -1)
            {
                printf("%d popped off the stack\n", item);
            }
            else
            {
                printf("Stack is underflow\n");
            }

            break;

        case 3:
            item = peek();
            printf("Top element is %d\n", item);
            break;

        case 4:
            traverse();
            break;

        default:
            run = false;
        }
    }

    return 0;
}