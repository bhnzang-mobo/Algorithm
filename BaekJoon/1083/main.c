#include <stdio.h>

int A[51];
int N;
int T;
void init(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&T);
}
void swap(int idx,int idx2){
    for(int i = idx ; i >idx2 ; i --){
        int tmp = A[i];
        A[i]=A[i-1];
        A[i-1]=tmp;
    }
}
void cal(){
    int tmpT = T;
    int idx=0;
    while(idx<50 &&tmpT>0){
        int max = idx;
        for(int i = idx ; i <= (N-1<=(idx+tmpT)?N-1:idx+tmpT) ; i++){
            if(A[max]<A[i]){
                max = i;
            }
        }
        if(max!=idx && max-idx<=tmpT){
            tmpT-=max-idx;
            swap(max,idx);
            }
        idx++;
    }
}
int main (){
    init();
    cal();
    for(int i = 0 ; i<N ; i ++){
        printf("%d ",A[i]);
    }
    return 0;
}