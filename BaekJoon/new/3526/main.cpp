#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <malloc.h>

int n,m;
using namespace std;




typedef struct leaf{
    int node;
    struct leaf * left;
    struct leaf * right;
}leaf;

typedef struct v{
    int weight; //출발점 1에서부터 해당 노드까지 걸리는 최소 weight
    int from; //해당 최소 weight를 갖기 위해 어디서 왔는지를 기록.
    leaf* tree;//해당 노드에 연결된 다른 노드와 그 사이 엣지의 weight <노드, 복도색>
}v;

v mymap[100001];
leaf leafPool[100001];
int leafIdx;

leaf** bstFind(leaf** v, int num){
    leaf** tmp = v;
    while((*tmp)!=NULL){
        if((*tmp)->node==num){
            break;
        }
        else if((*tmp)->node < num){
            tmp= &((*tmp)->right);
        }
        else{
            tmp=&((*tmp)->left);
        }
    }
    return tmp;
}

void bstInsert(leaf** v, int num){
    (*v)=&leafPool[leafIdx++];
    (*v)->node=num;
    (*v)->left=NULL;
    (*v)->right=NULL;
}

void queueInsert(queue<int> &queue, leaf* v){
    queueInsert(queue,v->left);
    queue.push(v->node);
    queueInsert(queue,v->right);
}

void read(){
    leafIdx=0;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m ; i ++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==b) continue;
        
    }
}

void bfs(){
    queue<int> myqueue;
    queueInsert(myqueue,mymap[1].tree);
    for( ; tmp != mymap[1].myarr.end(); tmp++){

    }
}

int main( int argc, char * argv[] )
{
    freopen("input.txt","r",stdin);
    read();

    return 0;
}