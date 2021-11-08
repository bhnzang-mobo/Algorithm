#include <stdio.h>
#include <string.h>
int dparr [500][500];
int map[500][500];
int M,N;

void init(){
    memset(dparr,0x3f,sizeof(dparr));
    scanf("%d %d",&M,&N);
    for(int i = 0 ; i < M ; i ++){
        for(int j = 0 ; j < N ; j ++){
            scanf("%d",&map[i][j]);
        }
    }
}

int dp(int y, int x){
    if(y<0 || x<0 || y>=M || x>=N){
        return 0;
    }
    if(dparr[y][x]!=0x3f3f3f3f){
        return dparr[y][x];
    }
    if(y==x && x==0){
        dparr[0][0]=1;
        return 1;
    }
    int ret = 0;
    if(map[y][x]<map[y-1][x]){
        ret+=dp(y-1,x);
    }
    if(map[y][x]<map[y+1][x]){
        ret+=dp(y+1,x);
    }
    if(map[y][x]<map[y][x-1]){
        ret+=dp(y,x-1);
    }
    if(map[y][x]<map[y][x+1]){
        ret+=dp(y,x+1);
    }
    dparr[y][x]=ret;
    return ret;
}
int main() {    
    init();
    printf("%d",dp(M-1,N-1));
    return 0;
}