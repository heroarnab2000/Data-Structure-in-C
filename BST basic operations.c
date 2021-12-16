#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node* root,int n)
{
	struct node* temp;
	struct node* p;
	struct node* q;
	temp=(struct node* )malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=n;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		p=root;
	    while(p!=NULL)
	    {
	    	q=p;
	    	if(n<=p->data)
	    	{
	    		p=p->left;
			}
			else if(n>p->data)
			{
				p=p->right;
			}
		}
		if(n<=q->data)
		q->left=temp;
		else if(n>q->data)
		q->right=temp;
    }
    return root;
}
struct node* deletion(struct node* root,int n)
{
	int f=0;
	struct node* temp;
	struct node* p1;
	struct node* q;
	temp=(struct node* )malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("BST is empty:\n");
	}
	else
	{
		p1=root;
	    while(p1!=NULL)
	    {
	    	if(n<p1->data)
	    	{
	    		p1=p1->left;
			}
			else if(n>p1->data)
			{
				p1=p1->right;
			}
			else if(n==p1->data)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("deleting element not found\n");
		}
		else if(f==1)
		{
		    if(p1->left==NULL && p1->right==NULL)
			{
			    p1=NULL;
			}			
		}
	}
	return root;
}
void display(struct node* root,int n,struct node* p)
{
	if(n==1)
	{
		if(root==NULL)
		{
			printf("BST is empty\n");
		}
		else if(p!=NULL)
		{
			display(root,n,p->left);
			printf("%d\n",p->data);
			display(root,n,p->right);
		}
	}
	if(n==2)
	{
		if(root==NULL)
		{
			printf("BST is empty\n");
		}
		else if(p!=NULL)
		{
			printf("%d\n",p->data);
			display(root,n,p->left);
			display(root,n,p->right);
		}
	}
	if(n==3)
	{
		if(root==NULL)
		{
			printf("BST is empty\n");
		}
		else if(p!=NULL)
		{
			display(root,n,p->left);
			display(root,n,p->right);
			printf("%d\n",p->data);
		}
	}
}
int main ()
{
	struct node* root=NULL;
	int i;
	do
	{
		printf("enter option:-\n1)insertion in BST\n2)deletion from BST\n3)display\n4)exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				int n;
				printf("enter element to be inserted:\n");
				scanf("%d",&n);
				root=insert(root,n);
				printf("inserting...\n"); 
				break;
			}
			case 2:
			{
			    int n;
				printf("Enter element to be deleted:\n");
				scanf("%d",&n);
				root=deletion(root,n);
				if(root!=NULL)
				printf("deleting...\n");
				break;
			}
			case 3:
			{
				int n;
				struct node* p;
				p=root;
	            printf("enter option:-\n1)inorder\n2)preorder\n3)postorder\n");
	            scanf("%d",&n);
	            if(n==1 && root!=NULL)
	            printf("the inorder BST is:\n");
	            else if(n==2 && root!=NULL)
	            printf("the preorder BST is:\n");
	            else if(n==3 && root!=NULL)
	            printf("the postorder BST is:\n");
				display(root,n,p);
				break;
			}
			case 4:
			{
				printf("process excited...\n");
				break;
			}
			default:
			{
				printf("wrong input\n");
				break;
			}
		}
	}
	while(i!=4);
	return 0;
}
