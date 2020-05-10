#include <stdio.h>
#include <stdlib.h>


int main (){
    int num;
    scanf("%d",&num);
    if(num<100) printf("%d",num);
    else{
        int ret=0;
        for(int i = 100; i <=num ; i ++){
            int H,T,O;
            H=i/100;
            T=(i%100)/10;
            O=(i%10);
            if(T-H==O-T){
                ret+=1;
            }
        }
        printf("%d",ret+99);
    }
}