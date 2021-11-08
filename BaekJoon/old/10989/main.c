#include <stdio.h>
#include <stdlib.h>

int arr[10001];
int main(){
    int N,num;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&num);
        arr[num]+=1;
    }
    for(int i = 1 ; i <= 10000 ; i ++){
        if(arr[i]==0){
            continue;
        }
        for(int j = 0 ; j < arr[i] ; j++){
            printf("%d\n",i);
        }
    }
    return 0;
}