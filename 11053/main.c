#include <stdio.h>

int N;
int arr[1001];
int dparr[1001];

void dp(){
    for(int i = 1 ; i<=N ; i++){
        int max = 0;
        for(int j = i-1 ; j >=0 ;  j--){
            if(arr[i]>arr[j] && max < dparr[j]+1){
                max=dparr[j]+1;
            }
        }
        dparr[i]=max;
    }
}
int max(){
    int m = 0;
    for(int i = 0 ; i <= N ; i ++){
        if(m<dparr[i]){
            m=dparr[i];
        }
    }
    return m;
}
int main(){
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i ++){
        scanf("%d",&arr[i]);
    }
    arr[0]=0;
    dparr[0]=0;
    dp();
    printf("%d",max());
    return 0;
}