#include <stdio.h>
#include <string.h>
#include <malloc.h>

int N;
int arr[20];
char oper[20];
int ans;

typedef struct __qnode{
    int data;
    struct __qnode* next,*prev;
}qNode;

typedef struct __queue{
    int numOfData;
    struct __qnode * front,*rear;
}Queue;

void queueInit(Queue* q){
    q->numOfData=0;
    qNode* hdmy=(qNode*)malloc(sizeof(qNode));
    qNode* tdmy=(qNode*)malloc(sizeof(qNode));
    hdmy->next=tdmy;
    hdmy->prev=NULL;
    tdmy->prev=hdmy;
    tdmy->next=NULL;

    q->front=hdmy;
    q->rear=tdmy;
}

void enQueue(Queue* que, int data){
    qNode * newnode = (qNode*)malloc(sizeof(qNode));
    newnode->data=data;
    newnode->next=que->rear;
    newnode->prev=que->rear->prev;
    
    que->rear->prev->next=newnode;
    que->rear->prev=newnode;
    que->numOfData++;
}

int deQueue(Queue* que){
    if(que->numOfData!=0){
        qNode * delnode = que->front->next;
        int deldata=delnode->data;

        que->front->next=delnode->next;
        que->front->next->prev=que->front;
        que->numOfData--;
        free(delnode);
        return deldata;
    }
    else{
        return -1;
    }
}

int deQueue_back(Queue* que){
    if(que->numOfData!=0){
        qNode * delnode = que->rear->prev;
        int deldata=delnode->data;

        que->rear->prev=delnode->prev;
        que->rear->prev->next=que->rear;
        que->numOfData--;
        free(delnode);
        return deldata;
    }
    else{
        return -1;
    }
}
int isQueueEmpty(Queue* queue){
    if(queue->numOfData<=0){
        return 1;
    }
    else{
        return 0;
    }
}

int doTheThing(int deci_A, int deci_B,char oper){
    switch (oper)
    {
    case '+' :
        return deci_A+deci_B;
    case '-' :
        return deci_A-deci_B;
    case '*' :
        return deci_A*deci_B;
    default:
        break;
    }
}

int cal(Queue * queue){
    Queue backup;
    queueInit(&backup);
    int ret=deQueue(queue);
    enQueue(&backup,ret);
    int isNum=0;
    char oper;
    while(!isQueueEmpty(queue)){
        if(isNum==1){
            int back = deQueue(queue);
            enQueue(&backup,back);
            ret=doTheThing(ret,back,oper);
            isNum=0;
        }
        else{
            oper=deQueue(queue);
            enQueue(&backup,oper);
            isNum=1;
        }
    }
    while(!isQueueEmpty(&backup)){
        enQueue(queue,deQueue(&backup));
    }
    return ret;
}

void BT(Queue* queue,int operidx,int flag){
    if(N==1){
        ans=arr[0];
        return;
    }
    if(operidx == N-2){
        if(flag==1){
            enQueue(queue,oper[operidx]);
            enQueue(queue,arr[operidx+1]);
            int ret = cal(queue);
            ans=(ans>ret?ans:ret);
            deQueue_back(queue);
            deQueue_back(queue);
            return;           
        }
        else{
            enQueue(queue,doTheThing(arr[operidx-1],arr[operidx+1],oper[operidx]));
            int ret = cal(queue);
            ans=(ans>ret?ans:ret);
            deQueue_back(queue);

            enQueue(queue,arr[operidx-1]);
            enQueue(queue,oper[operidx]);
            enQueue(queue,arr[operidx+1]);
            ret = cal(queue);
            ans=(ans>ret?ans:ret);
            deQueue_back(queue);
            deQueue_back(queue);
            deQueue_back(queue);
            return;
        }
    }
    else{
        if(flag==1){
            enQueue(queue,oper[operidx]);
            BT(queue,operidx+2,0);
            deQueue_back(queue);
        }
        else{
            //choose as 1
            enQueue(queue,doTheThing(arr[operidx-1],arr[operidx+1],oper[operidx]));
            BT(queue,operidx+2,1);
            deQueue_back(queue);
            //choose as 0
            enQueue(queue,arr[operidx-1]);
            enQueue(queue,oper[operidx]);
            BT(queue,operidx+2,0);
            deQueue_back(queue);
            deQueue_back(queue);
        }
    }

}

void read(){
    for(int i = 0 ; i < N ; i ++){
        if(i%2==0){
            scanf("%d",&arr[i]);
        }
        else{
            scanf("%c",&oper[i]);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        scanf("%d",&N);
        read();
        ans=-__INT32_MAX__-1;
        Queue queue;
        queueInit(&queue);

        BT(&queue,1,0);

        printf("%d\n",ans);
    }
    /*
    scanf("%d",&N);
    read();
    ans=0;
    Queue queue;
    queueInit(&queue);
    BT(&queue,1,0);
    printf("%d\n",ans);
    */
    return 0;
}