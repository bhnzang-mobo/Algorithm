#include <stdio.h>
#define _size 999

int start[_size];
int end[_size];
int profit[_size];
int profit_max[_size];
int t;
void init(){
    scanf("%d",&t);
    for(int i = 0 ; i < t; i ++){
        scanf("%d",&(start[i]));
    }
    for(int i = 0 ; i < t; i ++){
        scanf("%d",&(end[i]));
    }
    for(int i = 0 ; i < t; i ++){
        scanf("%d",&(profit[i]));
    }
}

/*
void dp_init(){ //초기값 설정
    for(int i = end[0] ; i < 999 ; i ++){
        profit_max[i]=profit[0];
    }
}
*/

void dp(){
    //dp_init();
    for(int i = 0 ; i < t ; i++){
        int b=i;
        while(b>0){
            if(end[b-1]<=start[i]){
                b-=1;
                break;
            }
            b-=1;
        }
        profit_max[end[i]]=(profit_max[end[b]]+profit[i]<profit_max[end[i]]?profit_max[end[i]]:profit_max[end[b]]+profit[i]);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int T=0;
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        init();
        dp();
        printf("%d\n",profit_max[end[t-1]]);
    }
    return 0;
}