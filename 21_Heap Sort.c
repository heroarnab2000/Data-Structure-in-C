#include<stdio.h>

int temp;  
  
void heapify(int arr[], int size, int i)
{
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
  
	if (left < size && arr[left] >arr[largest])  largest = left;
  
	if (right < size && arr[right] > arr[largest])  largest = right;
  
	if (largest != i)  {  
		temp = arr[i];  
    	arr[i]= arr[largest];   
    	arr[largest] = temp;  
		heapify(arr, size, largest);  
	}
}
  
void heapSort(int arr[], int size) 
{
	int i;  
	
	for (i = size / 2 - 1; i >= 0; i--)  
	heapify(arr, size, i);  
	
	for (i=size-1; i>=0; i--)  {  
		temp = arr[0];  
    	arr[0]= arr[i];   
    	arr[i] = temp;  
		heapify(arr, i, 0);  
	}  
}
  
void main()
{
	int n, i;
	printf("Please enter the size of the array:: ");
	scanf("%d", &n);
	
	int arr[n];  
	
	printf("\nPlease enter %d elements:: ", n);
	
	for(i = 0; i < n; i++)
	scanf ("%d", &arr[i]);
  
	heapSort(arr, n);  
  
	printf("\nThe sorted array is:: ");  
	
	for (i = 0; i < n; i++)
	printf("%d ",arr[i]);
}  
