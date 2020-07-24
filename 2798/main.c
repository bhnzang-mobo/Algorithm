#include <stdio.h>
#include <stdlib.h>

int card[101];
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&card[i]);
    }
    int max = 0;
    for(int i = 0 ; i < N ; i ++){//3차 브루트 포스는 j는 i에, k는 j 에 걸어야한다. 둘 다 i에 걸면 j와 k가 같아지는 경우가 생기므로 주의.
        for(int j = i+1; j < N ; j ++){
            for(int k = j+1 ; k < N ; k ++){//k=i+2 였다.
                int comp = card[i]+card[j]+card[k];
                if(max<=comp && comp<=M){
                    max=comp;
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}