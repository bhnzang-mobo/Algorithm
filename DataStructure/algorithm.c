#include "algorithm.h"

int mergesort(mytype arr[], mytype start, mytype end, mytype (*comp)(mytype, mytype))
{
    if (start >= end)  return 0;
    int mid = (start + end) / 2;
    mergesort(arr, start, mid, comp);
    mergesort(arr, mid + 1, end, comp);
    int lhand = start;
    int rhand = mid + 1;
    int tmp_arr[end - start + 1];
    int tmp_idx = 0;

    while (lhand <= mid && rhand <= end)
    {
        if (comp(arr[lhand], arr[rhand]))
        {
            tmp_arr[tmp_idx] = arr[lhand];
            tmp_idx++;
            lhand++;
        }
        else
        {
            tmp_arr[tmp_idx] = arr[rhand];
            tmp_idx++;
            rhand++;
        }
    }

    while (lhand <= mid)
    {
        tmp_arr[tmp_idx] = arr[lhand];
        tmp_idx++;
        lhand++;
    }

    while (rhand <= end)
    {
        tmp_arr[tmp_idx] = arr[rhand];
        tmp_idx++;
        rhand++;
    }
    
    for(int i = start ; i <=end ; i ++){
        arr[i]=tmp_arr[i-start];
    }
    return 0;
}