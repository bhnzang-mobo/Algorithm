#include <stdio.h>

int main(){
    int A,B,V;
    int sum=0;
    int quo,res;
    scanf("%d %d %d",&A,&B,&V);
    quo = (V-A)/(A-B);
    res = (V-A)%(A-B);
    if(res==0){
        printf("%d",quo+1);
        return 0;
    }
    else{
        printf("%d",quo+2);
        return 0;
    }
    return 0;
}