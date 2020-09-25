#include <stdio.h>
#include <queue>
/*
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)

다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다.
 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)

다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,
정수 X와 문자 C로 이루어져 있으며. 게임 시작 시간으로부터 X초가 끝난 뒤에 
 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며,
 방향 전환 정보는 X가 증가하는 순으로 주어진다.
*/

using namespace std;
queue<pair<int,int>> snake;
int map[101][101];//0:Empty 1:Body of snake 2:apple
int N,K,L;
int time;
char dir[10001];

void read(){
    scanf("%d %d",&N,&K);
    int x,y;
    for(int i = 0 ; i < K ; i ++){
        scanf("%d %d",&x,&y);
        map[x-1][y-1]=2;
    }
    scanf("%d",&L);
    int X;
    char d;
    for(int i = 0 ; i < L ; i++){
        scanf("%d %c",&X,&d);
        dir[X]=d;
    }
}

void turnleft(int* dx, int* dy){
    if(*dx!=0){
        *dy=*dx;
        *dx=0;
    }
    else{
        *dx=-(*dy);
        *dy=0;
    }
}

void turnright(int* dx, int* dy){
    if(*dy!=0){
        *dx=*dy;
        *dy=0;
    }
    else{
        *dy=-(*dx);
        *dx=0;
    }
}
int canProceed(int x,int y){
    pair<int,int> tail = snake.front();
    if(0<=x && x<N && 0<=y && y<N){
        if(map[x][y]==1){
            //Body
            return 0;
        }
        else{
            //is Not Body
            return 1;
        }
    }
    else{
        return 0;
    }
}
int myval;
void showme(){
    printf("%d secs try..\n",time);
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
}
void move(){
    int dx,dy;
    dx=0,dy=1;
    while(1){
        int x=snake.back().first;
        int y=snake.back().second;
        showme();
        pair<int,int> coor;
        switch (dir[time]){
        case 0:
            break;
        case 'L':
            turnleft(&dx,&dy);
            break;
        case 'D':
            turnright(&dx,&dy);
            break;
        default:
            break;
        }

        if(canProceed(x+dx,y+dy)){
            if(map[x+dx][y+dy]==2){
                snake.push({x+dx,y+dy});
                map[x+dx][y+dy]=1;
            }
            else{
                snake.push({x+dx,y+dy});
                coor = snake.front();
                map[coor.first][coor.second]=0;
                map[x+dx][y+dy]=1;
                snake.pop();
            }
            time++;
        }
        else{
            time++;
            break;
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    snake.push({0,0});
    map[0][0]=1;
    read();
    move();
    printf("%d",time);
    return 0;
}