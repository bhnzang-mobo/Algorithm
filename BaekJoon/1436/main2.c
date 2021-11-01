#include <stdio.h>
#include <stdlib.h>
//1.모든 수를 작은 수 부터 차례로 숌-테스트 하여 N개의 숌의 수가 나올때 까지 루프.
//2.조건의 맞는 수를 우선 계산해 N개의 숌의 수가 나올 때 까지 루프.
int arr[20];
int isShom(int comp){
    int tmp=comp;
    int oper=1;
    int i = 0;
    while(tmp>0){
        arr[i++]=comp/oper%10;
        oper*=10;
        tmp/=10;
    }
    int flag = 0;
    for(int j = 0 ; j < i ; j ++){
        if(arr[j]==6){
            flag++;
        }
        else{
            flag=0;
        }
        if(flag==3){
            return 1;
        }//플래그검사 위치에 따라 결과가 다름. 
        //맨 뒤에 666이 위치한 경우,플래그 조정 후 검사해야 됨.
        //아니면 플래그가 3인상태로 검사 못하고 끝.
    }
    return 0;
}

int main2(){
    int num;
    scanf("%d",&num);
    int ret = 0;
    int comp=666;
    while(ret<num){
        ret+=isShom(comp++);
    }
    printf("%d",comp-1);
    return 0;
}