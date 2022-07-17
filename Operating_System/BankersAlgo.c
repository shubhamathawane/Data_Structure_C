#include <stdio.h>
#include <conio.h>

int main()
{
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safesequence[10];
    int p, r, i, j, process, count;
    count = 0;

    printf("Enter the No. of processes : ");
    scanf("%d", &p);

    for (i = 0; i < p; i++)
    {
        completed[i] = 0;
    }

    printf("\nEnter the no of resources : ");
    scanf("%d", &r);

    printf("\nEnter the max matrix for each process : ");
    for (i = 0; i < p; i++)
    {
        printf("\nFor Process %d : ", i + 1);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("\nEnter the allocation for each proccess : ");
    for (i = 0; i < p; i++)
    {
        printf("\nFor process %d : ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\nEnter the available resources : ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &avail[i]);

        for (i = 0; i < p; i++)
        {

            for (j = 0; j < p; j++)
            {
                need[i][j] = Max[i][j] - alloc[i][j];
            }
        }
    }
    do
    {
        printf("\nMax matrix : \tAllocation Matrix : \n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < r; j++)
            {
                printf("%d ", Max[i][j]);
            }
            printf("\t\t");
            for (j = 0; j < r; j++)
                printf("%d ", alloc[i][j]);
            printf("\n");
        }
        process = -1;

        for (i = 0; i < p; i++)
        {
            if (completed[i] == 0) // if not completed
            {
                process = i;
                for (j = 0; j < r; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }

        if (process != -1)
        {
            printf("\nProcess %d runs to completion!", process + 1);
            safesequence[count] = process + 1;
            count++;
            for (j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
                completed[process] = 1;
            }
        }
    } while (count != p && process != -1);

    if (count == p)
    {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence : < ");
        for (i = 0; i < p; i++)
            printf("%d  ", safesequence[i]);
        printf(">\n");
    }
    else
        printf("\nThe system is in an unsafe state!!");

    getch();
}
