#include <stdio.h>

int __atoi(char C){
    if(C>96) return (C%65)-32;
    return (C%65);
}

char findmax(int* num){
    int max=0;
    int ret=0;
    int flag=0;
    for(int i = 0 ; i < 26 ; i ++){
        if(num[i]>max){
            max=num[i];
            ret=i;
        } 
    }
    for(int i = 0 ; i < 26 ; i ++){
        if(num[i]==max){
            if(flag) return '?';
            flag=1;
            continue;
        }
    }
    return ret+65;
}

int main(){
    char C;
    int num[28]={0,};
    scanf("%c",&C);
    while(C!=10){
        num[__atoi(C)]+=1;
        scanf("%c",&C);
    };
    printf("%c",findmax(num));
    return 0;
}