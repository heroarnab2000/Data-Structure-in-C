//Name-Arnab Das
//Dept-CSE
//Year-2nd
//Roll No- 17
//Assignment-9
//Question-1
//12/11/20

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createDLL(struct node* start, int new_data)
{
	if(start == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = new_data;
		temp->left = NULL;
		temp->right = NULL;
		printf("Your element is accepted.\n\n");
		return temp;
	}
	
	printf("Your element is not accepted!!!!!\n");
	printf("Opt iff there is no present node...\nReturning to main menu!\n\n");
	return start;

}

struct node* insert_at_begining(struct node* start, int new_data)
{
	if(start == NULL)
	{
		printf("Your element is not accepted!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->left = NULL;
	temp->right = start;
	start->left = temp;
	printf("Your element is accepted.\n\n");
	return temp;
}

struct node* insert_at_end(struct node* start, int new_data)
{
	if(start == NULL)
	{
		printf("Your element is not accepted!!!!!\n");
		printf("Opt iff atleast one node is present...\nReturning to main menu!\n\n");
		return start;
	}
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current = start;
	
	while(current->right != NULL)
	current = current->right;
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->left = current;
	temp->right = NULL;
	current->right = temp;
	printf("Your element is accepted.\n\n");
	return start;
}

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
		printf("--->%d", current->data);
	}
}

int main()
{
	int choice;
	struct node* start = NULL;
	
	do
	{
		printf("Operations:\n1. Create a Doubly Linked List\n2. Insert a node at the begining\n3. Insert a node at the end\n4. Display the list\n5. Exit\n\nEnter your option:\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				int new_data;
				printf("\n--Circular linked list is being created--\n");
				printf("Enter an element:\n");
				scanf("%d", &new_data);
				
				start = createDLL(start, new_data);
				break;
			}
			case 2:
			{
				int new_data;
				printf("\nEnter an element:\n");
				scanf("%d", &new_data);
				
				start = insert_at_begining(start, new_data);
				break;
			}
			case 3:
			{
				int new_data;
				printf("\nEnter an element:\n");
				scanf("%d", &new_data);
				
				start = insert_at_end(start, new_data);
				break;
			}
			
			case 4:
			{
				printf("The Linked list is:\n");
				display(start);
				printf("\n\n");
				break;
			}
		}
	} while(choice != 5);
	return 0;
}
