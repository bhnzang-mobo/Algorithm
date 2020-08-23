#include <stdio.h>
#include <string.h>

char arr[51];
int N,M;
void parse(){
    N=strlen(arr);
    int flag=0;
    for(int i = 0 ; i < N; i++){
        if(arr[i]=='-'){
            flag=1;
            continue;
        }
        if(arr[i]=='+'&& flag>0){
            arr[i]='-';
            continue;
        }
        
    }
}
int main(){
    scanf("%s",arr);
    parse();
    int ret=0;
    int parsed=0;
    int oper=1;
    for(int i = 0 ; i <= N ; i ++){
        if(arr[i]=='-'){
            if(oper==1){
                ret+=parsed;
                parsed=0;
                oper=0;
            }
            else{
                ret-=parsed;
                parsed=0;
            }
        }
        else if(arr[i]=='+'){
            if(oper==1){
                ret+=parsed;
                parsed=0;
            }
            else{
                ret-=parsed;
                parsed=0;
                oper=1;
            }
        }
        else if(arr[i]=='\0'){
            if(oper==1){
                ret+=parsed;
                parsed=0;
            }
            else{
                ret-=parsed;
                parsed=0;
            }
        }
        else{
            parsed*=10;
            parsed+=arr[i]-48;
        }
    }
    printf("%d",ret);
    return 0;
}