#include <stdio.h>
#include <limits.h>

int n;

void display(int arr[n][n])
{
	int i, j;
	
	printf(" \t");
	for(i = 0; i < n-1; i++)
	{
		printf("A%d\t", i+1);
		printf(" ");
	}
	
	printf("\n");
	
	for(i = 1; i < n; i++)
	{
		printf("A%d\t", i);
		
		for(j = 1; j < n; j++)
		{
			if(j < i)
			{
				printf("X\t");
				printf(" ");
			}
			
			else
			printf("%d\t ", arr[i][j]);
		}
		
		printf("\n");
	}
}

void print_optimal_parenthesis(int s[n][n], int i, int j)
{
	if (i == j)
	printf("A%d ", i);
	
	else
	{
		printf("(");
		print_optimal_parenthesis(s, i, s[i][j]);
		print_optimal_parenthesis(s, s[i][j] + 1, j);
		printf(")");
	}
}

int minimum_scalar_mul(int order[])
{
	int arr[n][n], i, j, index, set, minimum, s[n][n];
	
	for (i = 1; i <= n; i++)
    arr[i][i] = 0;
    
    for(index = 2; index < n; index++)
    {
    	for (i = 1; i < n - index + 1; i++)
        {
            j = i + index - 1;
            arr[i][j] = INT_MAX;
            
            for (set = i; set <= j - 1; set++)
            {
                minimum = arr[i][set] + arr[set+1][j] + order[i-1] * order[set] * order[j];
                
				if (minimum < arr[i][j])
                {
					arr[i][j] = minimum;
					s[i][j] = set;
				}
            }
        }
	}
	
	printf("\nThe matrix with corresponding minimum scalar multiplications is:\n");
	display(arr);
	
	printf("\nThe production rule for minimum number of scalar multiplcation is:\n");
	print_optimal_parenthesis(s, 1, n-1);
	return arr[1][n-1];
}

int main()
{
	int i, result;
	
	printf("Enter the number of matrices:\t");
	scanf("%d", &n);
	
	int order[++n];
	
	printf("\nEnter the dimensions:\n");
	for(i = 0; i < n; i++)
	{
		printf("Enter dimension%d:\t", i+1);
		scanf("%d", &order[i]);
	}
	result = minimum_scalar_mul(order);
	printf("\nAnd the minimum number of scalar multiplications required is:\t%d ", result);
	return 0;
}
