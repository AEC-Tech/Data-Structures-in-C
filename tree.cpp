#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

class BSTree
{
	node *root;
	public:
	BSTree()
	{
		root=NULL;
	}	
	void insert(int value)
	{
		node *ptr,*temp;
		temp = new node;
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		if(root == NULL)
			root = temp;
		else
		{
			ptr = root;
			while(ptr != NULL)
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
					cout<<"Duplicate values not allowed"<<endl;
					delete temp;
					break;
				}
				
			}
		}
	}

	void traversal()
	{
		cout<<"Preorder Traversal is "<<endl;
		preorder(root);
		cout<<"Inorder Traversal is "<<endl;
		inorder(root);
		cout<<"Postorder Traversal is "<<endl;
		postorder(root);
	}
	void preorder(node *ptr)
	{
		if(ptr == NULL)
			return;

		cout<<ptr->data<<endl;
		preorder(ptr->left);
		preorder(ptr->right);
	}
	void inorder(node *ptr)
	{
		if(ptr == NULL)
			return;

		inorder(ptr->left);
		cout<<ptr->data<<endl;
		inorder(ptr->right);
	}
	void postorder(node *ptr)
	{
		if(ptr == NULL)
			return;

		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<endl;
	}
};

int main()
{
	BSTree tree;
	int n, i, val;
	cout<<"How many nodes are there in the tree ";
	cin>>n;
	cout<<"Enter the node values : ";
	for(i=1; i<=n; i++)
	{
		cin>>val;
		tree.insert(val);
	}
	cout<<"\nTree Created\n Traversals are \n";
	tree.traversal();
	return 0;
}