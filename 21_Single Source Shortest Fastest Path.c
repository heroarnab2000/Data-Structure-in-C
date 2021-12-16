#include <stdio.h>
#include <limits.h>

int n;

void display(int* arr, int row, int col)
{
	int i, j, k = 0;
	
	printf(" \t");
	for(i = 0; i < col; i++)
	{
		printf("V%d\t", i+1);
		printf(" ");
	}
	
	printf("\n");
	
	for(i = 0; i < row; i++)
	{
		if (row == col)
		printf("V%d\t", i+1);
		
		else
		printf("T%d\t", i+1);
		
		for(j = 0; j < col; j++)
		{
			if(*(arr+k) >= 9999999)
			{
				printf("X\t");
				printf(" ");
			}
			
			else
			printf("%d\t ", *(arr+k));
			
			k++;
		}
		
		printf("\n");
	}
}

void calculate(int cost[n][n])
{
	int i, j, k, dist[n-1][n];
	
	for (i = 0; i < n; i++)
	dist[0][i] = cost[0][i];
	
	for (k = 1; k < n-1; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (i == 0)
			dist[k][i] = 0;
			
			else
			{
				int temp = 9999999;
				dist[k][i] = dist[k-1][i];
				
				for (j = 1; j < n; j++)
				{
					if (temp > dist[k-1][j] + cost[j][i] && (dist[k-1][j] != 9999999 || cost[j][i] != 9999999))
					temp = dist[k-1][j] + cost[j][i];
				}
				
				if (temp < dist[k][i])
				dist[k][i] = temp;
			}
		}
	}
	
	printf("\nThe final matrix with all weights/cost from V1 via (Ti) number of vertex/ices is:\n");
	display(&dist[0][0], n-1, n);
}

int main()
{
	int i, j, inp;
	
	printf("Enter the number of vertex/ices:\t");
	scanf("%d", &n);
	
	int cost[n][n];
	
	printf("\nEnter the weight/cost of edge between the pair of vertices\nEnter 0 if no edge is present between the pairs\n\n");
	
	for (i = 0; i < n; i++)
	{		
		for (j = 0; j < n; j++)
		{
			if (i == j || j == 0)
			cost[i][j] = 0;
			
			else
			{
				printf("For V%d ---> V%d:\t", i+1, j+1);
				scanf("%d", &inp);
				
				if (inp == 0)
				cost[i][j] = 9999999;
				
				else
				cost[i][j] = inp;
			}
		}
	}
	
	printf("\nThe given weight/cost matrix:\n");
	display (&cost[0][0], n, n);
	
	calculate(cost);
	return 0;
}
