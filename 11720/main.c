#include <stdio.h>
#include <stdlib.h>

int main (){
    char c;
    int sum=0;
    int i;
    scanf("%d",&i);
    for(int j = 0 ; j < i ; j ++ ){
        scanf(" %c",&c);//whitespace must be included
        sum+=c-48;
    }
    printf("%d",sum);
    return 0;
}

