#include<stdio.h>
#include<conio.h>
void main(){
    
    int bt[20], p[20], wt[20], tat[20], i,j,n,total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("\nEnter Burst Time :  \n");
    for(i = 0;i<n;i++){
        printf("P%d : ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
   }
    
    // sorting burst time in ascending order using selection sort
    for(i = 0;i<n;i++){
        pos = i;
        for( j = i;j<n;j++){
            if(bt[j] < bt[pos]){
                pos = j;
            }
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;  // waiting time for first process will be zero

    // Calculating waiting time;
    for(i = 1;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i] += bt[j];
        }

        total += wt[i];
    }


    avg_wt = (float) total/n;
    total = 0;

    printf("\nProcess\t      Burst time \t Waiting Time \tTurnaround Time");
    for(i = 0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\n P%d \t\t %d \t\t %d\t\t %d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float) total/n;
    printf("\n\n Average Waiting time  = %f ", avg_wt);
    printf("\n\n Average Turnaround time  = %f ", avg_tat);



        
}