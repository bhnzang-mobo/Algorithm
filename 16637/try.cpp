#include <stdio.h>
#include <string.h>
#include <malloc.h>

int N;
int arr[20];
char oper[20];
int plus(int a,int b){
    return a+b;
}
int minus(int a,int b){
    if(a==25 && b==-8){
    }
    return a-b;
}
int multi(int a,int b){
    return a*b;
}
int(*doTheThing[3])(int,int)={plus,minus,multi};

int whichoper(int operidx){
    switch (operidx)
    {
    case 43:
        return 0;
    case 42:
        return 2;
    case 45:
        return 1;
    default:
    return -1;
        break;
    }
}
int ans;

void BT(int operidx,int pass){
    if(N==1){
        ans=arr[0];
        return;
    }
    if(operidx>N-2){
        int operand = whichoper(oper[N-2]);
        int ret = doTheThing[operand](pass,arr[N-1]);
        if(ans < ret){
            ans=ret;
        }
        return;
    }
    else if(operidx==N-2){
        int operand = whichoper(oper[N-4]);
        int operand2 = whichoper(oper[N-2]);

        int pass2 = doTheThing[operand](pass,arr[N-3]);
        int ret = doTheThing[operand2](pass2,arr[N-1]);
        if(ans < ret){
            ans=ret;
        }
        pass2 = doTheThing[operand2](arr[N-3],arr[N-1]);
        ret= doTheThing[operand](pass,pass2);
        if(ans < ret){
            ans=ret;
        }
        return;
    }
    else{
        int operand = whichoper(oper[operidx-2]);
        int pass2 = doTheThing[operand](pass,arr[operidx-1]);
        BT(operidx+2,pass2);
        int operand2= whichoper(oper[operidx]);
        pass2 = doTheThing[operand2](arr[operidx-1],arr[operidx+1]);
        int pass3 = doTheThing[operand](pass,pass2);
        BT(operidx+4,pass3);
        return;
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

        BT(3,arr[0]);
        int operand = whichoper(oper[1]);
        if(N>=4){
            BT(5,doTheThing[operand](arr[0],arr[2]));
        }

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