#include <stdio.h>
#include <stdlib.h>

typedef struct dunch{
    int x;
    int y;
}dunch;

dunch arr[51];


int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i ++){
        scanf("%d %d",&(arr[i].x),&(arr[i].y));
    }
    for(int i = 0 ; i < num ; i ++){
        int ret=1;
        for(int j = 0 ; j < num ; j ++){
            if(arr[j].x>arr[i].x && arr[j].y>arr[i].y){
                ret++;
            }
        }
        printf("%d ",ret);
    }

    return 0;
}