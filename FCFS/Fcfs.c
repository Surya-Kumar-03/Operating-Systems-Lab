#include <stdio.h>
#include <conio.h>
void main()
{
    int nop, wt[10], twt, tat[10], ttat, i, j, bt[10], t;
    float awt, atat;
    awt = 0.0;
    atat = 0.0;
    printf("Enter the no.of process:");
    scanf("%d", &nop);
    for (i = 0; i < nop; i++)
    {
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    twt = wt[0];
    ttat = tat[0];
    for (i = 1; i < nop; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        twt += wt[i];
        ttat += tat[i];
    }
    awt = (float)twt / nop;
    atat = (float)ttat / nop;
    printf("\nProcessid\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < nop; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    printf("\nTotal Waiting Time:%d\n", twt);
    printf("\nTotal Around Time:%d\n", ttat);
    printf("\nAverage Waiting Time:%f\n", awt);
    printf("\nAverage Total Around Time:%f\n", atat);
}