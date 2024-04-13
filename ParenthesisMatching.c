#include <stdio.h>
#define MAX 10
void push(int data[],int *top,int value)
{
    if(*top == MAX-1)
        printf("\nOverflow");
    else
    {
        *top += 1;
        data[*top] = value;
    }
}
int pop(int data[],int *top)
{
    if(*top == -1)
    printf("\nUnderflow");
    else
    {
        int val=data[*top];
        *top -= 1;
        return val;
    }
}
int main() {
    int data[MAX];
    int top=-1,i;
    char exp[50];
    printf("Enter the arithmetic expression : ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(')
            push(data,&top,exp[i]);
        else if(exp[i] == ')')
        {
            if(top == -1)
            {
                printf("\nExtra Closing bracket");
                break;
            }
            else
                pop(data,&top);
        }
    }
    if(exp[i]=='\0')
    {
        if(top == -1)
            printf("\nParenthesis Match Perfectly");
        else
            printf("\nExtra Opening Bracket");
    }
    return 0;
}
