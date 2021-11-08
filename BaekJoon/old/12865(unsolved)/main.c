#include <stdio.h>

int item_val[101];
int item_weight[101];
int dp[101][100001];
int N,W;

void dpCal(){
    for(int i = 1 ; i <= W ; i ++){
        if(i>=item_weight[1]){//weight[i]가 아니다
            dp[1][i]=item_val[1];//val[i]가 아니다
        }
    }

    for(int i = 2 ; i <= N ; i ++){
        for(int j = 1 ; j <= W ; j ++){
            if(j>=item_weight[i]){
                int comp1 = dp[i-1][j];
                int comp2 = dp[i-1][j-item_weight[i]]+item_val[i];
                dp[i][j]=comp1>comp2? comp1 : comp2;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}
int main(){
    scanf("%d %d",&N,&W);
    for(int i = 1 ; i <= N ; i ++){
        scanf("%d %d",&item_weight[i],&item_val[i]);
    }
    dpCal();
    printf("%d",dp[N][W]);

    return 0;
}