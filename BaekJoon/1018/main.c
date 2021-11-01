#include <stdio.h>
#include <stdlib.h>

int chess [51][51];
int cal(int a, int b){
    int flag;
    int ret=0;
    if(chess[a][b]==1){
        flag=-1;
    }
    else{
        flag=1;
    }
    for(int i = a ; i < a+8 ; i++){
        flag*=-1;
        for(int j = b ; j < b+8 ; j++){
            if(chess[i][j]==flag) flag*=-1;
            else{
                ret++;
                flag*=-1;
            }
        }
    }
    return ret>=32?64-ret:ret; //이부분이 틀렸었음 원래는.. return ret
    /*그냥 ret 하면 기준이 첫 번째판의 색깔이므로 63개를 바꿔야 하는 경우가 생김. 이 경우
    63개를 전부 바꾸는 것 보다 나머지 1개를 바꾸는 것이 낫다.
    즉, 33개 이상의 체스판을 바꿔야 하는 경우 반대로 31개의 체스판을 바꾸는게 낫다는 뜻.
    즉 33이상이면 64에서 빼 반대의 경우를 리턴.*/
}
int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    char ch;
    for(int i = 0 ; i < M ; i ++){
        for(int j = 0 ; j < N ; j ++){
            scanf(" %c",&ch);
            if(ch=='W') chess[i][j]=1;
            else chess[i][j]=-1;
        }
    }
    int min=M*N;
    for(int i = 0 ; i <=M-8 ; i ++){
        for(int j = 0 ; j <=N-8 ; j ++){
            int val = cal(i,j);
            if(min>val) min=val;
        }
    }
    printf("%d",min);
    return 0;
}