#include <stdio.h>
#include <stdlib.h>

void sort_by_non_increasing(float *a, float *b, int n)
{
	int i, j;
	float temp;
	
	for(i = 0; i < (n-1); i++)
	{
		for(j = 0; j < n-i-1; j++)
	    {
	        if(*(a + j) < *(a + (j + 1)))
	        {
	        	temp = *(a + j);
	        	*(a + j) = *(a + (j + 1));
	            *(a + (j + 1)) = temp;
	            
	            temp = *(b + j);
	        	*(b + j) = *(b + (j + 1));
	            *(b + (j + 1)) = temp;
	        }
	    }
	}
}

void sort_by_non_decreasing(float *a, float *b, int n)
{
	int i, j;
	float temp;
	
	for(i = 0; i < (n-1); i++)
	{
		for(j = 0; j < n-i-1; j++)
	    {
	        if(*(a + j) > *(a + (j + 1)))
	        {
	        	temp = *(a + j);
	        	*(a + j) = *(a + (j + 1));
	            *(a + (j + 1)) = temp;
	            
	            temp = *(b + j);
	        	*(b + j) = *(b + (j + 1));
	            *(b + (j + 1)) = temp;
	        }
	    }
	}
}

void sort_by_non_increasing_strategy3(float *a, float *b, float *c, int n)
{
	int i, j;
	float temp;
	
	for(i = 0; i < (n-1); i++)
	{
		for(j = 0; j < n-i-1; j++)
	    {
	        if(*(a + j) < *(a + (j + 1)))
	        {
	        	temp = *(a + j);
	        	*(a + j) = *(a + (j + 1));
	            *(a + (j + 1)) = temp;
	            
	            temp = *(b + j);
	        	*(b + j) = *(b + (j + 1));
	            *(b + (j + 1)) = temp;
	            
	            temp = *(c + j);
	        	*(c + j) = *(c + (j + 1));
	            *(c + (j + 1)) = temp;
	        }
	    }
	}
}

