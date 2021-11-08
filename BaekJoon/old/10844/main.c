#include <stdio.h>

int arr[101][11];
void dp(){
    for(int i = 1 ; i < 10 ; i++){
        arr[1][i]=1;
    }
    for(int i = 2 ; i < 101 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            int parm1 = (j-1<0?0:arr[i-1][j-1])%1000000000;
            int parm2 = (j+1>9?0:arr[i-1][j+1])%1000000000;
            arr[i][j]=(parm1+parm2)%1000000000;
        }
    }
}
int sum(int num){
    unsigned long long int ret=0;
    for(int i = 0 ; i < 10 ; i ++){
        ret+=arr[num][i];
    }
    return ret%1000000000;
}
int main(){
    dp();
    int num;
    scanf("%d",&num);
    printf("%d",sum(num));
    return 0;
}