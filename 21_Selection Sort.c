#include<stdio.h>

void selection_sort(int *a, int n)
{
    int i,j,temp;
    for(i=0;i<(n-1);i++)
    {
        int imin=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+imin))
            imin=j;
        }
        temp=*(a+i);
        *(a+i)=*(a+imin);
        *(a+imin)=temp;
    }
    printf("The sorted arrray is: ");
    for(i=0;i<n;i++)
    printf("%d    ",*(a+i));
     
}

int main()
{
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    selection_sort(a, n);
    return 0;
}
