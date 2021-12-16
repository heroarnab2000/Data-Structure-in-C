#include <stdio.h>
#include <stdlib.h>

int n, m, temp = 0, count = 0;

void display(int arr[n][n])
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
		printf("%d\t ", arr[i][j]);
		
		printf("\n");
	}
}

int check(int k, int color, int sol[n], int adj[n][n])
{
	int j;
	
	for(j = 0; j < n; j++)
	{
		if(adj[k][j] && sol[j] == color)
		return 0;
	}
	
	return 1;
}

void show(int sol[n], int flag)
{
	int i;
	
	if(flag)
	{
		printf("Solution %d\t", ++count);
		for(i = 0; i < n; i++)
		printf("%d\t", sol[i]);
		
		printf("\n");
	}
	
	else
	{
		printf("Solution 0\t");
		for(i = 0; i < n; i++)
		printf("XX\t", i+1, sol[i]);
		
		printf("\n");
	}
}

int coloring(int adj[n][n], int sol[n], int k)
{
	if(k == n)
	return 1;
	
	int i;
	
	for (i = 1; i <= m; i++)
	{
		if(check(k, i, sol, adj))
		{
			sol[k] = i;
			
			if (k == n-1)
			{
				show(sol, 1);
				temp = 1;
			}
			
			else
			{
				coloring(adj, sol, k+1);
				sol[k+1] = 0;
			}
		}
	}
	
	return temp;
}

int main()
{
	int i, j;
	
	printf("Enter the number of vertices:\t");
	scanf("%d", &n);
	
	if (n <= 0)
	{
		printf("\nAtleast one vertex should be present");
		exit(0);
	}
	
	else if (n <= 2)
	{
		printf("\n\nOnly %d color is required\n", n);		
		exit(0);
	}
	
	int adj[n][n], sol[n];
	
	for(i = 0; i < n; i++)
	sol[i] = 0;
	
	printf("\nEnter 1 if there is an edge between the pairs and 0 if ther isn't:\n");
	
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			if (i == j)
			adj[i][j] = 0;
			
			else
			{			
				printf("Between pair V%d ---> V%d:\t", i+1, j+1);
				scanf("%d", &adj[i][j]);
				
				adj[j][i] = adj[i][j];
			}
		}
	}
	
	printf("\nThe adjancency matrix of the graph is:\n");
	display(adj);
	
	printf("\nEnter the number of colors:\t");
	scanf("%d", &m);	
	
	printf("\nThe color for following vertices are:\n\n");
	printf("          \t");
	
	for(i = 0; i < n; i++)
	printf("V%d\t", i+1);
	printf("\n");
		
	coloring(adj, sol, 0);
	if(temp == 0)
	{
		show(sol, 0);
		printf("\nGiven graph cannot be colored with %d colors", m);
		exit(0);
	}

	return 0;
}
