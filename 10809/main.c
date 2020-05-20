#include <stdio.h>

int main (){
    short num[30];
    for(int i = 0 ; i < 30 ; i ++){
        num[i]=-1;
    }
    char c;
    int count=0;
    scanf("%c",&c);
    while(97<=c && c<=122){ //\n = 10 in decimal
        if(num[c-97]==-1){
            num[c-97]=count;
        }
        scanf("%c",&c);
        count++;
    }
    for(int i = 0 ; i < 26 ; i ++){
        printf("%d ",num[i]);
    }
    return 0;
}