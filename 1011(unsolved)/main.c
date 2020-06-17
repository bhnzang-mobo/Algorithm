#include <stdio.h>
/* recursive한 방법 설계 자체는 올바르게 작동하지만 문제의 의도는 규칙성을 찾고 계산하는 것.
int ret;
int root(int distance, int from, int to){
    ret+=1;
    if(distance<=0){
        ret-=1;
        return 0;
    }
    if((to-from)==1){
        if(distance == 1|| distance ==2){
            return 1;
        }
        else{
            ret-=1;
             return 0;
        }
    }
    else if(to-from<=0){
        ret-=1;
        return 0;
    }
    if(root(distance+1,from+distance+1,to)){
        return 1;
    }
    else if(root(distance,from+distance,to)){
        return 1;
    }
    else if(root(distance-1,from+distance-1,to)){
        return 1;
    }
    else{
        ret-=1;
        return 0;
    }
}*/
 
int main(void)
{
    int test_case;
 
    scanf("%d",&test_case);
    for(int i = 0 ; i <test_case ; i++){
        int x,y;
 
        scanf("%d %d",&x,&y);
 
        int distance  = y-x;
 
        int i = 2;
        while(i*i-(i-1) > distance || i*i+i < distance){    
            i++;
        }
 
        if(i*i < distance){
            printf("%d\n",2*i);
        }else{
            printf("%d\n",2*i-1);
    
        }
    }
 
    
    return 0;
}
