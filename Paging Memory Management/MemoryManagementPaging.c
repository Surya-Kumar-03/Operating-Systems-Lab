#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int size, m, n, pgno, pagetable[3] = {5, 6, 7}, i, j, frameno;
    double m1;
    int ra = 0, ofs;
    printf("enter process size:");
    scanf("%d", &size);
    m1 = size / 4;
    n = ceil(m1);
    printf("total no of pages %d", n);
    printf("\n enter relative address \n:");
    scanf("%d", &ra);
    pgno = ra / 1000;
    ofs = ra % 1000;
    printf("pageno = %d\n", pgno);
    printf("page table");
    for (i = 0; i < n; i++)
        printf("\n %d [%d]", i, pagetable[i]);
    frameno = pagetable[pgno];
    printf("\n equivalent physical address:%d%d", frameno, ofs);
}