#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10000
int num[MAX_LEN];
void primeinit(){
    num[1]=1;
    int itr=2;
    int idx;
    while(itr<=MAX_LEN/2){
        if(num[itr]==0){
            idx=2;
            while(idx*itr<=MAX_LEN){
                num[idx*itr]=1;
                idx++;
            }
        }
        itr++;
    }
}

int blahblah(int a,int* ret1,int* ret2){
    for(int i = a/2 ; i >=2 ; i --){
        if(num[i]==0 && num[a-i]==0){
            *ret1=i;
            *ret2=a-i;
            return 1;
        }
    }
    return 0;
}
int main (){
    int ret1, ret2, itr,input;
    scanf("%d",&itr);
    primeinit();
    for(int i = 0 ; i < itr; i ++){
        scanf("%d",&input);
        if(blahblah(input, &ret1,&ret2)){
            printf("%d %d\n",ret1,ret2);
        }
        
    }
    return 0;   
}