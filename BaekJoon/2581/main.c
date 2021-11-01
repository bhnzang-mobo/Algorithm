#include <stdio.h>
#include <stdlib.h>

int num[10001];
int main(){
    int first =-1;
    num[1]=1;
    int idx = 2;
    while(idx<=5000){
        int i =2;
        while(i*idx<=10000){//boundary error..it was i*idx<=1000
            if(num[i*idx]==0){
                num[i*idx]=1;
            }
            i++;
        }
    idx++;
    }
    int num1, num2;
    int sum=0;
    scanf("%d %d",&num1, &num2);
    for(int i = num1 ; i <=num2; i ++){
        if(num[i]==0){
            sum+=i;
            if(first<0){
            first=i;
            }
        }
        
    }
    if(sum<=0){
        printf("-1");
    }
    else{
        printf("%d\n%d",sum,first);
    }
    return 0;
}