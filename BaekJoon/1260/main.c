#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
    int numOfEdge;
    int numOfVertex;
    int list[1001][1001];
    int visitinfo[1001];
}graph;

void gpInit(graph * gp){
    scanf("%d %d",&(gp->numOfVertex),&(gp->numOfEdge));
    for(int i = 0 ; i <= gp->numOfVertex ; i ++){
        for(int j = 0 ; j <= gp->numOfVertex ; j++){
            gp->list[i][j]=0;
        }
        gp->visitinfo[i]=0;
    }
}

typedef struct sNode{
    int data;
    struct sNode* next;
}sNode;

typedef struct Stack{
    int numOfData;
    sNode* top;
}Stack;


void stackInit(Stack* stack){
    stack->numOfData=0;
    stack->top=NULL;
}
int isStackEmpty(Stack* stack){
    return stack->numOfData==0?1:0;
}
int Pop(Stack* stack){
    if(!isStackEmpty(stack)){
        sNode * delNode = stack->top;
        int ret=delNode->data;
        stack->top=stack->top->next;
        stack->numOfData--;
        free(delNode);
        return ret;
    }
    exit(-1);
}
void Push(Stack* stack, int data){
    sNode* newnode = (sNode*)malloc(sizeof(sNode));
    newnode->data=data;
    newnode->next=stack->top;

    stack->top=newnode;
    stack->numOfData++;
}

int Peek(Stack* stack){
    if(!isStackEmpty(stack)){
        return stack->top->data;
    }
    exit(-1);
}
typedef struct qNode{
    int data;
    struct qNode * next;
}qNode;


typedef struct Queue{
    int numOfData;
    qNode* head;
    qNode* tail;
}Queue;

void queueInit(Queue* queue){
    queue->head=NULL;
    queue->tail=NULL;
    queue->numOfData=0;
}

int isQueueEmpty(Queue* queue){
    return queue->head==NULL?1:0;
}

void Enqueue(Queue* queue, int data){
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    newNode->data=data;
    newNode->next=NULL;
    if(queue->head==NULL){
        queue->head=newNode;
        queue->tail=newNode;
    }
    else{
        queue->tail->next=newNode;
        queue->tail=newNode;
    }
    queue->numOfData++;
}

int Dequeue(Queue* queue){
    if(!isQueueEmpty(queue)){
        qNode* delNode = queue->head;
        int ret = delNode->data;
        queue->head=delNode->next;
        queue->numOfData--;
        free(delNode);
        return ret;
    }
    exit(-1);
}
int haveVisited(graph* gp, int v){
    return gp->visitinfo[v]==1?1:0;
}
void visitVert(graph* gp, int v){
    gp->visitinfo[v]=1;
    printf("%d ",v);
}
void DFS(graph * gp, int start){
    int nextV;
    int obj;
    Stack stack;
    stackInit(&stack);
    for(int i = 0 ; i <= 1000 ; i ++){
        gp->visitinfo[i]=0;
    }

    Push(&stack,start);
    visitVert(gp,start);
    obj=start;
    big:
    while (!isStackEmpty(&stack)){
        for(int i = 1 ; i <= gp->numOfVertex ; i ++){
            if(!haveVisited(gp,i)&&gp->list[obj][i]==1){
                Push(&stack,i);
                visitVert(gp,i);
                obj=i;
                goto big;
            }
        }
    Pop(&stack);
    if(!isStackEmpty(&stack)){
        obj=Peek(&stack);
    }
    } 
}

void BFS(graph* gp, int start){
    int nextV;
    int obj;
    Queue queue;
    queueInit(&queue);
    for(int i = 0 ; i <= 1000 ; i ++){
        gp->visitinfo[i]=0;
    }
    Enqueue(&queue,start);
    visitVert(gp,start);

    while(!isQueueEmpty(&queue)){
        obj=Dequeue(&queue);
        for(int i = 1 ; i <= gp->numOfVertex ; i ++){
            if(!haveVisited(gp,i)&&gp->list[obj][i]==1){
                Enqueue(&queue,i);
                visitVert(gp,i);
            }
        }
    }
}

int main(){

    graph gp;
    gpInit(&gp);
    int start;
    scanf("%d",&start);
    for(int i = 0 ; i < gp.numOfEdge ; i ++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        gp.list[v1][v2]=1;
        gp.list[v2][v1]=1;
    }
    DFS(&gp,start);
    printf("\n");
    BFS(&gp,start);
    
    return 0;
}