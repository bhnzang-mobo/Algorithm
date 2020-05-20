#include <stdio.h>

int dial(char c){
    return c%65;
}

int main (){
    char c;
    int sum=0;
    scanf("%c",&c);
    int num[]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10,0};
    
    while(c!='\n'){
        sum+=num[dial(c)];
        scanf("%c",&c);
    }
    printf("%d", sum);
    return 0;
}