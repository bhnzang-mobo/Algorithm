#define N 4
#include <iostream>
 

typedef struct {

           int strike;

           int ball;

} Result;

 
int num[11];//idx:number , 0:unknown, 1:Strik 2: Ball;
int myphone[4]={4,0,3,1};//ㅎㅅㅎ!!
Result res;

// API

extern Result query(int guess[]);
bool isIn(int guess[],int num){
    for(int i = 0 ; i < 4 ; i ++){
        if(guess[i]==num) return true;
    }
    return false;
}
int next_X(int guess[],int idx){
    int next_num = (guess[idx]+1)%10;
    for(int i = 1 ; i < 10 ; i ++){
        if(!isIn(guess,next_num)&&num[next_num]!=-1){
            return next_num;
        }
        next_num+=1;
        next_num%=10;
    }
    return -1;
}

int next_T(int guess[],int place [], int idx){

}

void reduceX(int guess[],int idx,int* numOfX){   
    Result q_before;
    while(1){
        int next_num=next_X(guess,idx);
        if(next_num==-1){
            return;
        }
        int g_before[4]={guess[0],guess[1],guess[2],guess[3]};
        guess[idx]=next_num;
        q_before=res;
        res=query(guess);
        int dO=res.strike-q_before.strike;
        int dT=res.ball-q_before.ball;
        int dX=-(dO+dT);
            if(dX==0){
                if(dO==-1){
                    num[g_before[idx]]=1;
                    num[guess[idx]]=2;
                }
                else if(dO==1){
                    num[g_before[idx]]=2;
                    num[guess[idx]]=1;
                }
                else if(dO==0) {//T->T, X->X both are possible
                    /*num[g_before[idx]]=-1;
                    num[guess[idx]]=-1;
                    */
                }
            }
                
            if(dX==1){
                if(dO==-1){
                    num[g_before[idx]]=1;
                    num[guess[idx]]=-1;
                }
                else if(dO==1){//Not possible dT should be..-2
                }
                else if(dO==0){//dT=-1
                    num[g_before[idx]]=2;
                    num[guess[idx]]=-1;
                }
                for(int i = 0 ; i < 4 ; i ++){//dx=1 is not good. restoration necessary.
                    guess[i]=g_before[i];
                }
                res=q_before;
                break;
            }
            if(dX==-1){
                *numOfX-=1;
                if(dO==-1){//not possible
                }
                else if(dO==1){//dT=0
                    num[g_before[idx]]=-1;
                    num[guess[idx]]=1;
                }
                else if(dO==0){//dT=1
                    num[g_before[idx]]=-1;
                    num[guess[idx]]=2;
                }
                    break;
            }
        }
}
void init(){
    for(int i = 0 ; i < 11 ; i ++){
        num[i]=0;
    }
}
void guess_switch(int guess[],int idx1, int idx2){
    int tmp = guess[idx1];
    guess[idx1]=guess[idx2];
    guess[idx2]=tmp;
}
void reduceT(int guess[],int place[],int *numOfO){
    Result q_before;
    while(1){
        int idx = 0;
        int g_before[4]={guess[0],guess[1],guess[2],guess[3]};
        q_before=res;
        guess_switch(guess,idx,idx+1);
        res=query(guess);

        int dO=res.strike-q_before.strike;
        if(dO==2){
            place[guess[idx]]=1;
            place[guess[idx+1]]=1;
            *numOfO+=2;
            break;
        }
        if(dO==1){
            place[guess[idx]]=1;

            place[guess[idx+1]]=1;
        }
        if(dO==0){
            place[guess[idx]]=-1;
            place[guess[idx+1]]=-1;
        }
    }
}
void doUserImplementation(int guess[]) {
    init();
    for(int i = 0 ; i< 4 ; i ++){
        guess[i]=myphone[i];
    }
    res=query(guess);

    int numOfX = 4-res.strike-res.ball;
    int i = 0;
    while(numOfX!=0){
        reduceX(guess,i++,&numOfX);
    }
    int place[10]={0,};
    int numOfO=0;
    for(int i = 0 ; i < 10 ; i ++){
        if(num[i]==1){
            place[i]==1;
            numOfO++;
        }
    }
    int numOfT = res.ball;
    i=0;
    if(numOfO==0){
        reduceT(guess,place,&numOfO);
    }
    return;
}