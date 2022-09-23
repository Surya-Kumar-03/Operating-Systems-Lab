#include <stdio.h>

int count = 0;         // Count is the size of the buffer used
int sizeOfBuffer = 10; // Assuming Size of buffer as 10

void produce()
{
    if (count >= sizeOfBuffer)
    {
        printf("Buffer OverFlow, Producer can't Produce");
        return;
    }
    count++;
    printf("Producer produced Item %d", count);
}

void consume()
{
    if (count == 0)
    {
        printf("Buffer is Empty, Consumer can't Consume");
        return;
    }
    printf("Consumer consumed Item %d", count);
    count--;
}

int main()
{
    int num = 0;
    clrscr();
    printf("If you want to Produce, Press 1 \n If you want to Consume, Press 2 \n To Exit, Press 3: ");
    scanf("%d", &num);
    while (num != 3)
    {
        if (num == 1)
        {
            produce();
        }
        else if (num == 2)
        {
            consume();
        }
        else if (num == 3)
        {
            return 0;
        }
        printf("\nEnter Next Input: ");
        scanf("%d", &num);
    }
    return 0;
}