
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *left,*right;
}BSTree;

BSTree *root;
void add(int);
void preorder(BSTree*);
void inorder(BSTree*);
void postorder(BSTree*);
void search(int);
int main() {
    root=NULL;
    int ch,num;
    while(1)
    {
        printf("\nPress 1 - Add a Node");
        printf("\nPress 2 - Traversal");
        printf("\nPress 3 - Search");
        printf("\nPress 4 - Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the number : ");
            scanf("%d",&num);
            add(num);
            break;
            case 2:
            printf("\nPreorder Traversal : ");
            preorder(root);
            printf("\nInorder Traversal : ");
            inorder(root);
            printf("\nPostorder Traversal : ");
            postorder(root);
            break;
            case 3:
            printf("\nEnter the number to search : ");
            scanf("%d",&num);
            search(num);
            break;
            case 4:
            break;
        }
        if(ch==4)
        break;
    }
    return 0;
}
void add(int value)
{
    BSTree *temp,*ptr;
    temp = (BSTree*)malloc(sizeof(BSTree));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        ptr = root;
        while(ptr!=NULL)
        {
            if(value > ptr->data)
            {
                if(ptr->right == NULL)
                {
                    ptr->right = temp;
                    break;
                }
                else
                    ptr = ptr->right;
                
            }
            else if(value < ptr->data)
            {
                if(ptr->left == NULL)
                {
                    ptr->left = temp;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                printf("\nDuplicate Values Not Allowed");
                free(temp);
                break;
            }
        }
    }
}

void search(int value)
{
    BSTree *ptr,*parent;
    parent = NULL;
    ptr = root;
    while(ptr!=NULL)
    {
        if(ptr->data == value)
        {
            printf("\nFound at ");
            if(parent == NULL)
                printf(" Root");
            else if(value > parent->data)
                    printf(" Right of %d",parent->data);
            else
                    printf(" Left of %d",parent->data);
        
            break;
        }
        else if(value > ptr->data)
        {
            parent = ptr;
            ptr = ptr->right;
        }
        else
        {
            parent = ptr;
            ptr = ptr->left;
        }
    }
    if(ptr == NULL)
        printf("\nNo.Not Found");
}
void preorder(BSTree *ptr)
{
    if(ptr == NULL)
        return;
    printf("\t%d",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void inorder(BSTree *ptr)
{
    if(ptr == NULL)
        return;

    inorder(ptr->left);
    printf("\t%d",ptr->data);
    inorder(ptr->right);
}
void postorder(BSTree *ptr)
{
    if(ptr == NULL)
        return;
    
    postorder(ptr->left);
    postorder(ptr->right);
    printf("\t%d",ptr->data);
}
