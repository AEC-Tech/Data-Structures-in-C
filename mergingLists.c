#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}List;



List* addatend(List *start,int value)
{
    List *temp;
    temp = (List*)malloc(sizeof(List));
    temp->data = value;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        List *ptr;
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return start;
}
void display(List *start)
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
void sort(List *start)
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

List* merge(List *p,List *q)
{
    List *newstart=NULL;
    while( p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            newstart = addatend(newstart,p->data);
            p = p->next;
        }
        else
         {
               newstart = addatend(newstart,q->data);
               q=q->next;
         }

    }
    while(p!=NULL)
    {
        newstart = addatend(newstart,p->data);
        p = p->next;
    }
    while(q!=NULL)
    {
        newstart = addatend(newstart,q->data);
        q = q->next;
    }
    return newstart;
}
int main()
{
    int n,m,i,num;
    List *start1,*start2,*result;
    start1 = start2 = NULL;
    printf("\nHow many numbers are there in list 1 :");
    scanf("%d",&n);
    for(i =1; i<=n;i++)
    {
        printf("\nEnter the value : ");
        scanf("%d",&num);
        start1 = addatend(start1,num);
    }
    printf("\nHow many numbers are there in list 2 :");
    scanf("%d",&m);
    for(i =1; i<=m;i++)
    {
        printf("\nEnter the value : ");
        scanf("%d",&num);
        start2 = addatend(start2,num);
    }
    printf("\nList 1 is ");
    display(start1);
    printf("List 2 is ");
    display(start2);
    result = merge(start1,start2);
    printf("\nMerged List is ");
    display(result);
    return 0;
}
