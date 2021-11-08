#include <stdio.h>
#include <malloc.h>

typedef struct time{
    int start;
    int end;
}time;
typedef time data;
typedef int(*Prioritycomp)(data,data);

void Mergesort(data arr[],int left,int right, Prioritycomp comp){
    if( left < right ){
        int mid = (right+left)/2;
        Mergesort(arr,left,mid,comp);
        Mergesort(arr,mid+1,right,comp);

        data* tmparr = (data*)(malloc(sizeof(data)*(right-left+1)));
        int lhand = left;
        int rhand = mid+1;
        int i = 0;

        while(lhand<=mid && rhand <=right){
            if(comp(arr[lhand],arr[rhand])){
                tmparr[i++]=arr[lhand++];
            }
            else{
                tmparr[i++]=arr[rhand++];
            }
        }
        while(lhand <= mid && i < right-left+1){
            tmparr[i++]=arr[lhand++];
        }
        while(rhand <= right && i < right-left+1){
            tmparr[i++]=arr[rhand++];
        }

        for(int a = 0 ; a < right-left+1 ; a++){
            arr[a+left]=tmparr[a];
        }
    }
}
int N;
data arr[100001];
int comp(data a, data b){
    if(a.end<b.end){
        return 1;
    }
    else if(a.end==b.end && a.start<b.start){
        return 1;
    }
    else{
        return 0;
    }
}

int cal(){
    int ret = 0;
    int start = 0;
    int idx=-1;
    for(int i = 0; i < N ; i++){
        if(arr[i].start>=start){
            ret++;
            start=arr[i].end;
        }
    }
    return ret;        
}
int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N; i++){
        scanf("%d %d",&arr[i].start,&arr[i].end);
    }
    Mergesort(arr,0,N-1,comp);
    printf("%d",cal());
    return 0;
}