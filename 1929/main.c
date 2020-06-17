#include <stdio.h>
#include <stdlib.h>
int num[1000001];
int main(){
    num[1]=1;
    int itr=2;
    while(itr<=500000){
        if(num[itr]==0){
            int i =2;
            while(i*itr<=1000000){
            num[i*itr]=1;
            i++;
            }
        }
        itr++;
    }
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    for(int i = num1; i <=num2 ; i ++){
        if(num[i]==0){
            printf("%d\n",i);
        }
    }
    return  0;
}