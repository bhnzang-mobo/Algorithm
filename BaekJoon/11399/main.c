#include <stdio.h>
#include <malloc.h>

int N;
int arr[1001];
typedef int(*Prioritycomp)(int,int);

void Mergesort(int arr[],int left, int right , Prioritycomp comp){
    if(left<right){
        int mid=(right+left)/2;
        Mergesort(arr,left,mid,comp);
        Mergesort(arr,mid+1,right,comp);

        int * tmparr = (int*)malloc(sizeof(int)*(right-left+1));
        int lhand = left;
        int rhand = mid+1;
        int i = 0;

        while(lhand <= mid && rhand <=right){
            if(comp(arr[lhand],arr[rhand])){
                tmparr[i++]=arr[lhand++];
            }
            else{
                tmparr[i++]=arr[rhand++];
            }
        }

        while(lhand<=mid && i < right-left+1){
            tmparr[i++]=arr[lhand++];
        }
        while(rhand<=right && i < right-left+1){
            tmparr[i++]=arr[rhand++];
        }

        for(int a = 0 ; a < right-left+1 ; a++){
            arr[a+left]=tmparr[a];
        }
    }
}

int comp(int a, int b){
    if(a<b){
        return 1;
    }
    else {
        return 0;
    }
}
int cal(){
    int ret=0;
    int j = N;
    for(int i = 0 ; i < N ; i ++){
        ret+=(j*arr[i]);
        j--;
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&arr[i]);
    }
    Mergesort(arr,0,N-1,comp);
    printf("%d",cal());

    return 0;
}