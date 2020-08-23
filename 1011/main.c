#include <stdio.h>
#include <math.h>
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
 
int cal(unsigned long int dis){
    unsigned long int tmp = (unsigned long int)sqrt(dis);//데이터타입 설정 바로 못하면  0 ,2^31에서 오류남
    if(dis == tmp*tmp){
        return 2*tmp-1;
    }
    else if(tmp*tmp < dis && dis <=(2*tmp*tmp + 2*tmp + 1)/2){
        return 2*tmp;
    }
    else{
        return 2*tmp+1;
    }
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",cal(y-x));
    }
    return 0;
}
