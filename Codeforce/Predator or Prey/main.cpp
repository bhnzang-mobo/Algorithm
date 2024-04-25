#include <stdio.h>
#include <malloc.h>

int myarr[2][200001];
int ret[2][200001];
int n,a,b;
void mergeSort(int arr[][200001], int start,int end,int x){
    if(start==end){
        return;
    }
    int lhand=start;
    int mid =(start+end)/2;
    int rhand=mid+1;
    mergeSort(arr,lhand,mid,x);
    mergeSort(arr,rhand,end,x);
    int tmpidx=0;
    int * tmparr_idx =(int*)malloc(sizeof(int)*(end-start+1));
    int * tmparr = (int*)malloc(sizeof(int)*(end-start+1));
    while(lhand<= mid && rhand <= end){
        if(arr[x][lhand]<arr[x][rhand]) tmparr[tmpidx]=arr[1][lhand], tmparr_idx[tmpidx++]=arr[0][lhand++];
        else tmparr[tmpidx]=arr[1][rhand], tmparr_idx[tmpidx++]=arr[0][rhand++];
    }

    while(lhand<= mid ){
        tmparr[tmpidx]=arr[1][lhand];
        tmparr_idx[tmpidx++]=arr[0][lhand++];
    }

    while(rhand <= end){
        tmparr_idx[tmpidx]=arr[0][rhand];
        tmparr[tmpidx++]=arr[1][rhand++];
    }
    for(int i = 0 ; i < end-start+1 ; i ++){
        arr[0][start+i]=tmparr_idx[i];
        arr[1][start+i]=tmparr[i];
    }
    free(tmparr);
}

void init(){
    scanf("%d %d %d",&n, &a, &b);
    for(int i = 0 ; i < n ; i ++){
        myarr[0][i]=i;
        scanf("%d", &myarr[1][i]);
    }
}
int binaryIdx(int x, int start, int end){//x 초과 중 가장 작은 수의 인덱스
    while(start<=end){
        if(myarr[1][(start+end)/2] <= x){
            start=(start+end)/2+1;
        }
        else{
            end=(start+end)/2-1;
        }
    }
    return start;
}


void binarySearch(){
    for(int i = 0 ; i < n ; i ++){//p+a 이상 p+b 미만
        ret[0][myarr[0][i]]=binaryIdx(myarr[1][i]+b-1,i,n-1)-binaryIdx(myarr[1][i]+a-1,i,n-1);
    }
    for(int i = 0 ; i < n ; i ++){//p-b초과 p-a 이하
        ret[1][myarr[0][i]]=binaryIdx(myarr[1][i]-a,0,i)-binaryIdx(myarr[1][i]-b,0,i);
    }
}

int main(){
    init();
    mergeSort(myarr,0,n-1,1);
    binarySearch();
    mergeSort(myarr,0,n-1,0);
    for(int i = 0 ; i < n ; i ++){
        printf("%d %d\n",ret[0][i],ret[1][i]);
    }
}