// HEAP Sort Program
#include <stdio.h>
void heapify(int[],int);
void reheapify(int[],int);
void heapsort(int[],int);
int main() {
    int n,a[20],i;
    printf("\nHow many numbers are there : ");
    scanf("%d",&n);
    printf("\nEnter the numbers : ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        heapify(a,i);
    }
    printf("\nEntered array is ");
    for(i=1;i<=n;i++)
        printf("\t%d",a[i]);

    heapsort(a,n);
    
    printf("\nSorted array is ");
    for(i=1;i<=n;i++)
        printf("\t%d",a[i]);

    return 0;
}
void heapify(int a[],int pos)
{
    int parent,temp;
    while(pos!=1)
    {
        parent = pos / 2;
        if(a[pos] > a[parent])
        {
            temp = a[pos];
            a[pos] = a[parent];
            a[parent] = temp;
            pos = parent;
        }
        else
            break;
    }
}
void reheapify(int a[],int n)
{
    int parent=1,temp,left,right;
    while(1)
    {
        left = parent * 2;
        right = left + 1;
        if(a[left] > a[parent] && a[right]>a[parent] && left<=n && right<=n)
        {
            if(a[left]>a[right])    
            {
                temp = a[left];
                a[left] = a[parent];
                a[parent] = temp;
                parent = left;
            }
            else
            {
                temp = a[right];
                a[right] = a[parent];
                a[parent] = temp;
                parent = right;
            }
        }
        else if(a[left]> a[parent] && left<=n)
        {
                temp = a[left];
                a[left] = a[parent];
                a[parent] = temp;
                parent = left;
        }
        else if(a[right]> a[parent] && right<=n)
        {
            
                temp = a[right];
                a[right] = a[parent];
                a[parent] = temp;
                parent = right;
            
        }
        else
            break;
        
            
    }
}
void heapsort(int a[],int n)
{
    if(n==1)
        return;
    int temp;
    temp = a[1];
    a[1] = a[n];
    a[n] = temp;
    n = n-1;
    reheapify(a,n);
    heapsort(a,n);
            
}
