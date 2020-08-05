#include <stdio.h>

int arr[101][3];
int memo[100001][101];
int N,K;


int big(int K,int m){//이게 시간복잡도 오지게잡아먹음 거의 n^3?
    int max = 0;
    int idx=-1;
    for(int i = 0 ; i < N; i ++){//가져올 수 있는 K무게의 물건들 중 최대값
        if(memo[m][i]==0){
            if(arr[i][0]==K && max<arr[i][1]){
            max=arr[i][1];
            idx=i;
            }
        }       
    }
    return idx; //그 물건의 인덱스값. arr[idx][1] 이 그 가치. -1은 무게에 해당하는 물건이 없다.
}

void copy(int K,int M){
    for(int i = 0 ; i < N ; i++){
        memo[M][i]=memo[K][i];
    }
}
int cal(int K){
    if(K<=1){
        int idx = big(1,1);
        memo[1][idx]=1;
        memo[1][100]=arr[idx][1];
        return arr[idx][1];
    }
    if(memo[K][100]>0){
        return memo[K][100];
    }
    int flag=0, max=-1;
    int single = big(K,K);
    int single_val = single>=0?arr[single][1]:0;
    int idx_i=-1;
    for(int i = 1 ; i <=K/2 ; i++){
        int comp = cal(K-i);
        int comp_single=big(i,K-i);
        int comp_single_val=comp_single>=0?arr[comp_single][1]:0;
        if(comp+comp_single_val>single_val){
            flag=1;
            single_val=comp+comp_single_val;
            idx_i=comp_single;
            max=i;
        }
    }
    if(flag>=1){
        copy(K-max,K);
        if(idx_i>=0){
            memo[K][idx_i]=1;
            }
        memo[K][100]=single_val;
    }
    else{
        memo[K][single]=1;
        memo[K][100]=single_val;
    }
    return single_val;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    printf("%d",cal(K));
    return 0;
}