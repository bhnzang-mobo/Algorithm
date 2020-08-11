#include <stdio.h>
int dparr[301];
int arr[301];
int num;
int max(int a, int b){
    return (a>b?a:b);
}
void dp(){
    dparr[1]=arr[1];
    dparr[2]=arr[1]+arr[2];

    for(int i = 3 ; i <= num ; i++){
        int comp1 = arr[i]+arr[i-1]+dparr[i-3];
        int comp2 = arr[i]+dparr[i-2];
        dparr[i]=max(comp1,comp2);
    }
}
int main(){
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i ++){
        scanf("%d",&arr[i+1]);
    }
    dp();
    printf("%d",dparr[num]);
    return 0;
}