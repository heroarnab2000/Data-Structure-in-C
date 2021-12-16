//Name-Arnab Das
//Dept-CSE
//Year-2nd
//Roll No- 17
//Assignment-21
//Question-1
//24/02/21

#include <stdio.h>
#include <stdlib.h>

static int count = 0;

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
	if(isEmpty(root))
	{
		return (NewNode(data));
	}
	
	if (root->data > data) 
	root->left = insert(root->left, data); 
	else if (root->data <= data)
	root->right = insert(root->right, data);
	
	return root;
}

int get_min_right(struct node *root)
{
	struct node *temp = root;

    while(temp->left != NULL)
	temp = temp->left;

    return temp->data;
}

struct node* del(struct node *root, int data)
{
	if (isEmpty(root))
	return NULL;
	
	if (root->data < data)
	root->right = del(root->right, data);
	
	else if(root->data > data)
    root->left = del(root->left, data);
    
    else
    {
		if (root->left == NULL && root->right == NULL)
		{
	        free (root);
	        return NULL;
		}
		
		else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free (root);
            return temp;
        }
		
		else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free (root);
            return temp;
        }
        
        else
        {
            int min_right = get_min_right(root->right);
            
			root->data = min_right;
            root->right = del(root->right, min_right);
        }
	}
	
	return root;
}

void inorder(struct node* root)
{
	if(! isEmpty(root))
	{
		inorder(root->left);
		printf("%d   ", root->data);
		inorder(root->right);
	}
	
	return;
}

void preorder(struct node* root)
{
	if(! isEmpty(root))
	{
		printf("%d   ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	
	return;
}

void postorder(struct node* root)
{
	if(! isEmpty(root))
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d   ", root->data);
	}
	
	return;
}

int smallest_node(struct node* root)
{ 
	struct node* current = root; 
	
	while (current->left != NULL)
	current = current->left; 

	return(current->data);
}

int largest_node(struct node* root)
{ 
	struct node* current = root; 
	
	while (current->right != NULL)
	current = current->right; 

	return(current->data);
}

void mirror(struct node* root) 
{
	if (root == NULL)
	return;
	
	struct node* temp; 
	
	mirror(root->left); 
	mirror(root->right); 

	temp = root->left; 
	root->left = root->right; 
	root->right = temp; 
}

int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int count_external_nodes(struct node* root) 
{ 
	if(root == NULL)        
	return 0; 
	
	if(root->left == NULL && root->right==NULL)       
	return 1;             
	
	else 
	return (count_external_nodes(root->left) + count_external_nodes(root->right));
}

int height_of_binary_tree(struct node *root)
{
	if(root == NULL)
	return 0;
	
	else
	{
		int left_side, right_side;
		
		left_side = height_of_binary_tree(root->left);
		right_side = height_of_binary_tree(root->right);
		
		if(left_side > right_side)
		return left_side + 1;
		
		else
		return right_side + 1;
	}
}

void deleteBinaryTree(struct node* root)
{
    deleteBinaryTree(root->left);	
	free(root);
	deleteBinaryTree(root->right);
	free(root);
    return;
}

int main()
{
	struct node *root = NULL;
	int ch;
	do
	{
		printf("\n-- MENU --");
		printf("\n1.  Create a root of the tree with a single element\n2.  Insert element\n3.  Delete an element\n4.  Print the Binary Tree in Inorder\n5.  Print the Binary Tree in Preorder\n6.  Print the Binary Tree in Postorder\n7.  Find the smallest element\n8.  Find the largest element\n9.  Display Mirror image of the tree\n10. Find total number of nodes in the tree\n11. Find number of external nodes in the tree\n12. Find number of internal nodes in the tree\n13. Find height of the tree\n14. Delete the entire tree\n15. EXIT\n\nPlease enter your choice: ");
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
					printf("\nChoose iff the tree is non-empty. Else try to create a root first(1).\n\nReturning to main menu.\n\n");
										
					else
					{
						int choice, data;
	
						printf("\nEnter an element: ");
						scanf("%d", &data);
						
						insert(root, data);
						
						do
						{
							printf("\n--MENU--");
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
						while(choice != 2);
					}
					
					break;
				}
				
			case 3:
				{
					int data;
					printf("Enter the element to be deleted : ");
					scanf("%d", &data);
					printf("\n");
					
					root = del(root, data);
					
					break;
				}
				
			case 4:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						printf("\nInorder Traversal::::\n");
						inorder(root);
					}
					
					break;
				}
				
			case 5:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						printf("\nPreorder Traversal::::\n");
						preorder(root);
					}
					
					break;
				}
				
			case 6:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						printf("\nPostorder Traversal::::\n");
						postorder(root);
					}
					
					break;
				}
			
			case 7:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						int val = smallest_node(root);
						printf("Smallest element:::: %d\n", val);
					}
					
					break;	
				}
				
			case 8:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						int val = largest_node(root);
						printf("Largest element:::: %d\n", val);
					}
					
					break;	
				}
				
			case 9:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						printf("Mirror image of the tree in Inorder:::: \n");
						mirror(root);
						inorder(root);
						printf("\n");
						mirror(root);
					}
					
					break;	
				}
				
			case 10:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					printf("Total number of nodes:::: %d\n", countnodes(root));
					
					break;	
				}
			
			case 11:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					printf("Total number of external nodes:::: %d\n", count_external_nodes(root));
					
					break;	
				}
			
			case 12:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						int internal;
						internal = countnodes(root) - count_external_nodes(root);
						printf("Total number of external nodes:::: %d\n", internal);
					}
					break;	
				}
				
			case 13:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					printf("Height of the tree:::: %d\n", height_of_binary_tree(root));
					
					break;	
				}
				
			case 14:
				{
					if(isEmpty(root))
					printf("\nEmpty Binary Tree\n");
					
					else
					{
						printf("The Binary Search Tree is deleted");
						deleteBinaryTree(root);
					}
					
					break;	
				}
			case 15:
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
	while (ch != 15);
	
	return 0;
}
