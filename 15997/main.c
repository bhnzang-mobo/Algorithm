#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct __game{
    char A[11];
    char B[11];
    double WDL[4];
}game;

char team[4][12];//team name
game arr[7];//6 gamse occur
double win[5];//winning probability
double pos[1000][4];//all occasion
int whoiswinner[4];
int whoIsWinner(int team_score[],int sit_idx,double prob){
    int First=0;
    int first_val=-1;
    int Second=0;
    int second_val=-1;
    int f_idx[4];
    int numOfFirst=0;
    int numOfSecond=0;
    int s_idx[4];
    for(int i = 0 ; i < 4 ; i ++){
        if(team_score[i]>first_val){
            First=i;
            first_val=team_score[First];
        }
    }
    for(int i = 0 ; i < 4 ; i ++){
        if(team_score[i]>second_val&&team_score[First]>team_score[i]){
            Second=i;
            second_val=team_score[Second];
        }
    }
    int tmp=0,tmp2=0;
    for(int i = 0 ; i < 4 ; i ++){
        if(team_score[First]==team_score[i]){
            numOfFirst+=1;
            f_idx[tmp++]=i;
        }
        if(team_score[Second]==team_score[i]){
            numOfSecond+=1;
            s_idx[tmp2++]=i;
        }
    }
    
    if(numOfFirst==1){
        if(numOfSecond==1){
            pos[sit_idx][f_idx[0]]=prob;
            pos[sit_idx][s_idx[0]]=prob;
        }
        if(numOfSecond==2){
            pos[sit_idx][f_idx[0]]=prob;
            pos[sit_idx][s_idx[0]]=prob/2.0;
            pos[sit_idx][s_idx[1]]=prob/2.0;
        }
        if(numOfSecond==3){
            pos[sit_idx][f_idx[0]]=prob;
            pos[sit_idx][s_idx[0]]=prob/3.0;
            pos[sit_idx][s_idx[1]]=prob/3.0;
            pos[sit_idx][s_idx[2]]=prob/3.0;
        }
    }
    if(numOfFirst==2){
        pos[sit_idx][f_idx[0]]=prob;
        pos[sit_idx][f_idx[1]]=prob;
    }
    if(numOfFirst==3){
        pos[sit_idx][f_idx[0]]=prob*2/3.0;
        pos[sit_idx][f_idx[1]]=prob*2/3.0;
        pos[sit_idx][f_idx[2]]=prob*2/3.0;
    }
    if(numOfFirst==4){
        pos[sit_idx][f_idx[0]]=prob/2.0;
        pos[sit_idx][f_idx[1]]=prob/2.0;
        pos[sit_idx][f_idx[2]]=prob/2.0;
        pos[sit_idx][f_idx[3]]=prob/2.0;
    }
    
}

int teamIdx(char name[]){
    for(int i = 0 ; i < 4; i ++){
        if(!strcmp(name,team[i])){
        return i;
        }
    }
}
int convert(int digit[6]){
    int op=1;
    int ret=0;
    for(int i = 0 ; i < 6 ; i ++){
        ret+=digit[i]*op;
        op*=3;
    }
    return ret;
}
void winProbCal(int digit[]){
    double prob=1.0;
    int team_score[4]={0,};
    for(int i = 0 ; i < 6 ; i ++){
        switch (digit[i])
        {
            int idx;
        case 0:
            idx = teamIdx(arr[i].A);
            team_score[idx]+=3;
            prob*=arr[i].WDL[0];
            break;
        
        case 1:
            idx = teamIdx(arr[i].A);
            team_score[idx]+=1;
            idx = teamIdx(arr[i].B);
            team_score[idx]+=1;
            prob*=arr[i].WDL[1];
            break;
        
        case 2:
            idx = teamIdx(arr[i].B);
            team_score[idx]+=3;
            prob*=arr[i].WDL[2];
            break;
        default:
            break;
        }
    }
    int sit_idx=convert(digit);
    whoIsWinner(team_score,sit_idx,prob);
    
}

int digitCheck(int digit[], int check[]){
    for(int i = 0 ; i < 6 ; i ++){
        if(digit[i]!=check[i]){
            return 0;
        }
    }
    return 1;
}
void cal(int op,int digit[]){
    if(op<0){
        return;
    }
    if(op==0){
        int check[6]={0,0,2,2,0,2};

        digit[op]=0;

        winProbCal(digit);
        digit[op]=1;

        winProbCal(digit);
        digit[op]=2;

        winProbCal(digit);
        return;
    }
    digit[op]=0;
    cal(op-1,digit);
    digit[op]=1;
    cal(op-1,digit);
    digit[op]=2;
    cal(op-1,digit);
}

int main(){
    scanf("%s %s %s %s",team[0],team[1],team[2],team[3]);
    for(int i = 0 ; i < 6 ; i ++){
        scanf("%s %s %lf %lf %lf",arr[i].A,arr[i].B,&arr[i].WDL[0],&arr[i].WDL[1],&arr[i].WDL[2]);
    }
    int digit[7];
    memset(digit,0,sizeof(digit));
    cal(5,digit);
    double ret[4]={0,};
    for(int i = 0 ; i <= (int)pow(3,6); i ++){
        for(int j = 0 ; j <4 ; j ++){
            ret[j]+=pos[i][j];
        }
    }  
    for(int i = 0 ; i < 4 ; i ++){
        printf("%.18lf\n",ret[i]);
    }
    return 0;
}