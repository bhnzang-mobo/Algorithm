#include <stdio.h>
int isAlpha(char c){
    if((65<=c && c<=90) || (97<=c && c<=122)){
        return 1;
    }
    return 0;
}

int main (){
    char C;
    int ret = 0;
    int flag =0; //Indicate whether C is part of word or not.
    scanf("%c",&C);
    while(C!=10){
        if(flag==0){ //When C is not part of word
            if(isAlpha(C)){
                flag+=1;
                ret+=1;
            }
        }
        else{//When we are reading C as a part of word
            if(C==32){
                flag=0; //If blank came out, that is the end of word. flag reset.
            }
        }
        scanf("%c",&C);
    }
    printf("%d",ret);
    return 0;
}