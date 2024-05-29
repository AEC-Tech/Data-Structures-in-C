// Online C compiler to run C program online
#include <stdio.h>
enum State {Ready,Waiting,Processed};
typedef struct node1
{
    int data;
    struct node1 *next;
}Edge;
typedef struct node2
{
    int data;
    int state;
    struct node2 *next;
    Edge *estart;
}Graph;
Graph *start;
typedef struct node3
{
    Graph *data;
    struct node3 *next;
}Queue;
Queue *front,*rear;
void Enque(Graph *val)
{
    Queue *temp;
    temp=(Queue*)malloc(sizeof(Queue));
    temp->data = val;
    temp->next = NULL;
    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
Graph* Deque()
{
    if(front == NULL)
    return NULL;
    else if(front == rear)
    {
        Graph *p;
        p=front->data;
        free(front);
        front = rear = NULL;
        return p;
    }
    else
    {
        Graph *p;
        p = front->data;
        front= front->next;
        return p;
    }
}
Graph* getAddress(int data)
{
    Graph *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data == data)
            return ptr;
        ptr=ptr->next;
    }
}
void bfs()
{
    Graph *ptr=start;
    while(ptr!=NULL)
    {
        ptr->state = 0;
        ptr=ptr->next;
    }
    Enque(start);
    start->state = 1;
    while(front!=NULL)
    {
        ptr = Deque();
        printf("\n%c",ptr->data);
        ptr->state = 2;
        Edge *q;
        q=ptr->estart;
        while(q!=NULL)
        {
            Graph *temp = getAddress(q->data);
            if(temp->state==0)
            {
                Enque(temp);
                temp->state=1;
            }
            q=q->next;
        }
    }
}

void addedges(Graph *ptr)
{
    int n,i;
    int val;
    Edge *temp,*q;
    printf("\nEnter the number of edges : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the edge value : ");
        scanf("%d",&val);
        temp = (Edge*)malloc(sizeof(Edge));
        temp->data = val;
        temp->next = NULL;
        if(ptr->estart==NULL)
            ptr->estart = temp;
        else
        {
            q = ptr->estart;
            while(q->next!=NULL)
                q = q->next;
            q->next = temp;
        }
    }
    
}
void addnode(int value)
{
    Graph *temp,*ptr;
    temp = (Graph*)malloc(sizeof(Graph));
    temp->data = value;
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    addedges(temp);
}
void display()
{
    Graph *ptr;
    if(start==NULL)
        printf("\nGraph is Empty");
    else
    {
        ptr= start;
        while(ptr!=NULL)
        {
        printf("\n %c -> ",ptr->data);
        if(ptr->estart == NULL)
            printf("  NULL");
        else
        {
         Edge *q;
         q=ptr->estart;
         while(q!=NULL)
         {
             printf("\t%c",q->data);
             q=q->next;
         }
        }
        ptr=ptr->next;
        }
    }
}
int main() {
    start = NULL;
    front = NULL;
    rear = NULL;
    int n,i;
    int data;
    printf("\nHow many Nodes are there : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the Node value : ");
        scanf("%d",&data);
        addnode(data);
    }
    display();
    bfs();
    return 0;
}
