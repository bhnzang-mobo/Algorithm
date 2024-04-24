#include <stdio.h>
#include <vector>


using namespace std;



int main(){
    int n,prev;
    scanf("%d %d",&n,&prev);
    int ret=0;
    for(int i = 1 ; i < n ; i ++){
        int next;
        scanf("%d", &next);
        ret+=prev*next;
        prev=next;

    }
    printf("%d",ret);
}