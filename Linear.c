#include <stdio.h>
/*Program Linear Search*/
int main()
{

    int a[10]={20,5,25,12,32,56,25,33,65,78};
    int i,num,count=0;

    printf("Enter number to be searched :");
    scanf("%d",&num);

    for(i=0; i<10; i++)
    {
        if(a[i]==num)
        {
            printf("\nFound at %d", i);
            count++;
        }
    }

    if( count == 0)
        printf("\nNo. not found");
    return 0;
}
