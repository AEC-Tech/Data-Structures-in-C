#include <stdio.h>
/*Program Insertion Sort*/
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
    {
        scanf("%d",&a[i]);
        temp=a[i];
        for(j=i-1; j>=0; j--)
        {
            if(temp > a[j])
            {
                break;
            }
            else
                a[j+1] = a[j];
        }
        a[j+1] = temp;
    }

    printf("\nSorted numbers are : \n ");
    for(i=0; i<n; i++)
        printf("\n%d",a[i]);

    return 0;
}
