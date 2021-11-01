#include <stdio.h>

int arr[10001];
int dparr[10001];
int N;

int max(int a, int b){
    return (a>b?a:b);
}
void dp(){
    dparr[0]=0;
    dparr[1]=arr[1];
    dparr[2]=arr[1]+arr[2];
    dparr[3]=max(arr[1],arr[2])+arr[3];
    for(int i = 4 ; i <=N ; i++){
        int comp1 = dparr[i-3]+arr[i-1];
        int comp2 = dparr[i-2];
        int comp3 = dparr[i-4]+arr[i-1];
        comp2 = max(comp2,comp3);
        dparr[i]=max(comp1,comp2)+arr[i];
    }

}
int main(){
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
    }
    dp();
    printf("%d",max(dparr[N],dparr[N-1]));

}