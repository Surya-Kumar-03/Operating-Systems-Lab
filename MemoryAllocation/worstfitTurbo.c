#include <stdio.h>
void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    // This will store the block id of the allocated block to a process
    int allocation[10];
    int occupied[10];

    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    int i;
    for (i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

    for (i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (i = 0; i < processes; i++)
    {
        int indexPlaced = -1;
        int j;
        for (j = 0; j < blocks; j++)
        {
            // if not occupied and block size is large enough
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;

                // if any future block is larger than the current block where
                // process is placed, change the block and thus indexPlaced
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;

            // make the status of the block as occupied
            occupied[indexPlaced] = 1;
            // Reduce available memory for the block
            blockSize[indexPlaced] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
// Driver code
int main()
{
    int blockSize[5] = {100, 50, 30, 120, 35};
    int processSize[5] = {40, 10, 30, 60};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int processes = sizeof(processSize) / sizeof(processSize[0]);
    clrscr();
    implimentWorstFit(blockSize, blocks, processSize, processes);
    getch();
    return 0;
}