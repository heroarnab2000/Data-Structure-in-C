#include<stdio.h>

void divide_n_conquer(int *A, int i, int j, int *flag)
{
	if (i == j)
	{
		*(flag) = *(A+j);
		*(flag + 1) = *(A+i);
	}
	
	else if (i == j - 1)
	{
		if (*(A + j) > *(A+i))
		{
			*(flag) = *(A+i);
			*(flag + 1) = *(A+j);
		}
		else
		{
			*(flag + 1) = *(A+i);
			*(flag) = *(A+j);
		}
	}
	
	else
	{
		int mid = ( (i + j) / 2 );
		int left[2], right[2];
		
		divide_n_conquer(A, i, mid, left);
		divide_n_conquer(A, mid+1, j, right);

		if (left[0] < right[0])
			*(flag) = left[0];
			
		else
			*(flag) = right[0];

		if (left[1] > right[1])
			*(flag + 1) = left[1];
		
		else
			*(flag + 1) = right[1];
	}
}
void max_min_find(int *A, int n)
{
	int ans[2];
	divide_n_conquer(A, 0, n-1, ans);
	printf("\nThe maximum value is: %d", ans[1]);
	printf("\nThe minimum value is: %d\n", ans[0]);
}

int main()
{
	int n;
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	int A[n];
	
	printf("\nEnter %d elements: ", n);
	
	for(int i = 0; i < n; i++)
	scanf("%d", &A[i]);
	
	max_min_find(A, n);
}
