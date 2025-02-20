#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}List;

List *start;

void addatend(int value)
{
    List *temp,*ptr;
    temp = (List*)malloc(sizeof(List));
    temp->data = value;
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next = temp;
    }

}
void display()
{
    List *ptr;
    ptr = start;
    printf("\nList elements are : ");
    while(ptr != NULL)
    {
        printf("\n%d stored at %u",ptr->data,ptr);
        ptr = ptr->next;
    }
}
void search(int num)
{
    List *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->data == num)
        {
            printf("\nFound");
            break;
        }
        else    
            ptr = ptr->next;
    }
    if(ptr == NULL)
        printf("\nNot Found");
}
void addatbeg(int value)
{
    List *temp,*ptr;
    temp = (List*)malloc(sizeof(List));
    temp->data = value;
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        temp->next = start;
        start = temp;
    }

}
void addatpos(int value,int pos)
{
    List *ptr,*temp;
    int i;
    if(pos == 1)
        addatbeg(value);
    else 
    {
        ptr = start;
        for(i = 1; i< pos-1; i++)
        {
            ptr = ptr->next;
            if(ptr == NULL)
            {
                printf("\nInvalid Position");
                return;
            }
        }
        temp = (List*)malloc(sizeof(List));
        temp->data = value;
        temp->next = ptr->next;
        ptr->next  = temp;
    }

    
}
void delfrombeg()
{
    if(start == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        List *ptr;
        ptr = start;
        start = start -> next;
        free(ptr);
    }
}
void delfromend()
{
    if(start == NULL)
    {
        printf("List is Empty");
    }
    else if(start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        List *ptr;
        ptr = start;
        while(ptr->next->next != NULL)
            ptr = ptr -> next;
        free(ptr->next);
        ptr->next = NULL;
    }
}
void sort()
{
    List *p,*q;
    for(p = start; p->next != NULL; p=p->next)
    {
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(p->data > q->data)
            {
                int temp;
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}
int main()
{
    int n,i,num;
    start = NULL;
    do
    {
        
    printf("\nPress 1 - Add at End ");
    printf("\nPress 2 - Add at Beginning ");
    printf("\nPress 3 - Add at Position ");
    printf("\nPress 4 - Display ");
    printf("\nPress 5 - Search ");
    printf("\nPress 6 - Delete From Beginning");
    printf("\nPress 7 - Delete From End");
    printf("\nPress 8 - Delete From Position ");
    printf("\nPress 9 - Sort");
    printf("\nPress 10 - Reverse a Linked List");
    printf("\nPress 11 - Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("\nEnter the number : ");
        scanf("%d",&num);
        addatend(num);
        break;
        case 2:
        printf("\nEnter the number : ");
        scanf("%d",&num);
        addatbeg(num);
        break;
        case 3:
        int pos;
        printf("\nEnter the number : ");
        scanf("%d",&num);
        printf("\nEnter the position to insert : ");
        scanf("%d",&pos);
        addatpos(num,pos);
        break;
        case 4:
        display();
        break;
        case 5:
        printf("\nEnter a number to search : ");
        scanf("%d",&num);
        search(num);
        break;
        case 6:
            delfrombeg();
            break;
        case 7:
            delfromend();
            break;
        case 9:
            sort();
            display();
            break;
    }
}while(n!=11);
    return 0;
}
