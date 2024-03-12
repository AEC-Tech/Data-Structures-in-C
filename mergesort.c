
#include <stdio.h>
#define MAX 20
void merge(int a[],int b1,int e1,int e2)
{
    int i,j,k;
    int c[MAX];
    i=k=b1;
    j=e1+1;
    while(i<=e1 && j<=e2)
    {
        if(a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    if(i<=e1)
        for(;i<=e1;i++,k++)
        c[k]=a[i];
    else
        for(;j<=e2;j++,k++)
        c[k] = a[j];
    for(i = b1;i<=e2;i++)
    a[i]=c[i];
}
void mergesort(int a[],int beg,int end)
{
    if(beg == end)
        return;
    int mid = (beg+end)/2;
    mergesort(a,beg,mid);
    mergesort(a,mid+1,end);
    merge(a,beg,mid,end);
}
int main() {
    int a[] = {7,23,12,45,33,22,19,34,77,27,44};
    printf("\nInitial Array is \n");
    for(int i=0;i<11;i++)
    printf("\t%d",a[i]);
    mergesort(a,0,10);
    printf("\nSorted Array is \n");
    for(int i=0;i<11;i++)
    printf("\t%d",a[i]);
    return 0;
}
