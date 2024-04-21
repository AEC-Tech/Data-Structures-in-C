
#include <stdio.h>
#define MAX 10
void enqueue(int Q[],int *front,int *rear,int value);
void dequeue(int Q[],int *front,int *rear);
void display(int Q[],int front,int rear);

int main() {
    int data[MAX];
    int front =-1, rear = -1, val,n,k;
    do
    {
        printf("\nPress 1 - Insert\nPress 2 - Delete\nPress 3- Display\nPress 4 - Exit");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            printf("\nEnter the value :");
            scanf("%d",&val);
            enqueue(data,&front,&rear,val);
            break;
            case 2:
            dequeue(data,&front,&rear);
            break;
            case 3:
            display(data,front,rear);
            break;
            
        }
    }while(k!=4);
    return 0;
}
void enqueue(int Q[],int *front,int *rear,int value)
{
    if((*front == 0 && *rear == MAX-1) || *front == *rear + 1)
        printf("\nOverflow");
    else if(*front == -1)
    {
        *front = *rear = 0;
        Q[0] = value;
    }
    else
    {
        if (*rear == MAX-1)
            *rear = 0;
        else
            *rear = *rear + 1;
        Q[*rear] = value;
    }
}
void dequeue(int Q[],int *front,int *rear)
{
    if(*front == -1)
        printf("\nUnderflow");
    else if(*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        if(*front == MAX-1)
            *front = 0;
        else
            *front = *front + 1;
    }
    
}
void display(int Q[],int front,int rear)
{
    printf("\nQueue is ");
    if(front <= rear)
    {
        for(int i = front; i<= rear;i++)
            printf("\t%d",Q[i]);
    }
    else
    {
        for(int i = front; i< MAX;i++)
            printf("\t%d",Q[i]);
        for(int i = 0; i<= rear;i++)
            printf("\t%d",Q[i]);
    }
}
