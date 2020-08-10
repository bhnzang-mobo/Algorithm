#include <stdio.h>

#define MAX_LEN 250*501+1
int arr[MAX_LEN];
int max(int a, int b){
    return (a>=b?a:b);
}

void dp(int num){
    
    for(int i = 2; i <= num ; i++){
        int idx = ((i-1)*i)/2+1;
        int idx2 = ((i+1)*i)/2;
        for(int j = idx ; j <= idx2 ; j++){
            if(j==idx){
                arr[j]+=arr[j-i+1];
            }
            else if(j==idx2){
                arr[j]+=arr[j-i];
            }
            else{
                arr[j]=max(arr[j-i+1],arr[j-i])+arr[j];
            }
        }
    }

}

int main(){
    int num,idx;
    scanf("%d",&num);
    idx=(num*(num+1))/2;
    for(int i = 1 ; i <= idx  ; i++){
        scanf("%d",&arr[i]);
    }
    dp(num);
    int max = 0;
    num=((num-1)*num)/2;
    for(int i = num ; i<=idx ; i ++){
        if(max<arr[i]) max=arr[i];
    }
    printf("%d",max);
    return 0;
}