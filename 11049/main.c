#include <stdio.h>
#include <string.h>

struct matrix
{
    int a;
    int b;
} matrix[501];

int dparr[501][501];

int dp(int a, int b){
    if(dparr[a][b]!=0x3f3f3f3f){//11066번과 비슷한 문항
        return dparr[a][b];
    }
    if(a==b){
        dparr[a][b]=0;
        return 0;
    }
    if(a+1==b){
        dparr[a][b]=matrix[a].a*matrix[a].b*matrix[b].b;
        return matrix[a].a*matrix[a].b*matrix[b].b;
    }
    for(int i = a ; i < b ; i ++){
        int left = dp(a,i);
        int right = dp(i+1,b);
        int comp;
        if(left==0){
            if(right==0){
                comp=matrix[a].a*matrix[a].b*matrix[b].b;
            }
            else{
                comp=matrix[a].a*matrix[a].b*matrix[b].b+right;
            }
        }
        else if(right==0){
            comp=left+matrix[a].a*matrix[b].a*matrix[b].b;
        }
        else{
            comp=matrix[a].a*matrix[i].b*matrix[b].b+left+right;
        }
        dparr[a][b]=(dparr[a][b]>comp?comp:dparr[a][b]);
    }
    return dparr[a][b];
}

int N;
int main(){
    scanf("%d",&N);
    memset(dparr,0x3f,sizeof(dparr));
    for(int i = 0 ; i < N ; i ++){
        scanf("%d %d",&matrix[i].a,&matrix[i].b);
    }
    dp(0,N-1);
    printf("%d",dparr[0][N-1]);

    return 0;
}