void strategy1(float *profits, float *weights, int capacity, int n, float *solution_set)
{	
	int i, j, capacity_left = capacity;
	float profit_copy[n], weight_copy[n], profit;

	for (i = 0; i < n; i++)
	{
		*(solution_set + i) = 0.0;
		profit_copy[i] = *(profits + i);
		weight_copy[i] = *(weights + i);
	}
	
	sort_by_non_increasing(profits, weights, n);
	
	for (i = 0; (i < n) && (capacity_left > 0); i++)
	{
		if (*(weights + i) < capacity_left)
		{
			for (j = 0; j < n; j++)
			{
				if (profit_copy[j] == *(profits + i))
				{
					*(solution_set + j) = 1.0;
					capacity_left -= *(weights + i);
					profit += *(profits + i);
				}
			}	
		}
		
		else if(*(weights + i) != capacity_left)
		{			
			for(j = 0; j < n; j++)
			{
				if (profit_copy[j] == *(profits + i))
					{
						*(solution_set + j) = capacity_left / (*(weights + i));
						capacity_left = 0;
						profit += (*(solution_set + j)) * (*(profits + i));
					}
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		*(profits + i) = profit_copy[i];
		*(weights + i) = weight_copy[i];
	}
	
	printf("\nThe total profit is: %f\n", profit);	
}

void strategy2(float *profits, float *weights, int capacity, int n, float *solution_set)
{	
	int i, j, capacity_left = capacity;
	float weight_copy[n], profit_copy[i], profit = 0;

	for (i = 0; i < n; i++)
	{
		*(solution_set + i) = 0.0;
		weight_copy[i] = *(weights + i);
		profit_copy[i] = *(profits + i);
	}
	
	sort_by_non_decreasing(weights, profits, n);
	
	for (i = 0; (i < n) && (capacity_left > 0); i++)
	{
		if (*(weights + i) < capacity_left)
		{
			for (j = 0; j < n; j++)
			{
				if (weight_copy[j] == *(weights + i))
				{
					*(solution_set + j) = 1.0;
					capacity_left -= *(weights + i);
					profit += *(profits + i);
				}
			}	
		}
		
		else if(*(weights + i) != capacity_left)
		{			
			for(j = 0; j < n; j++)
			{
				if (weight_copy[j] == *(weights + i))
				{
					*(solution_set + j) = capacity_left / (*(weights + i));
					capacity_left = 0;
					profit += (*(solution_set + j)) * (*(profits + i));
				}
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		*(profits + i) = profit_copy[i];
		*(weights + i) = weight_copy[i];
	}
	
	printf("\nThe total profit is:  %f\n", profit);
}

void strategy3(float *profits, float *weights, int capacity, int n, float *solution_set)
{	
	int i, j, capacity_left = capacity;
	float weight_copy[n], profit_copy[i], profit_per_weight[n], profit = 0;

	for (i = 0; i < n; i++)
	{
		*(solution_set + i) = 0.0;
		weight_copy[i] = *(weights + i);
		profit_copy[i] = *(profits + i);
		profit_per_weight[i] = profit_copy[i] / weight_copy[i];
	}
	
	sort_by_non_increasing_strategy3(profit_per_weight, weights, profits, n);
	
	for (i = 0; (i < n) && (capacity_left > 0); i++)
	{
		if (*(weights + i) < capacity_left)
		{
			for (j = 0; j < n; j++)
			{
				if (weight_copy[j] == *(weights + i))
				{
					*(solution_set + j) = 1.0;
					capacity_left -= *(weights + i);
					profit += *(profits + i);
				}
			}	
		}
		
		else if(*(weights + i) != capacity_left)
		{			
			for(j = 0; j < n; j++)
			{
				if (weight_copy[j] == *(weights + i))
				{
					*(solution_set + j) = capacity_left / (*(weights + i));
					capacity_left = 0;
					profit += (*(solution_set + j)) * (*(profits + i));
				}
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		*(profits + i) = profit_copy[i];
		*(weights + i) = weight_copy[i];
	}
	
	printf("\nThe total profit is:  %f\n", profit);
}

void main()
{
	int choice, i, j, n, capacity;
	
	do
	{
		printf("\n-- Operations --\n1. Enter the data about the Knapsack and items\n2. Implement Strategy 1 to find Solution set\n3. Implement Strategy 2 to find Solution set\n4. Implement Strategy 3 to find Solution set\n5. Exit\nPlease enter the option:\t");
		scanf("%d", &choice);
		float *weights, *profits, *solution_set;
		
		switch (choice)
		{
			case 1:
				{
					printf("\nEnter the total number of items:\t");
					scanf("%d", &n);
					printf("Enter the capacity of Knapsack (M):\t");
					scanf("%d", &capacity);
					
					weights = (float *)malloc(n * sizeof(float));
					profits = (float *)malloc(n * sizeof(float));
					solution_set = (float *)malloc(n * sizeof(float));
					printf("\n");
					
					for (i = 0; i < n; i++)
					{
						printf("Enter the weight and profit of item %d (seperated by a space):\t", i + 1);
						scanf("%f %f", (weights + i), (profits + i));
					}
					
					break;
				}
			
			case 2:
				{
					printf("\nUsing Strategy 1,");
					strategy1(profits, weights, capacity, n, solution_set);
					
					printf("The solution set is:\t");
					for (i = 0; i < n; i++)
					printf("%f  ", *(solution_set + i));

					printf("\n");
					
					break;
				}
				
			case 3:
				{
					printf("\nUsing Strategy 2,");
					strategy2(profits, weights, capacity, n, solution_set);
					
					printf("The solution set is:\t");
					for (i = 0; i < n; i++)
					printf("%f\t", *(solution_set + i));

					printf("\n");
					
					break;
				}
			case 4:
				{
					printf("\nUsing Strategy 3,");
					strategy3(profits, weights, capacity, n, solution_set);
					
					printf("The solution set is:\t");
					for (i = 0; i < n; i++)
					printf("%f\t", *(solution_set + i));

					printf("\n");
					
					break;
				}
			
			case 5:
				{
					printf("\nThankyou!!\n\n");
					
					break;
				}
				
			default:
				{
					printf("\nWrong Choice!!\n\n");
					
					break;
				}
		}
	} while (choice != 5);
}
