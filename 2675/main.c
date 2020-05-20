#include <stdio.h>

void func(){
    int num;
    char c;
    scanf("%d ", &num);
    scanf("%c",&c);
    while(c!=10){
       for (int i = 0 ; i < num ; i ++){
            printf("%c",c);
        }
        scanf("%c",&c);
    }
    
}

int main (){
    int num;
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i ++){
        func();
        printf("\n");
    }
    return 0;
}