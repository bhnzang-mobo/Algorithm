#include <stdio.h>
#include <stdlib.h>

long long int arr[1000001];
unsigned long long int cal(int num){
    if(arr[num]==0){
        arr[num]=(cal(num-1)%15746+cal(num-2)%15746)%15746;
        return arr[num];
    }
    return arr[num];
}
void calInit(){
    arr[1]=1;
    arr[2]=2;
}

int cal2(int num){
    int a=1;
    int b=2;
    int c=3;
    for(int i = 0 ; i < num-3 ; i ++){
        a=b;
        b=c;
        c=a+b;
        if(c>15746){
            c%=15746;
        }
    }
    return num>=3?c : (num==1?a:(num==2?b:0));
}
int main(){
    int num;
    calInit();
    scanf("%d",&num);
    printf("%d",cal2(num));
    return 0;
}