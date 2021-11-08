#include <stdio.h>

int N;
int RGB[1001][3];
int dparr[1001][3];

int min(int a,int b){
    return (a<b?a:b);
}
void dp(){
    dparr[0][0]=RGB[0][0];
    dparr[0][1]=RGB[0][1];
    dparr[0][2]=RGB[0][2];

    for(int i = 1 ; i < N ; i++){
        dparr[i][0]=min(dparr[i-1][1],dparr[i-1][2])+RGB[i][0];
        dparr[i][1]=min(dparr[i-1][0],dparr[i-1][2])+RGB[i][1];
        dparr[i][2]=min(dparr[i-1][1],dparr[i-1][0])+RGB[i][2];
    }

}
int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d %d %d",&RGB[i][0],&RGB[i][1],&RGB[i][2]);
    }
    dp();
    int comp = min(dparr[N-1][0],dparr[N-1][1]);
    comp=min(comp,dparr[N-1][2]);
    printf("%d",comp);
    return 0;
}