
#include <stdio.h>
/*Program to multiply two matrices */
int main()
{

    int a[20][20], b[20][20], c[20][20];
    int i, j, k, n, m, p, q;

    printf("How many rows and columns are there in first matrix :");
    scanf("%d %d",&n,&m);
    printf("How many rows and columns are there in second matrix :");
    scanf("%d %d",&p,&q);
    if(n <=0 || n>20 || m <=0 || m>20)
    {
        printf("Invalid size for first matrix");
        return 0;
    }
    if(p <=0 || p>20 || q <=0 || q>20)
    {
        printf("Invalid size for second matrix");
        return 0;
    }

    printf("Enter the numbers for first matrix : ");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d",&a[i][j]);


    printf("Enter the numbers for second matrix : ");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d",&b[i][j]);

    if(m!=p)
    {
        printf("Multiplication not possible");
        return 0;
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<q; j++)
        {
            c[i][j] = 0;
            for(k=0; k<m; k++)
                c[i][j]+= a[i][k] * b[k][j];
        }
    }

    printf("\nProduct of matrices is \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<q; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
