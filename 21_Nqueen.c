#include <stdio.h>
#include <stdlib.h>

int n, count = 0;

void display(int board[n])
{
	int i, j;

	printf("\n\nFormation %d:\n\n", ++count); 
	
	printf("Board");
	
	for(i = 0; i < n; i++)
	printf("\t%d",i+1); 
	
	for(i = 0; i < n; i++)
	{
		printf("\n\n%d", i+1);
		
		for(j = 0; j < n; j++)
		{
			if(board[i] == j)
			printf("\tQ");
			
			else
			printf("\t-");
		}
	}
}

int place(int k, int i, int board[n])
{
	int j;
	
	for(j = 0; j <= k-1; j++)
	{
		if(board[j] == i)
		return 0;
		
		else
		{
			if(abs(board[j] - i) == abs(j - k))
			return 0;
		}
	}
	
	return 1;
}

void Nqueen(int k, int board[n])
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if(place(k, i, board))
		{
			board[k] = i;
			
			if(k == n-1)
			display(board);
			
			else
			Nqueen(k+1, board);
		}
	}
}

int main()
{
	printf("Enter the number of rows or columns of the chessboard:\t");
	scanf("%d", &n);
	
	if(n < 4)
	{
		printf("\nThe board should be atleast 4x4 in dimension");
		exit(0);
	}
	
	int board[n];
	
	printf("\nThe Queens can be placed in following formations:\n");
	Nqueen(0, board);
	
	return 0;
}
