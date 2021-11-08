#include <stdio.h>

int N,M;
int S,E;
int arr[2001];
int dparr[2001][2001];
int isP(int,int);
void cal(){
    for(int i = 1 ; i <= N ; i ++){
        for(int j = 0 ; j <= N ; j ++){
            if(i-j<1 || i+1+j>N){
                break;
            }
            if(arr[i-j]==arr[i+1+j]){
                dparr[i-j][i+1+j]=1;
            }
            else{
                break;
            }
        }
    }
    for(int i = 1 ; i < N ; i ++){
        for(int j = 0 ; j <= N ; j ++){
            if(i-1-j<1 || i+1+j >N){
                break;
            }
            if(arr[i-1-j]==arr[i+1+j]){
                dparr[i-1-j][i+1+j]=1;
            }
            else{
                break;
            }
        }
    }
}

int isP(int start,int end){
    int mid=(end-start+1)/2;
    if((end-start+1)%2==0){
        for(int i = start ; i < start+mid ; i++){
            if(arr[i]!=arr[mid+i]){
                return 0;
            }
        }
        return 1;
    }
    else{
        for(int i = start ; i < start+mid ; i++){
            if(arr[i]!=arr[1+mid+i]){
                return 0;
            }
        }
        return 1;
    }
}
void read(){
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i ++){
        scanf("%d",arr+i);
    }
    scanf("%d",&M);
}
int main(){
    freopen("input.txt","r",stdin);
    read();
    cal();
    for(int i = 0 ; i < M ; i ++){
        scanf("%d %d",&S,&E);
        printf("%d\n",(S==E?1:dparr[S][E]));
    }
    return 0;
}