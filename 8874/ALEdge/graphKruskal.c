#include <stdio.h>
#include <malloc.h>
#include "graphKruskal.h"
//enum value starts with 0. E = 4
int PQWeightComp(Edge a, Edge b){ //int type? new Edge type?
    if(b.weight<a.weight){
        return 1;
    }
    return 0; //1: a>b 0 : a<b
}
void GraphInit(ALGraph* al,int nv){//nv is number of vertex
    al->num_vert=nv;
    al->num_edge=0;
    //Cause of Crash.
    //Not enough allocation. it was...
    //sizeof(DLlist)*nv, which is nv+1 = al->num_vert.
    al->list=(DList*)malloc(sizeof(DList)*(al->num_vert));
    al->visitinfo=(int*)malloc(sizeof(int)*(al->num_vert));
    for(int i = 0 ; i < nv ; i ++){//error : i < nv
        Dinit(&(al->list[i]));
    }
    PQueueInit(&(al->pque),PQWeightComp);
    
}
void AddEdge1(ALGraph* al,int from ,int to, int weight){
    DList* obj = &(al->list[from]);
    DData data={to,weight};
    Dinsert(obj,data);
    obj = &(al->list[to]);
    data.data=from;
    data.weight=weight;
    Dinsert(obj,data);
    al->num_edge++;
    PQueue *pq = &(al->pque);
    Edge data2 = {from,to,weight};
    PEnqueue(pq,data2);

}
void AddEdge2(ALGraph* al,int from ,int to, int weight){
    DList* obj = &(al->list[from]);
    DData data={to,weight};
    Dinsert(obj,data);
    obj = &(al->list[to]);
    al->num_edge++;
    PQueue *pq = &(al->pque);
    Edge data2 = {from,to,weight};
    PEnqueue(pq,data2);

}
void ShowGraphInfo(ALGraph* al){
    DData data;
    int i = 0;
    while(i<=al->num_vert-1){
        printf("%c to ",'A'+i);
        DList* obj = &(al->list[i++]);
        if(DFirst(obj,&data)){
            printf("%c:%d | ",'A'+data.data,data.weight);
            while(DNext(obj,&data)){
                printf("%c:%d | ",'A'+data.data,data.weight);
            }
        }
        printf("\n");
    }
}
void FreeGraph(ALGraph* al){
    DData data;
    int i = 0;
    while(i<=al->num_vert){
        DList* obj = &(al->list[i++]);
        if(DFirst(obj,&data)){
            DRemove(obj);
            while(DNext(obj,&data)){
                DRemove(obj);
            }
        }
        printf("\n");
    }
}


int haveVisited(int list [], int k){
    if(list[k]==1) return 1;
    else return 0;
}
void VisitVert(ALGraph* al, int visit){
    al->visitinfo[visit]=1;
    printf("%c refered\n",'A'+visit);
}

void DFS(ALGraph* al,int start){
    DData next,origin;
    DData data;
    DList * obj,*start_obj;
    Stack stack;
    int i = 0;
    start_obj=&(al->list[start]);
    
    while(i < al->num_vert){
        DFirst(&(al->list[i]),&data);
        i++;
    }

    for(int i = 0 ; i < al->num_vert ; i ++){
        al->visitinfo[i]=0;
    }

    Stackinit(&stack);
    Push(&stack,start);
    VisitVert(al,start);    
    origin.data=Peek(&stack);
    al->visitinfo[origin.data]=1;

    obj=&(al->list[start]);
    next.data=start;

    /*
    while(haveVisited(al->visitinfo,next)){//What's next?
        DNext(obj,&next);
    }
    obj=&(al->list[next]);
    printf("%c Refered.\n",'A'+next);
    */

    while(!isEmpty(&stack) || obj->cur->right!=obj->tail){
        origin=next;
        DFirst(obj,&next);
        while(haveVisited(al->visitinfo,next.data)){//What's next?
            if(!DNext(obj,&next)) break;
        }
        if(!haveVisited(al->visitinfo,next.data)){ //Yes Next
            Push(&stack,origin.data);
            VisitVert(al,next.data);
            obj=&(al->list[next.data]);
            continue;
        }
        else{ //No next
            if(!isEmpty(&stack)){
                next.data=Pop(&stack);
                obj=&(al->list[next.data]);
            }
        }
    }
}

void BFS(ALGraph* al, int start){
    //init
    DData originV,nextV;
    DData data;
    DList* obj;
    queue alque;
    queueinit(&alque);

    for(int i = 0 ; i < al->num_vert ; i ++){
        al->visitinfo[i]=0;
    }

    enqueue(&alque,start);
    VisitVert(al,start);
    obj= &(al->list[start]);
    
    while(!isQEmpty(&alque)){
        nextV.data=dequeue(&alque);
        obj=&(al->list[nextV.data]);
        if(DFirst(obj,&nextV)){
            if(!haveVisited(al->visitinfo,nextV.data)){
                VisitVert(al,nextV.data);
                enqueue(&alque,nextV.data);
            }
            while(DNext(obj,&nextV)){
                if(!haveVisited(al->visitinfo,nextV.data)){
                    VisitVert(al,nextV.data);
                    enqueue(&alque,nextV.data);
                }
            }
        }
    }

}

int isConnect(ALGraph* al){
    BFS(al,A);
    for(int i = 0 ; i < al->num_vert ; i ++){
        if(al->visitinfo[i]==0){
            return 0;
        }
    }
    return 1;
}

void ConKruskal(ALGraph * al,int V){
    if(isPQEmpty(&(al->pque))){
        return;
    }
    PQueue pq = al->pque;
    
    while(al->num_vert<al->num_edge+1){
        //1.delete
        PQData data = PDequeue(&pq);
        int from = data.v1;
        int to = data.v2;
        DData comp;
        int weight;
        DFirst(&(al->list[from]),&comp);
        if(to==comp.data){
            weight=DRemove(&(al->list[from])).weight;
        }
        else{
            while(DNext(&(al->list[from]),&comp)){
                if(to==comp.data){
                    weight=DRemove(&(al->list[from])).weight;
                    break;
                }
            }  
        }
        DFirst(&(al->list[to]),&comp);
        if(from==comp.data){
            weight=DRemove(&(al->list[to])).weight;
        }
        else{
            while(DNext(&(al->list[to]),&comp)){
                if(from==comp.data){
                    weight=DRemove(&(al->list[to])).weight;
                    break;
                }
            }  
        }
        al->num_edge--;
        //2.connection test
        if(isConnect(al)){
            continue;
        }
        else{
            DList* obj = &(al->list[from]);
            DData A={to,weight};
            Dinsert(obj,A);
            if(to-from!=V){
                obj = &(al->list[to]);
                A.data=from;
                A.weight=weight;
                Dinsert(obj,A);
            }
            
            al->num_edge++;
        }
        //2.1 success = continue
        //2.2 fail = undo delete and continue
    }
}
