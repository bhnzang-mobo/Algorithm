#include <stdio.h>
#include <string.h>
#include <math.h>
int N,M;
int mem[101];
int cost[101];
int dparr[2][10001];
void read(){
    scanf("%d %d",&N,&M);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&mem[i]);
    }
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&cost[i]);
    }
}

int dp(){//return value = 
    for(int i = 0 ; i < 10001 ; i ++){
        if(i>=cost[0]){
            dparr[0][i]+=mem[0];
        }
    }
    for(int i = 1 ; i < N ; i ++){
        for(int j = 0 ; j < 10001 ; j ++){
            int case1 = dparr[0][j]; //not gonna hold
            int case2;
            if(j>=cost[i]){ //can hold
                case2 = dparr[0][j-cost[i]]+mem[i];
            }
            else{//cannot hold
                case2 = dparr[0][j];
            }
            dparr[1][j] = (case1>case2?case1:case2);
        }
        for(int j = 0 ; j < 10001 ; j ++){
            dparr[0][j]=dparr[1][j];
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    read();
    dp();
    int ret = 0x3f3f3f3f;
    for(int i = 0 ; i < 10001 ; i ++){
        if(dparr[0][i]>=M){
            if(ret>=i){
                ret=i;
                break;
            }
        }
    }
    printf("%d",ret);
    return 0;
}