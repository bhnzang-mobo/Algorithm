#include <stdio.h>

typedef struct node{
    long long int val;
    int time0;
    int time1;
}node;

node arr[41];

void nodeInit(node * arr){
    for(int i = 0 ; i < 41 ; i ++){
        arr[i].val=0;
        arr[i].time0=0;
        arr[i].time1=0;
    }
    arr[0].time0=1;
    arr[0].val=0;
    arr[1].time1=1;
    arr[1].val=1;
}
node fiv(int k){
    if(k<=1){
        if(k==0){
            return arr[0];
        }
        return arr[1];
    }
    else
    {   
        if(arr[k].val<=0){
            node node1=fiv(k-1);
            node node2=fiv(k-2);
            arr[k].val=node1.val+node2.val;
            arr[k].time0=node1.time0+node2.time0;
            arr[k].time1=node1.time1+node2.time1;
        }
        return arr[k];
    }
    
}

int main(){
    int T,num;
    scanf("%d",&T);
    nodeInit(arr);
    for(int i = 0 ; i < T ; i ++){
        scanf("%d",&num);
        node ret = fiv(num);
        printf("%d %d\n",ret.time0,ret.time1);
    }
    return 0;
}