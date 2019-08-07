#include <stdio.h>
/*Program Binary Search*/
int main()
{

    int a[10]={2,5,12,25,32,53,56,63,65,78};
    int num,beg=0,end=9,mid;

    printf("Enter number to be searched :");
    scanf("%d",&num);

    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(a[mid]==num)
        {
            printf("\nFound at position %d", mid);
            break;
        }
        else if(num > a[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }

    if(beg > end)
        printf("\nNo. not found");
    return 0;
}
