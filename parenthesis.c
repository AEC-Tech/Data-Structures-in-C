#include <stdio.h>
#define MAX 10
/* Program Stack implementation using array */
void push(int data[],int num, int *top)
{
    if(*top == MAX - 1)
        printf("Stack is full");
    else{
        *top +=1;
        data[*top] = num;
    }
}

int pop(int data[], int *top)
{
    int n=0;
    if(*top==-1)
        printf("Stack is empty");
    else
    {
        n = data[*top];
        *top -= 1;
    }
    return n;
}
void display(int data[], int *top)
{
    if(*top == -1)
        printf("Stack is empty");
    else{
        printf("\nStack is: ");
        for(int i=*top; i>=0; i--)
            printf("%d",data[i]);
    }

}
int main()
{

    char infix[50];
    int data[MAX];
    int i,top=-1;

    printf("Enter the  arithmetic expression:");
    gets(infix);
    for(i=0; infix[i]!='\0'; i++)
    {
        if(infix[i]=='(')
            push(data,infix[i],&top);
        else if(infix[i]==')')
        {
            if(top == -1)
            {
                printf("\nerror : extra right parenthesis");
                return 0;
            }
            else
                pop(data,&top);
        }
    }

    if(top==-1)
        printf("\nparenthesis match perfectly\n ");
    else
        printf("\nerror : extra left parenthesis\n");

    return 0;
}
