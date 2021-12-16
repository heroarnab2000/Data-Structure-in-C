#include <stdio.h>

int row, col;

void getData(int arr[row][col])
{
	int i, j;
	printf("\nEnter the elements of each row with a space in between(eg: a b c d):\n");
	for(i = 0; i < row; i++)
	{
		printf("Enter the elements of row %d\n", i+1);
		for(j = 0; j < col; j++)
		scanf("%d", &arr[i][j]);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
	int j, pivot = a[high], flag = low - 1;
	
	for(j = low; j<=high; j++)
	{
		if(a[j] < pivot)
		{
			flag++;
			swap(&a[flag], &a[j]);
		}
	}
	swap(&a[flag + 1], &a[high]); 
    return (flag + 1);
}

void quick_sort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
		int pivot = partition(a, low, high); 
        quick_sort(a, low, pivot - 1); 
        quick_sort(a, pivot + 1, high); 
    } 
}

void row_sort(int arr[row][col])
{
	int i, j, a[col];
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		a[j] = arr[i][j];

		quick_sort(a, 0, col-1);

		for(j = 0; j < col; j++)
		arr[i][j] = a[j];
	}
}

void column_sort(int arr[row][col])
{
	int i, j, a[col];
	
	for(i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)
		a[j] = arr[j][i];

		quick_sort(a, 0, row-1);
		
		for(j = 0; j < row; j++)
		arr[j][i] = a[j];
	}
}

void display(int arr[row][col])
{
	int i, j;

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		printf("%d  ", arr[i][j]);
		
		printf("\n");
	}
}

int main()
{
	int i, j;
	
	printf("Enter the number of rows:\t");
	scanf("%d", &row);
	printf("Enter the number of columns:\t");
	scanf("%d", &col);
	
	int arr[row][col];
	
	getData(arr);
	
	printf("\nThe given matrix is:\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		printf("%d  ", arr[i][j]);
		
		printf("\n");
	}
	
	row_sort(arr);
	printf("\nThe matrix after Phase 1 row wise sort:\n");
	display(arr);
	column_sort(arr);
	printf("\nThe matrix after Phase 2 column wise sort:\n");
	display(arr);
}
