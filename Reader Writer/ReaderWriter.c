#include <stdio.h>
#include <conio.h>
void main()
{
    typedef int semaphore;
    semaphore sread = 0, swrite = 0;
    int ch, r = 0;
    printf("\nReader writer");
    do
    {
        printf("\nMenu");
        printf("\n\t 1.Read from file");
        printf("\n \t2.Write to file");
        printf("\n \t 3.Exit the reader");
        printf("\n \t 4.Exit the writer");
        printf("\n \t 5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (swrite == 0)
            {
                sread = 1;
                r += 1;
                printf("\nReader %d reads", r);
            }
            else
            {
                printf("\n Not possible");
            }
            break;
        case 2:
            if (sread == 0 && swrite == 0)
            {
                swrite = 1;
                printf("\nWriter in Progress");
            }
            else if (swrite == 1)
            {
                printf("\nWriter writes the files");
            }
            else if (sread == 1)
            {
                printf("\nCannot write while reader reads the file");
            }
            else
                printf("\nCannot write file");
            break;
        case 3:
            if (r != 0)
            {
                printf("\n The reader %d closes the file", r);
                r -= 1;
            }
            else if (r == 0)
            {
                printf("\n Currently no readers access the file");
                sread = 0;
            }
            else if (r == 1)
            {
                printf("\nOnly 1 reader file");
            }
            else
                printf("%d reader are reading the file\n", r);
            break;
        case 4:
            if (swrite == 1)
            {
                printf("\nWriter close the file");
                swrite = 0;
            }
            else
                printf("\nThere is no writer in the file");
            break;
        case 5:
            return;
        }
    } while (ch < 6);
    scanf("%d", &ch);
}