#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 2*123457
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

int howmany(int a){
    int ret=0;
    for(int i = a+1; i <= 2*a ; i ++){
        if(num[i]==0){
            ret++;
        }
    }
    return ret;
}
int main(){
    primeinit();
    int ret;
    scanf("%d",&ret);
    while(ret!=0){
        printf("%d\n",howmany(ret));
        scanf("%d",&ret);
    }
    return 0;
}