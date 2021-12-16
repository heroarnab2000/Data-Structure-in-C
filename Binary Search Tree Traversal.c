#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* NewNode(int data)
{
	struct node *temp =  (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int isEmpty(struct node *root)
{
	if(root == NULL)
	return (1);
	
	return (0);
}

struct node* insert(struct node *root, int data)
{
	if (root->data >= data) 
		root->left = insert(root->left, data); 
	else if (root->data < data)
		root->right = insert(root->right, data);
	
	return root;
}

void inorder(struct node* root)
{
	if (isEmpty(root))
	{
		printf("\nEmpty Binary Tree\n");
		return;
	}
	
	inorder(root->left);
	printf("\t%d\t", root->data);
	inorder(root->right);
	
	return;
}

int main()
{
	struct node *root = NULL;
	int ch;
	do
	{
		printf("-- MENU --");
		printf("\n1. Create a root of the tree with a single element\n2. Insert element\n3. Print the Binary Tree in Inorder\n4. EXIT\n\nPlease enter your choice: ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				{
					if(isEmpty(root))
					{
						int data;
						
						printf("\nEnter an element: ");
						scanf("%d", &data);
						
						root = NewNode(data);
					}
					else
					printf("\nChoose iff the tree is empty. Else try to Insert(2) the element.\n\nReturning to main menu.\n\n");
					
					break;
				}

			case 2:
				{
					if(isEmpty(root))
					printf("\nChoose iff the tree is empty. Else try to Insert(2) the element.\n\nReturning to main menu.\n\n");
										
					else
					{
						int choice, data;
	
						printf("\nEnter an element: ");
						scanf("%d", &data);
						
						insert(root, data);
						
						do
						{
							printf("--MENU--");
							printf("\n1. Enter element\n2. Exit\nPlease enter your choice: ");
							scanf("%d", &choice);
							
							switch (choice)
							{
								case 1:
									{
										printf("\nEnter an element: ");
										scanf("%d", &data);
										
										insert(root, data);
										break;
									}
								
								case 2:
									{
										printf("\nReturning to main menu.\n\n");
										break;
									}
								
								default:
									{
										printf("\nWrong choice!! Returning to menu.");
										break;
									}
							}
						}
						while(ch != 2);
					}
					
					break;
				}
				
			case 3:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					inorder(root);
					
					break;
				}
				
			case 4:
				{
					printf("Thankyou!!\nGoodbye!!");
					break;
				}
			
			default:
				{
					printf("\nWrong choice!! Returning to main menu.");
					break;
				}
		}
	}
	while (ch != 4);
	
	return 0;
}
