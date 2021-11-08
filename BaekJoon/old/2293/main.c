#include <stdio.h>

int n,k;
int arr[101];
int dparr[2][101];

void dp(){
    dparr[0][0]=1;
    for(int i = 0 ; i <= k ; i ++){
        if(i>=arr[0]&&i%arr[0]==0){
            dparr[0][i]=1;
        }
    }

    for(int i = 1 ; i < n ; i ++){
        for(int j = 0 ; j <= k ; j ++){
            if(j>=arr[i]){
                int quo = j/arr[i];
                for(int l = 1 ; l <= quo ; l++){
                    dparr[1][j]+=dparr[0][j-l*arr[i]];
                }
            }
            dparr[1][j]+=dparr[0][j];
        }
        for(int j = 0 ; j <=k ; j ++){
            dparr[0][j]=dparr[1][j];
            dparr[1][j]=0;
        }
    }

}
int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&arr[i]);
    }
    dp();
    printf("%d",dparr[0][k]);
    return 0;
}