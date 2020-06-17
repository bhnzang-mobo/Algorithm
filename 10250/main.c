#include <stdio.h>

int main(){
    int T,H,W,N;
    scanf("%d",&T);
    for(int i = 0 ; i < T; i ++){
        scanf("%d %d %d",&H,&W,&N);
        W=N/H+1;
        if(N%H<=0){
            W-=1;
        }
        H= N%H>0 ? N%H : H;
        printf("%d%02d\n",H,W);//Several outputs needs line break.\n!
    }
    return 0;
}