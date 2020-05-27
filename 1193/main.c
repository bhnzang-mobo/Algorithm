#include <stdio.h>

int main(){
    int A;
    int ret1,ret2;
    scanf("%d",&A);
    int i =1;
    int sum=0;
    sum+=i;
    while(sum<A){
        i++;
        sum+=i;
    }
    A-=sum-i+1;
    if(i%2==0){
        ret1=1+A;
        ret2=i-A;
    }
    else{
        ret2=1+A;
        ret1=i-A;
    }
    printf("%d/%d",ret1,ret2);
    return 0;
}