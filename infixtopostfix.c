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
   char infix[30],postfix[30];
   int i,j;
   int data[MAX],top=-1;
   printf("\nEnter the infix expression : ");
   scanf("%s",infix);
   j=0;
   for(i=0;infix[i]!='\0';i++)
   {
       if(infix[i] == '(')
        push(data,&top,infix[i]);
       else if(infix[i]=='+' || infix[i] == '-' || infix[i] == '*'|| infix[i] == '/' )
       {
           if(top == -1 || data[top]=='(')
            push(data,&top,infix[i]);
            
           else if(infix[i] =='*' || infix[i] =='/')
           {
               if(data[top] == '*' || data[top] == '/')
               {
                   postfix[j++] = pop(data,&top);
               }
               push(data,&top,infix[i]);
           }
           else if(infix[i] == '+' || infix[i] =='-')
           {
               while(top != -1 && data[top] !='(')
               {
                   postfix[j++] = pop(data,&top);
               }
               push(data,&top,infix[i]);
           }
       }
       else if(infix[i] == ')')
       {
           while(data[top] != '(')
           {
               postfix[j++] = pop(data,&top);
           }
           pop(data,&top);
       }
       else
       {
           postfix[j++] = infix[i];
       }
   }
   while(top != -1)
    {
        postfix[j++] = pop(data,&top);
    }
    postfix[j] = '\0';
    printf("\n\nPostfix expression is %s",postfix);
    return 0;
}
