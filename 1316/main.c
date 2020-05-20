#include <stdio.h>

int isGroup(char* buf){
    char C='a';
    int idx=0;
    short app[27]={0,};
    C=buf[idx];
    int idx2 = buf[idx]-97;
    app[idx2]=1;
    while(C!='\0'){
        C=buf[idx];
        while(C==buf[idx]){
            idx++;
        }
        if(buf[idx]=='\0') return 1;
        int idx2 = buf[idx]-97;
        if(!app[idx2]){
            app[idx2]=1;
        }
        else return 0;
    }
    
}

int main(){
    int num;
    int ret=0;
    char buf [110]={'\0',};
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i++){
        scanf("%s",buf);
        ret+=isGroup(buf);
    }
    printf("%d",ret);
    return 0;
}