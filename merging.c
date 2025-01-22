#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int n,int b[], int m, int c[])
{
    int i,j,k;
    i = j = k = 0;
    while( i < n && j < m)
    {
        if( a[i] < b[j] )
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    /* Checking if first list has some unprocessed numbers */
    if( i< n )
    {
        for(;i<n;i++,k++)
        {
            c[k] = a[i];
        }
    }
    else if(j < m) /*in case second list has unprocessed numbers*/
    {
        for(; j<m; j++,k++)
        {
            c[k] = b[j];
        }
    }
}
int main()
{
    int *a,*b,*c,n,m,i;
    printf("\nHow many numbers are there in first array : ");
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int)*n);
    printf("\nEnter the numbers in increasing oreder : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("\nHow many numbers are there in second array : ");
    scanf("%d",&m);
    b = (int*)malloc(sizeof(int)*m);
    printf("\nEnter the numbers in increasing oreder : ");
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    
    c = (int*)malloc(sizeof(int)*(n+m));
    
    merge(a,n,b,m,c);

    printf("\nMerged numbers are : ");
    for(i=0;i<n+m;i++)
    {
        printf("\t %d",c[i]);
    }
    return 0;
}
