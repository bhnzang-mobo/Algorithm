#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int cal(int num, int len,int rel[], int arr[]){
   if(rel[num]!=0) return rel[num]; 
    int max=0;
    for(int i = 0 ; i < len ; i ++){
        int com=arr[i];
        if(num>com && num%com==0){
            int tmp=cal(com,len,rel,arr)+1;
            if(tmp>max) max=tmp;
        }
    }
    rel[num]=max;
    if(max==0){
        rel[num]=1;
    }
    return max==0?1:max;
}


int main(){
    int t,n,m;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i ++){
        int * rel = (int*)calloc(1000001,sizeof(int));
        int * arr = (int*)calloc(100001,sizeof(int));
        
        scanf("%d",&n);
        for(int j = 0 ; j < n ; j++){
            scanf("%d",&m);
            arr[j]=m;
        }
        for(int j = 0 ; j < n ; j++){
            cal(arr[j],n,rel,arr);
        }
        int max=1;
        for(int j = 0 ; j < n ; j++){
            if(rel[arr[j]]>max) max=rel[arr[j]];
        }
        printf("#%d %d\n",i+1,max);

    }
    return 0;
}