#include <stdio.h>
#include <malloc.h>
int X;
int * arr;
int min(int a,int b){
    return (a<b?a:b);
}
void dp(){
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i = 4 ; i <=X ; i ++){
        int count =0;
        if(i%3==0){
            count+=1;
        }
        if(i%2==0){
            count+=2;
        }
        switch (count)
        {
        case 1:
            arr[i]=min(arr[i/3],arr[i-1])+1;
            break;
        case 2:
            arr[i]=min(arr[i/2],arr[i-1])+1;
            break;
        case 3:
            arr[i]=min(arr[i/2],min(arr[i/3],arr[i-1]))+1;
            break;
        default:
          arr[i]=arr[i-1]+1;
            break;
        }
    }

}
int main(){
    scanf("%d",&X);
    arr = (int*)malloc(sizeof(int)*X+1);
    dp();
    printf("%d",arr[X]);
    return 0;
}