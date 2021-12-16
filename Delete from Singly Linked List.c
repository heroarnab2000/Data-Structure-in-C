//Name-Arnab Das
//Dept-CSE
//Year-2nd
//Roll No- 17
//Assignment-6
//Question-1
//24/9/20

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void append(struct node** root_ptr, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	
	struct node* last = *root_ptr;
	
	if(*root_ptr == NULL)
	{
		*root_ptr = new_node;
		return;
	}
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	return;
}

void delete_at_front(struct node* root_ptr)
{
	if(root_ptr == NULL)
	{
		printf("Underflow!");
		return;
	}
	else
	*root_ptr = *root_ptr->next;
}

void delete_at_end(struct node** root_ptr)
{
	if(*root_ptr == NULL)
	{
		printf("Underflow!");
		return;
	}
	else
	{
		struct node* ptr = *root_ptr;
		while(ptr->next->next != NULL)
		ptr = ptr->next;
		
		ptr->next = NULL;
	}
}

int search(struct node** root_ptr, int key)
{
	if(*root_ptr == NULL)
	{
		printf("Underflow!");
		exit(0);
	}
	else
	{
		int index;
		struct node* ptr = *root_ptr;
		while(ptr->data != key)
		{
			index++;
			ptr = ptr->next;
		}
		
		return (ptr != NULL) ? index: -1;
	}
}

int delete_after(struct node** root_ptr, int key)
{
	if(*root_ptr == NULL)
	{
		printf("Underflow!");
		return 1;
	}
	else
	{
		struct node* ptr = *root_ptr;
		while(ptr->data != key)
		ptr = ptr->next;
		
		if(ptr != NULL)
		{
			ptr->next = ptr->next->next;
			return 0;
		}
		else
		{
			printf("Element not present!");
			return 1;
		}
	}
}

int delete_prev(struct node** root_ptr, int key)
{
	if(*root_ptr == NULL)
	{
		printf("Underflow!");
		return 1;
	}
	else
	{
		struct node* ptr = *root_ptr;
		while(ptr->next->next->data != key)
		ptr = ptr->next;
		
		if(ptr != NULL)
		{
			ptr->next = ptr->next->next;
			return 0;
		}
		else
		{
			printf("Element not present!");
			return 1;
		}
	}
}

void printList(struct node* node)
{
	if(node == NULL)
	{
		printf("Empty!");
	}
	while (node != NULL)
	{
		printf("%d\t", node->data);
    	node = node->next;
	}
}

int main()
{
	int choice, count = 0;
	struct node* root = NULL;
	
	do
	{
		printf("Operations:\n1. Create a linked list(append)\n2. Delete an element at the front\n3. Delete an element at the end\n4. Search for the key element\n5. Delete an element after the key element\n6. Delete an element before the key element\n7. Display the contents of the list\n8. Delete entirely\n9. Exit\n\nEnter your option:\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				count++;
				int new_data;
				printf("\nEnter an element:\n");
				scanf("%d", &new_data);
				
				append(&root, new_data);
				printf("Your element is accepted\n\n");
				break;
			}
			case 2:
			{
				delete_at_front(root);
				printf("\nThe first number is deleted\n\n", count);
				break;
			}
			case 3:
			{
				delete_at_end(&root);
				printf("\nThe last number is deleted\n\n", count);
				break;
			}
			case 4:
			{
				int key;
				printf("\nEnter the element to search:\n");
				scanf("%d", &key);
				int result = search(&root, key);
				if(result == -1)
				printf("\nElement not found!\n\n");
				if(result != -2)
				printf("\nElement found at index: %d\n\n", result);
				break;
			}
			case 5:
			{
				int key;
				printf("\nEnter the key element:\n");
				scanf("%d", &key);
				int result = delete_after(&root, key);
				if(result == 0)
				printf("\nThe element after the key element is deleted\n\n");
				break;
			}
			case 6:
			{
				int key;
				printf("\nEnter the key element:\n");
				scanf("%d", &key);
				int result = delete_prev(&root, key);
				if(result == 0)
				printf("\nThe element before the key element is deleted\n\n");
				break;
			}
			case 7:
			{
				printf("The Linked list is:\n");
				printList(root);
				printf("\n\n");
				break;
			}
			case 8:
			{
				root = NULL;
				break;
			}
		}
	} while(choice != 9);
	return 0;
}
