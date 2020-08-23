#include <stdio.h>

int N,K;

int arr[11];

int idx(){
    for(int i = 0 ; i < N ; i ++){
        if(K/arr[i]==0){
            return i;
        }
    }
    return N;//이거 조심!
}

int cal(){
    int tmp = idx()-1;
    int ret=0;
    for(int i = tmp ; i >=0 ; i--){
        ret += K/arr[i];
        K%=arr[i];
    }
    return ret;

}
int main() {
    scanf("%d %d",&N, &K);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&arr[i]);
    }
    printf("%d", cal());

    return 0;
}