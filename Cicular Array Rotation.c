#include <stdio.h>
int main()
{
    int n, turns, query, i, flag;
    scanf("%d %d %d", &n, &turns, &query);
    int arr[n], m;
    flag = turns%n;

    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

    for(i=0;i<query;i++)
    {
        scanf("%d", &m);
        printf("%d\n", arr[(n - flag + m) % n]);
    }   

    return 0;
}

