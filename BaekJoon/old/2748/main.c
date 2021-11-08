#include <stdio.h>
long long int arr[91]={0,};

long long int fiv(int k){
    if(k<=1){
        return k;
    }
    else
    {   
        if(arr[k]<=0){
            arr[k]=fiv(k-1)+fiv(k-2);
        }
        return arr[k];
    }
    
}

int main(){
    long long int T;
    scanf("%lld",&T);
    printf("%lld",fiv(T));
    return 0;
}