#include <stdio.h>

int N;
int arr[1001];
int dparr1[1002];
int dparr2[1002];
void dp1(int * arr,int* dparr){
    for(int i = 1 ; i<=N ; i++){
        int max = 0;
        for(int j = i-1 ; j >=0 ;  j--){
            if(arr[i]>arr[j] && max < dparr[j]+1){
                max=dparr[j]+1;
            }
        }
        dparr[i]=max;
    }
}
void dp2(int * arr,int* dparr){
    for(int i = N ; i>=1 ; i--){
        int max = 0;
        for(int j = i+1 ; j <=N+1 ;  j++){
            if(arr[i]>arr[j] && max < dparr[j]+1){
                max=dparr[j]+1;
            }
        }
        dparr[i]=max;
    }
}
int max(int* dparr){
    int m = 0;
    for(int i = 0 ; i <= N ; i ++){
        if(m<dparr[i]){
            m=dparr[i];
        }
    }
    return m;
}

int main(){
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i ++){
        scanf("%d",&arr[i]);
    }
    dp1(arr,dparr1);
    dp2(arr,dparr2);
    for(int i = 0 ; i < N+1 ; i++){
        dparr1[i]+=dparr2[i];
    }
    printf("%d",max(dparr1)-1);
    return 0;
}