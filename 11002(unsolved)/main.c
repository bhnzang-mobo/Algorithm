#include <stdio.h>
#include <math.h>

int N,M;
long int arr[100001][2];
long int path[100001][2];

void read(long int arr[][2],int X){
    for(int i = 0 ; i < X ; i++){
        scanf("%d %d",&(arr[i][0]),&(arr[i][1]));
    }
}
typedef struct node
{
    long int x;
    long int y;
}node;

typedef struct incinfo{
    long int x;
    long int y;
    long int idx;
    double inc;
}incinfo;

typedef int(*PriorityComp)(node,node);
typedef struct _heap{
    PriorityComp comp;
    int numOfData;
    node hparr[200001];
}heap;

void heapInit(heap* hp, PriorityComp comp){
    hp->comp = comp;
    hp->numOfData = 0;
}

void heapInsert(heap* hp, node data){
    int rt=0;
    int idx=hp->numOfData+1;
    while(idx>=2){
        rt=idx/2;
        if(hp->comp(data,hp->hparr[rt])){
            hp->hparr[idx]=hp->hparr[rt];
        }
        else{
            break;
        }
        idx=rt;
    }
    hp->hparr[idx]=data;
    hp->numOfData++;
}

node heapDelete(heap* hp){
    int mv;
    int idx=1;
    node delData = hp->hparr[1];
    node data = hp->hparr[hp->numOfData--];

    while(2*idx<=hp->numOfData){
        if(2*idx == hp->numOfData) mv=2*idx;
        else mv = (hp->comp(hp->hparr[2*idx],hp->hparr[2*idx+1]))?2*idx : 2*idx+1;

        if(hp->comp(hp->hparr[mv],data)){
            hp->hparr[idx]=hp->hparr[mv];
        }
        else{
            break;
        }
        idx=mv;
    }
    hp->hparr[idx]=data;
    return delData;
}

int isHeapEmpty(heap* hp){
    if(hp->numOfData<=0) return 1;
    else return 0;    
}

int comp(node a, node b){
    if(a.x < b.x){
        return 1;
    }
    else return 0;
}
double calIncl(node a, node b){
    return ((a.x-b.x)==0?-200000000:(a.y-b.y)/(a.x-b.x));
}

double max(double a, double b){
    return (a>b?a:b);
}

void cal(heap* hp){
    node init;
    init.x=path[0][0];
    init.y=path[0][1];
    heapInsert(hp,init);
    int mtn_idx=0;
    incinfo info;
    info.idx=0;
    for(int i = 0 ; i < M-1 ; i++){
        long int p1_x = path[i][0];
        long int p1_y = path[i][1];
        long int p2_x = path[i+1][0];
        long int p2_y = path[i+1][1];
        node comp;
        comp.x=p1_x;
        comp.y=p1_y;
    
        while(comp.x!=p2_x){
            node a,b;
            a.x=comp.x;
            a.y=comp.y;
            mtn_idx=info.idx;
            b.x=arr[mtn_idx][0];
            b.y=arr[mtn_idx][1];
            double maxin = calIncl(a,b);
            info.x=b.x;
            info.y=b.y;
            info.inc=maxin;
            while(arr[mtn_idx+1][0]<p2_x){
                mtn_idx++;
                b.x=arr[mtn_idx][0];
                b.y=arr[mtn_idx][1];
                double inc = calIncl(a,b);
                if(maxin<inc){
                    info.x=b.x;
                    info.y=b.y;
                    info.idx=mtn_idx;
                    info.inc=inc;
                    maxin=inc;
                }   
            }

            b.x=path[i+1][0];
            b.y=path[i+1][1];
            double inc = calIncl(a,b);
            if(maxin<inc){
                info.x=b.x;
                info.y=b.y;
                info.inc=inc;
                info.idx=mtn_idx+1;
                maxin=inc;
            }
            comp.x=info.x;
            comp.y=info.y;
            heapInsert(hp,comp);
        }
        
    }

}
double calDist(node a, node b){
    double X_sq = pow(a.x-b.x,2);
    double Y_sq = pow(a.y-b.y,2);
    return sqrt(X_sq+Y_sq);
}

double ret(heap* hp){
    double ret=0;
    node from, to;
    to = heapDelete(hp);
    while(!isHeapEmpty(hp)){
        from = to;
        to = heapDelete(hp);
        ret+=calDist(from,to);
    }
    return ret;
}

int main(){
    heap hp;
    heapInit(&hp,comp);
    scanf("%d",&N);
    read(arr,N);
    scanf("%d",&M);
    read(path,M);
    cal(&hp);
    
    printf("%.12lf",ret(&hp));
    return 0;
}