#include <stdio.h>

unsigned long long int arr[101];
int T;

void init(){
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    arr[4]=2;
    arr[5]=2;
}

void dp(){
    for(int i = 6 ; i <=100 ; i ++){
        arr[i]=arr[i-5]+arr[i-1];
    }
}
int main() {
    init();
    dp();
    scanf("%d",&T);
    int N;
    for(int i = 0; i < T ; i ++){
        scanf("%d",&N);
        printf("%llu\n",arr[N]);
    }
    return 0;
}