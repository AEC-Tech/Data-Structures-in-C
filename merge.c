#include <stdio.h>

int main()
{

    int a[20], b[20], c[50],i,j,k,n,m;
    printf("How many numbers are there in first array:");
    scanf("%d",&n);
    printf("How many numbers are there in second array:");
    scanf("%d",&m);
    printf("Enter numbers for first array in increasing order:");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter numbers for second array in increasing order:");
    for(j=0; j<m; j++)
        scanf("%d",&b[j]);

    i=0;   j=0;    k=0;
    while(i<n && j<m)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    if(i<n)
        for(; i<n; i++,k++)
            c[k]=a[i];
    if(j<m)
        for(; j<m; j++,k++)
            c[k]=b[j];
    printf("Numbers after merging are :");
    for(k=0; k< n+m; k++)
        printf("\n%d",c[k]);
    return 0;
}
