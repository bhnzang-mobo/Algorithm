#include <stdio.h>
#include <stack>
#include <stdlib.h>

int N,M,ans;
char map[11][11];
using namespace std;
typedef struct __ball{
    int x;
    int y;
}ball;
ball R,B;

void read(){
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j ++){
            scanf(" %c ",&map[i][j]);
            if(map[i][j]=='R'){
                R.y=j;
                R.x=i;
            }
            if(map[i][j]=='B'){
                B.y=j;
                B.x=i;
            }
        }
    }
}


int canMove_up(){
    if(R.x==0 || R.y==0 || B.x==0 || B.y==0){
        return 0;
    }
    int ret=0;
    int flag=1;
    while(flag==1){
        flag=0;
        if(R.x-1>0 && map[R.x-1][R.y]=='.'){
            map[R.x-1][R.y]='R';
            map[R.x][R.y]='.';
            R.x--;
            flag=1;
            ret=1;
        }
        if(B.x-1>0 && map[B.x-1][B.y]=='.'){
            map[B.x-1][B.y]='B';
            map[B.x][B.y]='.';
            B.x--;
            flag=1;
            ret=1;
        }
        if(R.x-1>0 && map[R.x-1][R.y]=='O'){
            map[R.x][R.y]='.';
            R.x=0;
            R.y=0;
            flag=1;
            ret=1;
        }
        if(B.x-1>0 && map[B.x-1][B.y]=='O'){
            map[B.x][B.y]='.';
            B.x=0;
            B.y=0;
            flag=1;
            ret=1;
        }
    }
    return ret;
}
int canMove_down(){
    if(R.x==0 || R.y==0 || B.x==0 || B.y==0){
        return 0;
    }
    int ret=0;
    int flag=1;
    while(flag==1){
        flag=0;
        if(R.x+1>0 && map[R.x+1][R.y]=='.'){
            map[R.x+1][R.y]='R';
            map[R.x][R.y]='.';
            R.x++;
            flag=1;
            ret=1;
        }
        if(B.x+1>0 && map[B.x+1][B.y]=='.'){
            map[B.x+1][B.y]='B';
            map[B.x][B.y]='.';
            B.x++;
            flag=1;
            ret=1;
        }
        if(R.x+1>0 && map[R.x+1][R.y]=='O'){
            map[R.x][R.y]='.';
            R.x=0;
            R.y=0;
            flag=1;
            ret=1;
        }
        if(B.x+1>0 && map[B.x+1][B.y]=='O'){
            map[B.x][B.y]='.';
            B.x=0;
            B.y=0;
            flag=1;
            ret=1;
        }
    }
    return ret;
}
int canMove_left(){
    if(R.x==0 || R.y==0 || B.x==0 || B.y==0){
        return 0;
    }
    int ret=0;
    int flag=1;
    while(flag==1){
        flag=0;
        if(R.y-1>0 && map[R.x][R.y-1]=='.'){
            map[R.x][R.y-1]='R';
            map[R.x][R.y]='.';
            R.y--;
            flag=1;
            ret=1;
        }
        if(B.y-1>0 && map[B.x][B.y-1]=='.'){
            map[B.x][B.y-1]='B';
            map[B.x][B.y]='.';
            B.y--;
            flag=1;
            ret=1;
        }
        if(R.y-1>0 && map[R.x][R.y-1]=='O'){
            map[R.x][R.y]='.';
            R.x=0;
            R.y=0;
            flag=1;
            ret=1;
        }
        if(B.y-1>0 && map[B.x][B.y-1]=='O'){
            map[B.x][B.y]='.';
            B.x=0;
            B.y=0;
            flag=1;
            ret=1;
        }
    }
    return ret;
}
int canMove_right(){
    if(R.x==0 || R.y==0 || B.x==0 || B.y==0){
        return 0;
    }
    int ret=0;
    int flag=1;
    while(flag==1){
        flag=0;
        if(R.y+1>0 && map[R.x][R.y+1]=='.'){
            map[R.x][R.y+1]='R';
            map[R.x][R.y]='.';
            R.y++;
            flag=1;
            ret=1;
        }
        if(B.y+1>0 && map[B.x][B.y+1]=='.'){
            map[B.x][B.y+1]='B';
            map[B.x][B.y]='.';
            B.y++;
            flag=1;
            ret=1;
        }
        if(R.y+1>0 && map[R.x][R.y+1]=='O'){
            map[R.x][R.y]='.';
            R.x=0;
            R.y=0;
            flag=1;
            ret=1;
        }
        if(B.y+1>0 && map[B.x][B.y+1]=='O'){
            map[B.x][B.y]='.';
            B.x=0;
            B.y=0;
            flag=1;
            ret=1;
        }
    }
    return ret;
}

void Restore(int rx,int ry,int bx,int by){
   int rx_now=R.x;
    int ry_now=R.y;
    int bx_now=B.x;
    int by_now=B.y;
    char r_now;
    char b_now;

    R.x=rx;
    R.y=ry;
    B.x=bx;
    B.y=by;
    map[rx_now][ry_now]=(map[rx_now][ry_now]!='#'?'.':'#');
    map[bx_now][by_now]=(map[bx_now][by_now]!='#'?'.':'#');
    map[rx][ry]='R';
    map[bx][by]='B';
}
int goalCheck(){
    if(B.x==0||B.y==0){
        return 0;
    }
    if(R.x==0||R.y==0){
        return 1;
    }
    return 0;
}

int panemove(int Count, int red_x, int red_y, int blue_x, int blue_y,int dir){
    if(Count>10){
        return 0;
    }
    if(dir!=1 && canMove_left()){
        panemove(Count+1,R.x,R.y,B.x,B.y,3);
        if(goalCheck()){
            if(ans>Count){
                ans=Count;
            }
        }
        Restore(red_x,red_y,blue_x,blue_y);
    }
    if(dir != 3&&canMove_right()){
        panemove(Count+1,R.x,R.y,B.x,B.y,1);
        if(goalCheck()){
            if(ans>Count){
                ans=Count;
            }
        }
        Restore(red_x,red_y,blue_x,blue_y);
    }
    if(dir != 2&&canMove_up()){
        panemove(Count+1,R.x,R.y,B.x,B.y,0);
        if(goalCheck()){
            if(ans>Count){
                ans=Count;
            }
        }
        Restore(red_x,red_y,blue_x,blue_y);
    }
    if(dir != 0 &&canMove_down()){
        panemove(Count+1,R.x,R.y,B.x,B.y,2);
        if(goalCheck()){
            if(ans>Count){
                ans=Count;
            }
        }
        Restore(red_x,red_y,blue_x,blue_y);
    }

}
int main(){
    freopen("input.txt","r",stdin);
    stack<int> stack;
    scanf("%d %d",&N,&M);
    ans=0x3f3f3f3f;
    read();
    panemove(1,R.x,R.y,B.x,B.y,-1);
    printf("%d",(ans>10?-1:ans));
    return 0;
}