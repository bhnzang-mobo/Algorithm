#include <stdio.h>
#include <stdlib.h>

int left2(int fnum){
    if(fnum/100 >= 13 || fnum/100==0) return 2;
    else return 3;
}

int right2(int fnum){
    if(fnum%100 >=13 || fnum%100==0) return 5;
    else return 7;
}


int main(){
    int itr;
    scanf("%d",&itr);
    for(int i = 1 ; i<= itr; i++){
        int fnum;
        scanf("%d",&fnum);
        switch (left2(fnum)+right2(fnum))
        {
        case 7:
            printf("#%d NA\n",i);
            break;
        case 8:
            printf("#%d MMYY\n",i);
            break;
        case 9:
            printf("#%d YYMM\n",i);
            break;
        case 10:
            printf("#%d AMBIGUOUS\n",i);
            break;
        }
    }
    return 0;
}