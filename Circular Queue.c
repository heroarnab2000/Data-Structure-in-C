//Name- Arnab Das
//Dept- CSE
//Year- 2nd
//Roll No- 17
//Assignment- 17
//Question- 1
//Date- 28/01/21

#include<stdio.h>
#include<stdlib.h>
#define n 5

struct node
{
	int data;
	struct node* link;
};

int queue[n], ch = 1, front = -1, rear = -1, j = 1, x = n;

struct node* root = NULL;
struct node* tail = NULL;

struct node* enqueueLL(int data)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	
	if(root == NULL)
	{
		root = temp;
		root->link = root;
		tail = root;
	}
	
	else
	{
		tail->link = temp;
		temp->link = root;
		tail = temp;
	}
	
	return root;
}

void enqueue_array()
{
	if((front == rear + 1) || (front == 0 && rear == x - 1))
		printf("\nQueue is Full\n");
            
	else
    {
    	if(front == -1)
    	front = 0;
    	
    	rear = (rear + 1) % x;
        printf("\nEnter an element: ");
        scanf("%d", &queue[rear]);
        
		printf("\nEnqueuing...\n");
    }
    
	return;
}

struct node* dequeueLL()
{
    struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	if(root == NULL)
	{
		printf("\nEmpty Queue!!\nReturning to menu.\n\n");
	}
	
	else if(root->link == root)
	{
		printf("\nDequeing...\n");
		
		root = NULL;
		tail = NULL;
		
		printf("......\nOnly element is deleted.\nReturning to menu.\n\n");
	}
	
	else
	{
	    temp = root;
	    root = root->link;
	    tail->link = root;
	    
		free(temp);
	    
		printf("\nDequeing...\n");
	    printf("......\nFirst element is deleted.\nReturning to menu.\n\n");
    }
    
	return root;
}

void dequeue_array()
{
	if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
    	printf("\nDeleted Element is %d\n", queue[front]);
    	
    	if (front == rear)
		front = rear = -1;
		
		else
		front = (front + 1) % x;
    }
}

void displayLL()
{
	struct node* p;
	p = root;
	
	if(root == NULL)
	printf("Empty Queue!!\nReturning to menu.\n\n");
	
	else
	{
	    printf("\nThe queue is/are: ");
	    
		do
	    {
		    printf("--> %d --", p->data);
		    
			p = p->link;
	    }
	    
	    while(p != root);
	    printf("\n\n");
    }
}

void display_array()
{
	int i;
	
	if(front == -1)
        printf("\nQueue is Empty");
    
	else
    {
    	printf("\nQueue Elements are:\n ");
        for(i = front; i != rear; i = (i + 1) % x)
        {
            printf("%d  ", queue[i]);
        }
        printf("%d", queue[i]);
    }
    
	return;
}

int main ()
{
	int ch, choice;
	
	do
	{
		printf("\n--MAIN MENU--\n1)Build a Circular Queue using Linked List\n2)Build a Circular Queue using Array\n3)Exit\nPlease enter an option: ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				{
					printf("\n\n--Circular Queue using Linked List--\n\n");
		
					do
					{
						printf("\n--MENU--\n1)ENQUEUE (Enter an element)\n2)DEQUEUE (Delete and element)\n3)Display\n4)Exit\nPlease enter an option: ");
						scanf("%d", &choice);
						
						switch(choice)
						{
							case 1:
							{
								int data;
								
								printf("\nEnter an element: ");
								scanf("%d", &data);
								
								printf("\nEnqueuing...\n");
								
								enqueueLL(data);
									
								break;
							}
							case 2:
							{
								dequeueLL();
								
								break;
							}
							case 3:
							{
								displayLL();
								break;
							}
							case 4:
							{
								printf("\nProcess is exited\n");
							    break;	
							}	
							default:
							{
								printf("\nWrong input\nReturning to menu.\n\n");
								break;
							}
						}
				    }
				    while(choice != 4);
				    break;
				}
				
			case 2:
				{
					printf("\n\n--Circular Queue using Array--\n\n");
					printf("MAX Length is 5\n\n");
		
					do
					{
						printf("\n--MENU--\n1)ENQUEUE (Enter an element)\n2)DEQUEUE (Delete and element)\n3)Display\n4)Exit\nPlease enter an option: ");
						scanf("%d", &choice);
						
						switch(choice)
						{
							case 1:
							{
								enqueue_array();
									
								break;
							}
							case 2:
							{
								dequeue_array();
								
								break;
							}
							case 3:
							{
								display_array();
								break;
							}
							case 4:
							{
								printf("\nProcess is exited\n");
							    break;	
							}	
							default:
							{
								printf("\nWrong input\nReturning to menu.\n\n");
								break;
							}
						}
				    }
				    while(choice != 4);
				    break;
				}
				
			case 3:
				{
					printf("\nThankyou!!\nGoodbye!!\n\n");
					break;
				}
			
			default:
				{
					printf("\nWrong input\nReturning to Main Menu.\n\n");
					break;
				}
		}
	}
	while(ch != 3);
	
    return 0;
}
