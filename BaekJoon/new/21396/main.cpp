#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;


unordered_map<int,int> counter;
int arr[100001];
int N,x;
void init(){
    //자료구조를 초기화. 테스트케이스 횟수마다 초기화.
    //counter.erase(counter.begin(),counter.end());
    counter.clear();
}   

void read(){
    //한 테스트 케이스의 시작에서 호출. 입력을 받는다.
    scanf("%d %d",&N,&x);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&arr[i]);
        unordered_map<int,int>::iterator tmp;
        tmp = counter.find(arr[i]);
        if(tmp!=counter.end()){
            tmp->second++;
        }
        else{
            counter.insert({arr[i],1});
        }
    }
}

long long int count(){
    long long int ret=0;
    for(int i = 0 ; i < N-1 ; i ++){
        int target = arr[i]^x;
        counter.find(arr[i])->second-=1;
        unordered_map<int,int>::iterator tmp;
        tmp = counter.find(target);

        if(tmp!=counter.end()){
            ret += tmp->second;
        }
    }
    return ret;
}

int main( int argc, char * argv[] )
{
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i ++){
        init();
        read();
        printf("%lld ",count());
        printf("\n");
    }
    return 0;
}