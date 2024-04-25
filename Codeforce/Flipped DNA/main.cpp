#include <stdio.h>
#include <math.h>

void init(){
    freopen("input.txt","r",stdin);
}

char arr[2][100001];

int main(){
    int n;
    char tmp;
    scanf("%d",&n);
    scanf(" %[A-Z]s",arr[0]);
    scanf(" %[A-Z]s",arr[1]);
    
    for(int i = 0 ; i < n ; i ++){
        if(!(
            abs(arr[0][i]-arr[1][i])==0||
            abs(arr[0][i]-arr[1][i])==19||
            abs(arr[0][i]-arr[1][i])==4
            )){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}