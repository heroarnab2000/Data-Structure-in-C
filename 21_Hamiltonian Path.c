#include <stdio.h>
#include <stdlib.h>

int n, count = 0;

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

void show(int adj[n][n], int sol[n])
{
	if(adj[sol[n-1]][0])
	{
		int i;
		printf("\nSolution no. %d : \n", ++count);
		
		for(i = 0; i < n; i++)
		{
			printf("%d ---> ", sol[i]+1);
		}
		
		printf("%d", sol[0]+1);
		
		printf("\n");
		return;
	}
	
	return;
}

void hamil_path(int adj[n][n], int sol[n], int k, int i)
{	
	int j, l;
	
	sol[k] = i;
	
	if(k == n-1)
	{
		show(adj, sol);
	}
	
	else
	{
		for(j = 0; j < n; j++)
		{
			if(adj[i][j])
			{
				for(l = 0; l < k; l++)
				{
					if(sol[l] == j)
					{
						break;
					}
				}
				if(l == k)
				{
					hamil_path(adj, sol, k+1, j);
				}
			}
		}
	}
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
	
	int adj[n][n], sol[n];
	
	for(i = 0; i < n; i++)
	sol[i] = 0;
	
	printf("\nEnter 1 if there is an edge between the pairs and 0 if there isn't:\n");
	
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
	
	hamil_path(adj, sol, 0, 0);
	
	return 0;
}


/*
1
1
0
0
0
1
0
1
0
0
0
0
1
1
0
1
0
0
1
0
0
0
1
0
0
1
0
1
*/

/*
1
1
1
0
0
1
0
0
0
0
1
0
0
1
1
*/
