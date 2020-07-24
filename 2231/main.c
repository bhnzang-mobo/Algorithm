#include <stdio.h>
#include <stdlib.h>

int main (){
    int num, min;
    scanf("%d",&num);
    int radix=1;
    int cal = num;
    while((cal/=10)>0){
        radix++;
    }
    min=num;
    for(int i = num ; i >=num-9*(radix+1) ; i--){
        cal=0;
        cal+=i;
        int oper=1;
        for(int j = 1 ; j <= radix ; j++,oper*=10){
            cal+=i/oper%10; //자리수 더하는게 입력된 수의 자리수마다 다르다
        }

        if(cal==num && i<min){
            min=i;
        }
    }
    printf("%d",min==num?0:min);
    return 0;
}