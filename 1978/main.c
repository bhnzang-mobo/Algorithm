#include <stdio.h>
#include <stdlib.h>

int num[1001];
int main(){
    num[1]=1;
    int idx = 2;
    while(idx<=1000){
        int i =2;
        while(i*idx<=1000){
            if(num[i*idx]==0){
                num[i*idx]=1;
            }
            i++;
        }
    idx++;
    }
    int input;
    scanf("%d",&input);
    int sum=0;
    for(int i = 0 ; i < input ; i ++){
        int ret;
        scanf("%d",&ret);
        if(!num[ret]) sum++;
    }
    printf("%d",sum);
    return 0;
}