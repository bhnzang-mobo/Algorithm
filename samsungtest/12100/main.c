#include <stdio.h>

int mat[21][21];
int N,ans;

int innerCheck(int x, int y){
    if( 0<=x&& x<=N-1 && 0<=y && y<=N-1){
        return 1;
    }
    return 0;
}
int comCheck(int x,int y, int dir){
    //(x,y) dir 0 1 2 3 up right down left
    int dx,dy;
    switch (dir)
    {
    case 0:
        dx=-1;
        dy=0;
        break;
    case 1:
        dx=0;
        dy=1;
        break;
    case 2:
        dx=1;
        dy=0;
        break;
    case 3:
        dx=0;
        dy=-1;
        break;
    default:
        break;
    }
    int ret=0;
    int ddx=dx;
    int ddy=dy;
    while(mat[x][y]!=0 && innerCheck(x+dx,y+dy)){
        if(mat[x][y]==mat[x+dx][y+dy]){
            mat[x][y]*=2;
            mat[x+dx][y+dy]=0;
            ret+=1;
            break;
        }
        else if(mat[x+dx][y+dy]==0){
            dx+=ddx;
            dy+=ddy;
        }
        else{
            break;
        }
    }
    return ret;
}
int move(int x,int y, int dir){
    int dx,dy;
    switch (dir)
    {
    case 0:
        dx=-1;
        dy=0;
        break;
    case 1:
        dx=0;
        dy=1;
        break;
    case 2:
        dx=1;
        dy=0;
        break;
    case 3:
        dx=0;
        dy=-1;
        break;
    default:
        break;
    }
    int ret=0;
    while(mat[x][y]!=0 && innerCheck(x+dx,y+dy) && mat[x+dx][y+dy]==0){
        int tmp = mat[x+dx][y+dy];
        mat[x+dx][y+dy] = mat[x][y];
        mat[x][y] = tmp;
        x=x+dx;
        y=y+dy;
        ret=1;
    }
    return ret;
}
int left(){
    int ret=0;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            ret+=comCheck(j,i,1);
            ret+=move(j,i,3);
        }
    }
    return (ret>0?1:0);
}
int right(){
    int ret=0;
    for(int i = N-1 ; i >= 0 ; i --){
        for(int j = 0 ; j < N ; j ++){
            ret+=comCheck(j,i,3);
            ret+=move(j,i,1);
        }
    }
    return (ret>0?1:0);
}
int up(){
    int ret=0;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            ret+=comCheck(i,j,2);
            ret+=move(i,j,0);
        }
    }
    return (ret>0?1:0);
}
int down(){
    int ret=0;
    for(int i = N-1 ; i >= 0 ; i --){
        for(int j = 0 ; j < N ; j ++){
            ret+=comCheck(i,j,0);
            ret+=move(i,j,2);
        }
    }
    return (ret>0?1:0);
}
void matmax(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(ans<mat[i][j]){
                ans=mat[i][j];
            }
        }
    }
}
void Restoration(int restore[][N]){

    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            mat[i][j]=restore[i][j];
        }
    }

}
void tilt(int count,int arr[]){
    matmax();
    if(ans==128){
        printf(" ");
    }
    if(count >=5){

        return ;
    }
    
    int restore[N][N];
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            restore[i][j]=mat[i][j];
        }
    }
    if(left()){
        arr[count]=4;
        tilt(count+1,arr);
        Restoration(restore);
    }
    if(right()){
        arr[count]=2;
        tilt(count+1,arr);
        Restoration(restore);
    }
    if(up()){
        arr[count]=1;
        tilt(count+1,arr);
        Restoration(restore);
    }
    if(down()){
        arr[count]=3;
        tilt(count+1,arr);
        Restoration(restore);
    }
}

void read(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
int myval;
void showme(){
    printf("%dth try...\n",++myval);
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
}
int main(){/*
    while(1){
        int order;
        scanf("%d",&order);
        int(*oper[4])()={up,right,down,left};
        if(1<=order && order<=4){
            oper[order-1]();
        }
        else if(order==0){
            break;
        }
        showme();
    }*/
    freopen("input.txt","r",stdin);
    read();
    int arr[10];
    tilt(0,arr);
    printf("%d",ans);
    return 0;
}