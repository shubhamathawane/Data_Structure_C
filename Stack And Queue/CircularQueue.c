#include <stdio.h>
#define max 6

int queue[max]; //
int front = -1;
int rear = -1;

void insert();
void delete ();
void display();

int main()
{
    int choice = 1, x;
    while (choice < 4 && choice != 0)
    {
        printf("\n Press 1: insert an element");
        printf("\n Press 2: Delete an element");
        printf("\n Press 3: Display an element");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the element to insert : ");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
}

void insert(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
    {
        printf(" Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % max; // rear is increased
        queue[rear] = element;   // assigning the value to deque
    }
}

void delete ()
{
    if ((front == -1) && (rear == -1)) // condition to check queue is empty
    {
        printf("\n Queue is underflow..");
    }
    else if (front == rear)
    {
        printf("\n The deleted element is %d ", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n The deleted element is %d ", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Element in a Queue are : ");
        while (i <= rear)
        {
            printf("\n %d", queue[i]);
            i = (i + 1) % max;
        }
    }
}