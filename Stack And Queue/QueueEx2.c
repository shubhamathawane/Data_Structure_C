#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insert();
void Delete();
void Display();
int array[MAX];
int front = -1;
int rear = -1;
int item, i;
int main()
{
    int choice;

    do
    {
        printf("\n1 For insert into the queue");
        printf("\n2 For Delete from the queue");
        printf("\n3 For Display the queue");
        printf("\n4 For exit");
        printf("\nEnter your choice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        default:
            printf("Please enter correct choice : ");
        }
    } while (choice != 4);
}

void insert()
{
    if (front == 4)
    {
        printf("\nQueue is empty !!");
    }
    else
    {
        if (front == -1)
            front = 0;
        {
            printf("\nEnter value to insert in the queue : ");
            scanf("%d", &item);
            rear = rear + 1;
            array[rear] = item;
        }
    }
}

void Delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Deletd queue element is %d\n", array[front]);
        front = front + 1;
    }
}

void Display()
{
    if (front == -1)
    {
        printf("\nnothing to Display");
    }
    else
    {
        int i;
        printf("   Queue elements are : ");
        printf("\n| ============================== |");
        for (i = front; i <= rear; i++)
        {
            printf("\n%d", array[i]);
        }
        printf("\n| ============================== |");
        printf("\n");
    }
}
