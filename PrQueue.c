// Prioriety Queue Using Arrays
#include <stdio.h>
#define MAX 10
int front, rear;
int Q[MAX];
void enqueue(int value);
void dequeue();
void display();

int main() {
    int ch,num;
    front = rear = -1;
    while(1)
    {
        printf("\nPress 1 - Add Prioriety Value : ");
        printf("\nPress 2 - Delete");
        printf("\nPress 3 - Display");
        printf("\nPress 4 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter a  number : ");
            scanf("%d",&num);
            enqueue(num);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            
        }
        if(ch == 4)
        break;
    }
    return 0;
}
void enqueue(int value)
{
    if(front == -1)
    {
        front = rear = 0;
        Q[0] = value;
    }
    else if(rear == MAX -1 )
        printf("\nOverflow- Queue is Full");
    else
    {
        int i = rear;
        while( value <Q[i] && i>=0)
        {
            Q[i+1] = Q[i];
            i = i-1;
        }
        Q[i+1] = value;
        rear = rear + 1;
    }
}
void dequeue()
{
    if(front == -1)
        printf("\nUnderflow-Queue is Empty");
    else
    {
        printf("\nDeleted element is %d",Q[front]);
        if(front == rear)
            front = rear = -1;
        else
        {
            for(int i =0;i<rear;i++)
                Q[i] = Q[i+1];
            rear = rear - 1;
        }
    }
}
void display()
{
    printf("\nQueue is ");
    if(front == -1)
        printf("Empty");
    else
    {
        for(int i =0; i<=rear;i++)
            printf("\t%d",Q[i]);
    }
}
