#include <stdio.h>
#include "graphKruskal.h"
#include <malloc.h>

int shortcut(ALGraph * al,int start, int end){
    int sum=0;
    DData next,origin;
    DData data;
    DList * obj,*start_obj;
    Stack stack, weightstack;
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
    Stackinit(&weightstack);
    Push(&stack,start);
    VisitVert(al,start);    
    origin.data=Peek(&stack);
    al->visitinfo[origin.data]=1;

    obj=&(al->list[start]);
    next.data=start;
    int weight=0;
    while(!isEmpty(&stack) || obj->cur->right!=obj->tail){
        if(next.data==end){
            break;
        }
        origin=next;
        DFirst(obj,&next);
        while(haveVisited(al->visitinfo,next.data)){
            if(!DNext(obj,&next)) break;
        }
        if(!haveVisited(al->visitinfo,next.data)){
            Push(&stack,origin.data);
            weight=next.weight;
            Push(&weightstack,weight);
            VisitVert(al,next.data);
            obj=&(al->list[next.data]);
            continue;
        }
        else{
            if(!isEmpty(&stack)){
                next.data=Pop(&stack);
                Pop(&weightstack);
                obj=&(al->list[next.data]);
            }
        }
    }
    while (!isEmpty(&weightstack))
    {
        sum+=Pop(&weightstack);
    }
    printf("%d",sum);
}
ALGraph* hardcopy(ALGraph* al){
    ALGraph* newal = (ALGraph*)malloc(sizeof(ALGraph));
    PQueueInit(&newal->pque,al->pque.comp);
    
    newal->num_edge=al->num_edge;
    newal->num_vert=al->num_vert;
    newal->list=(DList*)malloc(sizeof(DList)*(al->num_vert));
    for(int i = 0 ; i < al->num_vert ; i ++){//error : i < nv
        Dinit(&(newal->list[i]));
    }
    newal->visitinfo=(int*)malloc(sizeof(int)*(al->num_vert));
    
    int i= 1;
    pqueue pq = al->pque;
    while( i <= pq.numOfData){
        newal->pque.heaparr[i]=pq.heaparr[i];
        i++;
    }
    newal->pque.numOfData=pq.numOfData;
    i=0;
    DList dl = al->list[i];
    DData data;
    while(i<al->num_vert&&DFirst(&dl,&data)){
        DList* newdl= &(newal->list[i]);
        Dinsert(newdl,data);
        while(DNext(&dl,&data)){
            Dinsert(newdl,data);
        }
        i++;
        dl = al->list[i];
    }
    return newal;
}
/*
void changeweight(ALGraph* al,int P,int Q,int W){
    PQueue* pq = &(al->pque);
    int i =1;
    while(i<=pq->numOfData){
        Hdata data = pq->heaparr[i];
        if(data.)
    }
}
*/
int main(){
    ALGraph al;
    int H,V,W;
    scanf("%d %d",&H,&V);
    GraphInit(&al,H*V);
    ALGraph newal;
    GraphInit(&newal,H*V);
   
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < V-1 ; j++){
            scanf("%d",&W);
            AddEdge1(&al,V*i+j,V*i+j+1,W);
        }
    }
    for(int i = 0 ; i < H-1 ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d",&W);
            AddEdge2(&al,V*i+j,V*(i+1)+j,W);
        }
    }
    newal= *hardcopy(&al);
    
    
    ShowGraphInfo(&newal);
    int quest;
    scanf("%d",&quest);
    int q = 0;
    while( q < quest){
        int i1,i2,i3,i4;
        int point1,point2;
        DData data;
        DList* obj;
        scanf("%d",&i1);
        switch (i1)
        {
        case 1 :
        scanf("%d %d %d",&i2,&i3,&i4);
        point1 = V*i2+i3;
        point2 = V*i2+i3+1;
        obj = &(al.list[point1]);
        DFirst(obj,&data);
        if(data.data==point2){
            obj->cur->data.weight=i4;
        }
        else{
            while(DNext(obj,&data)){
                if(data.data==point2){
                    obj->cur->data.weight=i4;
                    break;
                }       
            }
        }
        obj = &(al.list[point2]);
        DFirst(obj,&data);
        if(data.data==point1){
            obj->cur->data.weight=i4;
        }
        else{
            while(DNext(obj,&data)){
                if(data.data==point1){
                    obj->cur->data.weight=i4;
                }       
            }
        }
        for(int i = 1 ; i <= al.pque.numOfData ; i++){
            Hdata *hdat=&al.pque.heaparr[i];
            if(hdat->v1==point1 && hdat->v2==point2){
                hdat->weight=i4;
                break;
            }
        }
            break;
        case 2 :
        scanf("%d %d %d",&i2,&i3,&i4);
        point1 = V*i2+i3;
        point2 = V*(i2+1)+i3;
        obj = &(al.list[point1]);
        DFirst(obj,&data);
        if(data.data==point2){
            obj->cur->data.weight=i4;
        }
        else{
            while(DNext(obj,&data)){
                if(data.data==point2){
                    obj->cur->data.weight=i4;
                    break;
                }       
            }
        }
        obj = &(al.list[point2]);
        DFirst(obj,&data);
        if(data.data==point1){
            obj->cur->data.weight=i4;
        }
        else{
            while(DNext(obj,&data)){
                if(data.data==point1){
                    obj->cur->data.weight=i4;
                    break;
                }       
            }
        }
        for(int i = 1 ; i <= al.pque.numOfData ; i++){
            Hdata *hdat=&al.pque.heaparr[i];
            if(hdat->v1==point1 && hdat->v2==point2){
                hdat->weight=i4;
                break;
            }
        }
            break;
        case 3 :
        scanf("%d %d",&i2,&i3);
        point1=i2;
        point2=V*(H-1)+i3;
        newal = *hardcopy(&al);
        ConKruskal(&newal,V);
        ShowGraphInfo(&newal);
        shortcut(&newal,point1,point2);
            break;
        }
        q++;
    }
    return 0;
}