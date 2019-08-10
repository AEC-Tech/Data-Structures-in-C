#include <stdio.h>
/*Program Shell Sort*/
int main()
{

    int a[20], i, j, n, temp;

    printf("Enter how many numbers are there :");
    scanf("%d",&n);
    if(n <=0 || n>20)
    {
        printf("Please enter upto 20");
        return 0;
    }

    printf("Enter the numbers : ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(i=n-1; i>=1; i--)
    {
        for(j=0; j<n-i; j++)
        {
            if(a[j] > a[j+i])
            {
                temp = a[j];
                a[j] = a[j+i];
                a[j+i] = temp;
            }
        }
    }

    printf("\nSorted numbers are : \n ");
    for(i=0; i<n; i++)
        printf("\n%d",a[i]);

    return 0;
}
