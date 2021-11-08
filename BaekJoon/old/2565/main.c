#include <stdio.h>
#include <malloc.h>
typedef struct pnt{
    int A;
    int B;
}pnt;
typedef int(*Prioritycomp)(pnt,pnt);
pnt arr[101];

void Mergesort(pnt arr[], int left, int right, Prioritycomp comp){
    if(left<right){
        int mid = (right+left)/2;
        Mergesort(arr,left,mid,comp);
        Mergesort(arr,mid+1,right,comp);

        pnt* tmparr = (pnt*)(malloc(sizeof(pnt)*(right-left+1)));
        int lhand = left;
        int rhand = mid+1;
        int i = 0;

        while(lhand <=mid && rhand<=right){
            if(comp(arr[lhand],arr[rhand])){
                tmparr[i++]=arr[lhand++];
            }
            else{
                tmparr[i++]=arr[rhand++];
            }
        }

        while(lhand<=mid && i < right - left + 1){
            tmparr[i++]=arr[lhand++];
        }
        while(rhand<=right && i < right - left + 1){
            tmparr[i++]=arr[rhand++];
        }

        for(int a = 0 ; a< right - left + 1 ; a++){
            arr[a+left]=tmparr[a];
        }
    }
}

int Comp(pnt a, pnt b){
    if(a.A<b.A){
        return 1;
    }
    else{
        return 0;
    }
}
int N;
int dparr[101];
void dp(){
    dparr[0]=1;
    for(int i = 1 ; i < N ; i ++){
        int max = 0;
        for(int j = i-1 ; j >=0 ; j--){
            if(arr[i].B>arr[j].B){
                if(max<dparr[j]){
                    max=dparr[j];
                }
            }
        }
        dparr[i]=max+1;
    }
}

int max(){
    int ret = 0;
    for(int i = 0 ; i < N ; i++){
        if(dparr[i]>ret){
            ret=dparr[i];
        }
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d %d",&arr[i].A,&arr[i].B);
    }
    Mergesort(arr,0,N-1,Comp);
    dp();
    printf("%d",N-max());
    return 0;
}