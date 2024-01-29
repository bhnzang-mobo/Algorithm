#include <stdio.h>
#include "algorithm.h"

int size;
int arr[9999];

void init()
{
    freopen("C:\\Users\\bhnza\\Desktop\\code_exp\\Algorithm\\DataStructure\\input.txt","r",stdin);
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d ", &(arr[i]));
    }
}

int mycomp(mytype a, mytype b)
{
    return (a <b);
}

int main()
{
    init();
    mergesort(arr, 0, size-1, mycomp);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}