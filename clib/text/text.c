#include <stdio.h>

void text_output(int n_in)
{
    printf("===> A STATUS MESSAGE <===\n");
    int i;
    for(i=0;i<n_in;i++)
        printf("%d\n", i);
}

// vim: tw=70:ts=4:sts=4:sw=4:et:sta
