#include <stdio.h>

int main(){
    int i=0;
    int idx=1;
    int num;
    scanf("%d",&num);
    while(num>idx){
        i++;
        idx+=6*i;
    }
    printf("%d",i+1);
    return 0;
}