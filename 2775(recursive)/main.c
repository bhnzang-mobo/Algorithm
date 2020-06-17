#include <stdio.h>
int arr[15][15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,};

int cal(int k, int n){ //recursive perfect!
    if(arr[k][n]!=0){
        return arr[k][n];
    }
    int sum=0;
    for(int i = 1 ; i <= n ; i++){
        sum+=cal(k-1,i);
    }
    arr[k][n]=sum;
    return arr[k][n];
}

int main(){
    int T,k,n;
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        scanf("%d %d",&k,&n);
        printf("%d\n",cal(k,n));
    }
    return 0;
}