#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int(*intComp)(int,int);

void mergesort(int arr[],int left, int right,intComp comp){
    if(left<right){
        int mid=(right+left)/2; //괄호 조심
        mergesort(arr,left,mid,comp);
        mergesort(arr,mid+1,right,comp);

        int lhand=left;
        int rhand=mid+1;
        int *tmparr=(int*)malloc(sizeof(int)*(right-left+1));
        int i=0;

        while(lhand<=mid && rhand<=right){//lhand경계검사를 left로 하는 실수
            if(comp(arr[lhand],arr[rhand])){
                tmparr[i++]=arr[lhand++];
            }
            else{
                tmparr[i++]=arr[rhand++];
            }
        }
        while(lhand<=mid && i < right-left+1){ //lhand경계검사를 left로 하는 실수
            tmparr[i++]=arr[lhand++];
        }
        while(rhand<=right && i < right-left+1){
            tmparr[i++]=arr[rhand++];
        }

        for(int a = 0 ; a < right-left+1 ; a++){
            arr[a+left]=tmparr[a];
        }
        free(tmparr);
    }
}
int comp(int a, int b){
    if(a<=b) return 1;
    else return 0;
}
int arr[1000000];
int main(){
    int N,oper=1;
    scanf("%d",&N);
    int tmp=N;
    for(int i = 0 ; i <N ; i ++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,N-1,comp);

    for(int i = 0 ; i < N ; i ++){
        printf("%d\n",arr[i]);
    }return 0;
}