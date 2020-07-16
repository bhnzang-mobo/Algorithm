#include <stdio.h>
#include "graphKruskal.h"

int main(){
    ALGraph al;
    int H,V,W;
    scanf("%d %d",&H,&V);
    GraphInit(&al,H*V);
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < V-1 ; j++){
            scanf("%d",&W);
            AddEdge(&al,V*i+j,V*i+j+1,W);
        }
    }
    for(int i = 0 ; i < H-1 ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d",&W);
            AddEdge(&al,V*i+j,V*(i+1)+j,W);
        }
    }
    
    printf("Depth First Search\n");
    DFS(&al,1);
    ShowGraphInfo(&al);
    printf("\nConstitue Kruskal\n");
    ConKruskal(&al);
    ShowGraphInfo(&al);
    return 0;
}