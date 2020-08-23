#include <stdio.h>

int dparr[100001];
int N;
void dp(){

    for(int i = 1 ; i < N ; i ++){
        dparr[i]=(dparr[i-1]<=0?dparr[i]:dparr[i-1]+dparr[i]);
    }

}

int max(){
    int ret = -1001;
    for(int i = 0 ; i < N ; i ++){
        ret=(ret>dparr[i]?ret:dparr[i]);
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&dparr[i]);
    }
    dp();
    printf("%d",max());
    return 0;
}