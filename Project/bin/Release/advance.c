#include<stdio.h>
int main()
{
    int i,j,factor=0;
    char str[7]="advance";
    for(j=0;j<=3;j++)
    {
        for (i=0;i<j;i++)
        {
            printf(" ");
        }
        for (i=j;i<=6-j;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    for(j=2;j>=0;j--)
    {
        for (i=0;i<j;i++)
        {
            printf(" ");
        }
        for (i=j;i<=6-j;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;

}
