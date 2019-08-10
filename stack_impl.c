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
    int stack[MAX], top = -1, choice, val;
    do
    {
        printf("Press 1 - Push\nPress 2 - Pop\nPress 3 - Display\nPress 5 - Exit");
        scanf("%d",&choice);
        switch(choice)
        {
       case 1:
        printf("Enter value to be inserted :");
        scanf("%d",&val);
        push(stack,val,&top);
        break;
       case 2:
        val = pop(stack,&top);
        printf("Value removed is %d",val);
        break;
       case 3:
        display(stack,&top);
        break;
        }
    }while(choice != 5);
    return 0;
}
