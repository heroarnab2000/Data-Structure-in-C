// Breadth-First-Search for directed graph

#include <stdio.h>
#include <stdlib.h>

int n, adj[20][20], queue[20], visit[20], front=0, rear=-1;

void display() // function to display the graph on depth first basis
{
	int i, j, k = 0;
	
	printf(" \t");
	for(i = 0; i < n; i++)
	{
		printf("V%d\t", i+1);
		printf(" ");
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++)
	{	
		printf("V%d\t", i+1);
		
		for(j = 0; j < n; j++)
		printf("%d\t ", adj[i][j]);
		
		printf("\n");
	}
}

void bfs(int v) // recursive function that traverses the graph in Depth First order
{
	int i;
	
	for (i = 1; i <= n; i++)
	{
		if (adj[v][i] && !visit[i]) // checks if the vertex, we are about to visit is not already visited
		queue[++rear] = i;          // visits the vertex and enters in the queue or further exploration of its connected vertices
	}
	
	if (front <= rear)
	{
		visit[queue[front]] = 1;
		bfs (queue[front++]);      // recursive call of the function
	}
}

int main()
{
	int i, j;
	
	printf("------BFS------\n\n");
	printf("Enter the total number of vertex/ices:\t");
	scanf("%d", &n);
	
	if (n <= 0)
	{
		printf("\nAtleast one vertex should be present");
		exit(0);
	}
	
	else if (n <= 3)
	{
		printf("\nBFS traversal gives:\n");
		
		for (i = 0; i < n; i++)
		printf("V%d --- ", i+1);
		
		exit(0);
	}
	
	printf("\nEnter 1 if the following pair has an edge between then, -1 if in reverse direction and 0 if they don't\n");
	
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (i == j)
			adj[i][j] = 0;
			
			else
			{			
				printf("Between pair V%d ---> V%d:\t", i+1, j+1);
				scanf("%d", &adj[i][j]);
				
				adj[j][i] = (-1) * adj[i][j];
			}
		}
	}
	
	printf("\n\nThe Adjacency matrix is:\n\n");
	display();
	
	bfs(0);
	
	printf("\nThe Output is:\n");
	
	for (i = 1; i <= n; i++)
	{
		if(visit[i])
		printf("V%d ", i);
		
		if(i != n)
		printf("---- ");
	}
	printf("V%d ", i-1);
	
	return 0;
}
