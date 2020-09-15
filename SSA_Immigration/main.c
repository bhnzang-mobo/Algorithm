#include <stdio.h>
#define LLU unsigned long long int

long int tk[100001];

LLU ret;
LLU min;
int N,M;
void bs(LLU start,LLU end, int target){
    LLU mid = (start+end)/2;
    LLU m=0;
    for(int i = 0 ; i < N ; i ++){
        m+=mid/tk[i];
    }
    if(target<=m && ret>mid){
        ret=mid;
    }
    if(start == mid || mid == end){
        return;
    }
    if(m>=target){
        bs(start,mid,target);
    }
    else{
        bs(mid+1,end,target);
    }

}
int T;
int main(){
    setbuf(stdout,NULL);
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        scanf("%ld %ld",&N,&M);
        min=__INT64_MAX__;
        ret=__INT64_MAX__;
        for(int j = 0 ; j < N ; j ++){
            scanf("%d",&tk[j]);
            if(min>tk[j]){
                min=tk[j];
            }
        }
        bs(min,(LLU)M*min,M);
        printf("#%d %llu\n",i+1,ret);
    }
    return 0;
}