#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20],n,i,j,temp;
    printf("\nHow many numbers are there : ");
    scanf("%d",&n);

    if(n < 1 || n >20)
    {
        printf("Invalid size, please enter between 1-20");
        return 0;
    }

    printf("\nEnter the numbers ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nNumbers entered are : ");
    for(i=0; i<n; i++)
    {
        printf("\n%d",a[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=0; j< n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nNumbers in sorted order are : ");
    for(i=0; i<n; i++)
    {
        printf("\n%d",a[i]);
    }
    return 0;
}
