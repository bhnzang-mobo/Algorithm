#include <stdio.h>


int main(){
    char C;
    int ret=0;
    int idx=0;
    char buf[120]={'\0',};
    scanf("%[a-z-=]",buf);
    C=buf[idx++];
    while(C!='\0'){
        if(C=='c'){
            C=buf[idx++];
            if(C=='=') C=buf[idx++];
            if(C=='-') C=buf[idx++];
        }
        else if(C=='d'){
            C=buf[idx++];
            if(C=='z'){
                C=buf[idx++];
                if(C=='=') C=buf[idx++];
                else ret++;//if alpha is not dz=, dz is two alpha. For that case, we have to define instruction.
            }
            else if(C=='-') C=buf[idx++];
        }
        else if(C=='l'){
            C=buf[idx++];
            if(C=='j') C=buf[idx++];
        }
        else if(C=='n'){
            C=buf[idx++];
            if(C=='j') C=buf[idx++];
        }
        else if(C=='s'){
            C=buf[idx++];
            if(C=='=') C=buf[idx++];
        }
        else if(C=='z'){
            C=buf[idx++];
            if(C=='=') C=buf[idx++];
        }
        else{
            C=buf[idx++];
        }
        ret++;
    }
    printf("%d",ret);
    return 0;
}