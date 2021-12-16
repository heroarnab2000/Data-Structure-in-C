#include<stdio.h>

void insertion_sort(int *a, int n)
{
    int i,j,temp;
    for(i=1;i<=(n-1);i++)
    {
        temp=*(a+i);
        j=i-1;
        while(j>=0 && *(a+j)>temp)
        {
            *(a+(j+1))=*(a+j);
            j=j-1;
        }
        *(a+(j+1))=temp;        
    }
    printf("The sorted arrray is: ");
    for(i=0;i<n;i++)
    printf("%d    ",*(a+i));
     
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    insertion_sort(a, n);
    return 0;
}
