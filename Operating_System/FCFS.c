#include<stdio.h>
#include<conio.h>

int main(){
    int n, BT[50], WT, TAT, i;
    WT = 0;
    int AWT = 0, AVTAT = 0 , AW = 0, AT = 0;
    printf("Enter the process No. : ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the Burst Time [BT] for Proccess P[%d] : ", i+1);
        scanf("%d", &BT[i]);
    }
    printf("Process \t BT \t WT \t TAT");
    for ( i = 0; i < n; i++)
    {
        TAT = WT+BT[i];
        printf("\n%d \t\t %d \t %d \t %d ", i+1, BT[i],WT, TAT);
        AT = AT + TAT;
        AW = AW + WT;
        WT = WT + BT[i];
    }

    AVTAT = AT/n;
    AWT  = AW/n;

    printf("\nAverage waiting time : %d \naverage turnarround time : %d", AWT, AVTAT);
    return 0;
}