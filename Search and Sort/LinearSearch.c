#include <stdio.h>
#include <conio.h>

void main()
{
    int list[20], size, i, sElement;

    printf("Enter the size of list : ");
    scanf("%d", &size);

    printf("Enter any %d integer values : ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    printf("Enter the element to be search : ");
    scanf("%d", &sElement);

    // Linear search login
    for (i = 0; i < size; i++)
    {
        if (sElement == list[i])
        {
            printf("Element is founded at [ %d ] index ", i);
            break;
        }
    }
    if (i == size)
    {
        printf("Given element is not found in the list !!! ");
    }
    getch();
}