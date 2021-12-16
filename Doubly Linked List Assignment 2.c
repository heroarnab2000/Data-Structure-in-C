//Name-Arnab Das
//Dept-CSE
//Year-2nd
//Roll No- 17
//Assignment-11
//Question-1
//02/12/20
//Done by: 3:48pm

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void display(struct node* start)
{
	if(start == NULL)
	{
		printf("\nEmpty List!!\n");
		printf("Returning to main menu!\n\n");
		return;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	printf("\nThe Doubly Linked List is:\n");
	printf("%d", start->data);
	
	while(current->right != NULL)
	{
		current = current->right;
		printf(" <---> %d", current->data);
	}
	printf("\n\n");
}

struct node* createDLL(struct node* start, int new_data)
{
	if(start == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = new_data;
		temp->left = NULL;
		temp->right = NULL;
		printf("Your element is accepted.\n\n");
		display(temp);
		return temp;
	}
	
	printf("Your element is not accepted!!!!!\n");
	printf("Opt iff there is no present node...\nReturning to main menu!\n\n");
	return start;

}

struct node* insert_at_begining(struct node* start, int new_data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->left = NULL;
	temp->right = start;
	start->left = temp;
	printf("Your element is accepted.\n\n");
	return temp;
}

void insert_at_end(struct node* current, int new_data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->left = current;
	temp->right = NULL;
	current->right = temp;
	printf("Your element is accepted.\n\n");
	return;
}

struct node* insert_after_node(struct node* start, int key, int new_data)
{
	if(start == NULL)
	{
		printf("Your element is not accepted!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	while(current->data != key)
	{
		if(current->data != key && current->right == NULL)
		{
			printf("Given node is not present!!\n");
			printf("Your element is not accepted!!!!!\n");
			printf("Returning to main menu!\n\n");
			return start;
		}
	current = current->right;
	}
	
	display(start);
	
	if(current->data == key && current->right == NULL)
	{
		insert_at_end(current, new_data);
		display(start);
		return start;
	}
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = new_data;
	temp->left = current;
	temp->right = current->right;
	temp->right->left = temp;
	current->right = temp;
	
	printf("Your element is accepted.\n\n");
	
	display(start);
	
	return start;
}

struct node* insert_before_node(struct node* start, int key, int new_data)
{
	if(start == NULL)
	{
		printf("Your element is not accepted!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	if(start->data == key)
	{
		display(start);
		start = insert_at_begining(start, new_data);
		display(start);
		return start;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	while(current->data != key)
	{
		if(current->data != key && current->right == NULL)
		{
			printf("Given node is not present!!\n");
			printf("Your element is not accepted!!!!!\n");
			printf("Returning to main menu!\n\n");
			return start;
		}
		current = current->right;
	}
	
	display(start);
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = new_data;
	temp->right = current;
	temp->left = current->left;
	temp->left->right = temp;
	current->left = temp;
	
	printf("Your element is accepted.\n\n");
	
	display(start);
	
	return start;
}

struct node* delete_first(struct node* start)
{
	if(start == NULL)
	{
		printf("Underflow!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	display(start);
	
	if(start->right == NULL)
	{
		printf("The list is deleted.\n\n");
		printf("\nThe Doubly Linked List is:\nNULL\n");
		free(start);
		return NULL;
	}
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = start;
	start = start->right;
	start->left = NULL;
	free(temp);
	printf("The first element is deleted.\n\n");
	display(start);
	return start;
}

struct node* delete_last(struct node* start)
{
	if(start == NULL)
	{
		printf("Underflow!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	display(start);
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = start;
	
	while(temp->right != NULL)
	temp = temp->right;
	
	if(temp->left == NULL)
	{
		printf("The list is deleted.\n\n");
		printf("\nThe Doubly Linked List is:\nNULL\n");
		free(start);
		return NULL;
	}
	
	temp->left->right = NULL;
	free(temp);
	printf("The last element is deleted.\n\n");
	display(start);
	return start;
}

struct node* delete_after_node(struct node* start, int key)
{
	if(start == NULL)
	{
		printf("Underflow!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	if(start->right == NULL)
	{
		display(start);
		delete_last(start);
		display(start);
		return start;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	while(current->data != key && current->right != NULL)
	{
		if(current->data != key && current->right == NULL)
		{
			printf("Given node is not present!!\n");
			printf("Returning to main menu!\n\n");
			return start;
		}
		current = current->right;
	}
	
	display(start);
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = current->right;
	current->right = temp->right;
	temp->right->left = temp->left;
	free(temp);
	display(start);
	return start;
}

struct node* delete_before_node(struct node* start, int key)
{
	if(start == NULL)
	{
		printf("Underflow!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	if(start->data == key)
	{
		printf("No item before the key!!!!\nReturning to main menu!\n\n");
		return start;
	}
	
	if(start->right->data == key)
	{
		display(start);
		delete_first(start);
		display(start);
		return start;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	while(current->data != key && current->right != NULL)
	{
		if(current->data != key && current->right == NULL)
		{
			printf("Given node is not present!!\n");
			printf("Returning to main menu!\n\n");
			return start;
		}
		current = current->right;
	}
	
	display(start);
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = current->left;
	temp->left->right = temp->right;
	current->left = temp->left;
	free(temp);
	display(start);
	
	return start;
}

int main()
{
	int choice;
	struct node* start = NULL;
	
	do
	{
		printf("Operations:\n1. Create a Doubly Linked List\n2. Insert a node after a given node\n3. Insert a node before a given node\n4. Delete the first node\n5. Delete the last node\n6. Delete the node after a given node\n7. Delete the node before the given node\n8. Display the list\n9. Exit\n\nEnter your option:\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				int new_data;
				printf("\n--Doubly linked list is being created--\n");
				printf("Enter an element:\n");
				scanf("%d", &new_data);
				
				start = createDLL(start, new_data);
				break;
			}
			case 2:
			{
				int new_data, key;
				printf("\nEnter the node after which new element will be inserted:\n");
				scanf("%d", &key);
				printf("\nEnter an element:\n");
				scanf("%d", &new_data);
				
				start = insert_after_node(start, key, new_data);
				break;
			}
			case 3:
			{
				int new_data, key;
				printf("\nEnter the node before which new element will be inserted:\n");
				scanf("%d", &key);
				printf("\nEnter an element:\n");
				scanf("%d", &new_data);
				
				start = insert_before_node(start, key, new_data);
				break;
			}
			case 4:
			{
				start = delete_first(start);
				break;
			}
			case 5:
			{
				start = delete_last(start);
				break;
			}
			case 6:
			{
				int key;
				printf("\nEnter the node after which element will be deleted:\n");
				scanf("%d", &key);			
				start = delete_after_node(start, key);
				break;
			}
			case 7:
			{
				int key;
				printf("\nEnter the node before which element will be deleted:\n");
				scanf("%d", &key);			
				start = delete_before_node(start, key);
				break;
			}
			case 8:
			{
				display(start);
				break;
			}
		}
	} while(choice != 9);
	return 0;
}
