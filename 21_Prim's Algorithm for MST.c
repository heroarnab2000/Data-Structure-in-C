#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int n, index;

void getVertices(char vertex[n])
{
	int i;
	printf("Please enter all the vertices(seperated by a space):\n");
	for(i = 0; i < n; i++)
	{
		scanf(" ");
		scanf("%c", &vertex[i]);
	}
}

void getEdges(int edge[n][n], char vertex[n])
{
	int i, j;
	printf("\nPlease enter weights of the edges betweeen the following vertices:\n(Enter 0 if there is no edge present between the pair of vertices)\n");
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			printf("For %c<-->%c:\t", vertex[i], vertex[j]);
			scanf("%d", &edge[i][j]);
			
			if (edge[i][j] < 0)
			{
				j--;
				printf("\nPlease enter a valid weight (greater than or equal to 0)\n\n");
			}
		}
		
		for(j = 0; j < i+1; j++)
		{
			if(i == j)
			edge[i][j] = -1;
			
			else
			edge[i][j] = edge[j][i];
		}
	}
}

void display(int edge[n][n], int set[n], char vertex[n])
{
	int i, j, total = 0;
	printf("\nThe tabulated form of the vertices and the corresponding weighted edges are given below:\n\n\t");
	
	for(i = 0; i < n; i++)
	{
		printf("%c\t", vertex[i]);
		printf(" ");
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%c\t", vertex[i]);
		
		for(j = 0; j < n; j++)
		printf("%d\t ", edge[i][j]);
		
		printf("\n");
	}
	
	printf("\n\nThe selected edge and the weight between the vertices is:\n\nEdge \tWeight\n");
	for (int i = 1; i < n; i++)
	{
		printf("%c<-->%c \t%d \n", vertex[set[i]], vertex[i], edge[i][set[i]]);
		total += edge[i][set[i]];
	}
	
	printf("\nThe minimum spanning tree has the total weight of %d units.", total);
}

int find_min(int arr[n], int flag[n])
{
	int min = INT_MAX, i, tape;
	int *temp = (int*) malloc(sizeof(int) * 2);
	
	for(i = index+1; i < n; i++)
	{
		if(arr[i] < min && arr[i] != 0 && flag[i] == 0)
		{
			min = arr[i];
			tape = i;
		}
	}
	
	return tape;
}

void find_min_spanning_tree(int edge[n][n], char vertex[n])
{
	int tape, i, j, flag[n], set[n], min[n];
	
	min[0] = 0;
	flag [0] = 0;
	
	for (int i = 1; i < n; i++)
	{
		min[i] = INT_MAX;
		flag[i] = 0;
	}
	
	set[0] = -1;

	for (i = 0; i < n-1; i++)
	{
		tape = find_min(min, flag);
		
		flag[tape] = 1;
		
		for (j = 0; j < n; j++)
		{
			if (edge[tape][j] > 0 && flag[j] == 0 && edge[tape][j] < min[j])
			set[j] = tape, min[j] = edge[tape][j];
		}
	}
	
	display(edge, set, vertex);
}

int main()
{
	int i, j;
	
	printf("Enter the number of vertices:\t");
	scanf("%d", &n);
	
	char vertex[n];
	int edge[n][n];
	
	getVertices(vertex);
	getEdges(edge, vertex);
	find_min_spanning_tree(edge, vertex);
	
	return 0;
}

/*
2
4
3
0
0
5
2
5
0
3
0
5
6
4
7
*/
