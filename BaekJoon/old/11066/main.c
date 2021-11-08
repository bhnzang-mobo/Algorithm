#include <stdio.h>
#include <string.h>

int T,K;
int arr[501];
int dparr[501][501];
int sum[501];
int min(int a, int b){
    return (a>b?b:a);
}
int dp(int tx,int ty){
    if(dparr[tx][ty]!=0x3f3f3f3f){
        return dparr[tx][ty];
    }
    if(tx+1 == ty){
         dparr[tx][ty]=arr[tx]+arr[tx+1];
        return dparr[tx][ty];
    }
    if(tx==ty){
        dparr[tx][ty]=0;
        return 0;
    }
    for(int mid =tx ; mid<ty ; mid++){
        int left = dp(tx,mid);
        int right = dp(mid+1,ty);
        dparr[tx][ty]=min(dparr[tx][ty],left+right);
    }
    return dparr[tx][ty]+=(sum[ty]-(tx<=0?0:sum[tx-1]));
}
int main(){
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        memset(dparr,0x3f,sizeof(dparr));
        scanf("%d",&K);
        for(int j = 0 ; j < K ; j ++){
            scanf("%d",&arr[j]);
            sum[j]=arr[j]+(j==0?0:sum[j-1]);
        }
        dp(0,K-1);
        printf("%d\n",dparr[0][K-1]);
    }


   return 0;
}