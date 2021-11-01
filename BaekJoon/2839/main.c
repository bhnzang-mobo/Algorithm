#include <stdio.h>

int main(){
    int A;
    int n3,n5;
    scanf("%d",&A);
    if(A%5 == 1 || A%5 == 4){
        n5=A/5 - 1;
        n3=(A%5+5)/3;
    }
    else if(A%5 == 3 || A%5 == 0){
        n5=A/5;
        n3=A%5/3;
    }
    else{
        n5=A/5 -2;
        n3=4;
    }
    printf("%d", n5>=0?n5+n3:-1);
    return 0;
}