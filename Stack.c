// Title : Write a program of using C programming language
// Name of coder : Shubham Athawane
// Email: Shubhamathawane02@gmail.com
// Date: 24/12/2021

#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define MAX 5
// this will store maximum 5 number of elements

int top = -1, stack[MAX];
// Here top = -1 because top will always point at n-1 index, means at index 1

void push();        // Creating functions here
void pop();
void display();

void main()
{
    int ch;
    while (1)   // Program will run again and again util while is true (1 = true, 0 = false)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEneter you choice : ");
        scanf("%d", &ch);           // Taking use input 
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nYou have entered Wrong Number choice : ");
        }
    }
}

void push()
{
    int val;
    if (top == MAX - 1)     // Chacking if stack is already fulled  or not
    {
        printf("\nStack is full");
    }
    else        // If not full then we will perform push operation here
    {
        printf("\nEnter elemeents to push : ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)      // checking if stack is already empty or not 
    {
        printf("Stack is already empty");
    }
    else                // If not empty then we will perform pop() operation (deletion)
    {
        printf("\nDeleted elements are : %d ", stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty..");
    }
    else        //Displaying the stack using for loop 
    {
        printf("\nStack is...\n");
        for (i=top;i>= 0; --i)
        {
            printf("%d\n", stack[i]);
        }
    }
}
