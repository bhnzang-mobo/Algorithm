#include <stdio.h>
#include <string.h>

char arr [2][1001];
int dparr[1001][1001];
int N,M;

int max(int a,int b){
    return (a>b?a:b);
}

void dp(){

    for(int i = 1 ; i <= strlen(arr[N]) ; i ++){
        for(int j = 1 ; j <= strlen(arr[M]) ; j ++){
            if(arr[N][i-1]==arr[M][j-1]){
                dparr[i][j]=dparr[i-1][j-1]+1;
            }
            else{
                dparr[i][j]=max(dparr[i-1][j],dparr[i][j-1]);
            }
        }
    }
}
int main () {
    scanf("%s",arr[0]);
    scanf("%s",arr[1]);
    N = (strlen(arr[0])<strlen(arr[1])?0:1);
    M = (strlen(arr[0])<strlen(arr[1])?1:0);
    dp();
    printf("%d",dparr[strlen(arr[N])][strlen(arr[M])]);
    return 0;
}