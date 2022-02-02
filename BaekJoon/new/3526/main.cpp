#include <iostream>
#include <vector>
#include <queue>
#include <malloc.h>
#define INIT_NUM 1000
#define EXPAND_NUM 2000

using namespace std;

/*
typedef struct node{
    int vertex;
    int color;
}node;

typedef struct pqueue{
    int capacity;
    int count;
    node * __pqueue;    
}pqueue;

pqueue pq[100001];
int n,m;

void init(){
    for(int i = 0 ; i <= n ; i ++){
        pq[i].capacity=0;
        pq[i].count=0;
        pq[i].__pqueue=(node*)malloc(sizeof(node)*INIT_NUM);
    }
}

int pq_isEmpty(pqueue * pq){
    return (pq->count==0 ? 1 : 0);
}
void pq_push(int a, int b, int c){
    if(a==b)return; //자기자신을 루프하는 경우는 넣지 않음.
    if(pq[a].capacity==pq[a].count){
        pq[a].__pqueue = (node*) realloc(pq[a].__pqueue,sizeof(node)*(pq[a].count+EXPAND_NUM));
    }
    
    int idx = ++(pq[a].count);
    while(idx >= 2){
        if(pq[a].__pqueue[idx/2].color>c){ // 부모와 자식의 우선순위
        //오류 :: pq[a].__pqueue[idx/2].color>pq[a].__pqueue[idx].color
        //c 가 아닌 idx 인덱스에 해당하는 원소와 비교하려 함.
            pq[a].__pqueue[idx].color=pq[a].__pqueue[idx/2].color;
            pq[a].__pqueue[idx].vertex=pq[a].__pqueue[idx/2].vertex;
        }
        else{
            break;
        }
        idx /=2;
    }
    pq[a].__pqueue[idx].vertex=b;
    pq[a].__pqueue[idx].color=c;
}

void pq_pop(pqueue * pq){
    int numOfEle = pq->count--;
    int idx = 1;
    int child;
    while(idx <= numOfEle/2){
        //우선순위가 더 높은 자식 노드 선택
        //오류 : 자식이 한 개인 경우를 고려하지 못함.

        if(idx*2 == numOfEle){ //자식이 한 개인 경우.
            child = idx*2;
        }
        else{
            child = (pq->__pqueue[idx*2].color < pq->__pqueue[idx*2+1].color)? idx*2 : idx*2+1;
        }
        if(pq->__pqueue[child].color<pq->__pqueue[numOfEle].color){ //해당 자식 노드와 우선순위 비교.
        //child와 numOfEle랑 비교할 것.
            pq->__pqueue[idx].color=pq->__pqueue[child].color;
            pq->__pqueue[idx].vertex=pq->__pqueue[child].vertex;
        }
        else{ //
            break;
        }
        idx = child;
    }
    pq->__pqueue[idx].color=pq->__pqueue[numOfEle].color;
    pq->__pqueue[idx].vertex=pq->__pqueue[numOfEle].vertex;
}

node pq_peek(pqueue * pq){
    return pq->__pqueue[1];
}

void read(){
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0 ; i < m ; i ++){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        pq_push(a,b,c);
        pq_push(b,a,c);
    }
}


void bfs(){
    struct cmp{
        bool operator()(pair<node,vector<int>>&a, pair<node,vector<int>>&b ){
            return a.first.color > b.first.color ;
        }
    };

    priority_queue<pair<node, vector<int>>,vector<pair<node, vector<int>>,cmp>> q;
    node tmp = {1,-1};
    q.push(make_pair(tmp,vector<int>(0)));
    int visit[100001]={0,};
    visit[1]=1;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size ; i ++){
            pair<node,vector<int>> current = q.top();
            q.pop();

            while(!pq_isEmpty(pq[current.first.vertex]))

        }
    }
}
*/
int main( int argc, char * argv[] )
{
    freopen("input.txt","r",stdin);
    read();
    //test;
    bfs();
    return 0;
}