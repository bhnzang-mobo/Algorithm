#include <iostream>
using namespace std;
int T,N;
int arr[12][12];

void read(){
    cin >> T;
    for(int i = 0 ; i < T ; i ++){
        cin >> N;
        for(int j = 0 ; j < N ; j ++){
            for(int k = 0 ; k < N ; k ++){
                cin >> arr[j][k];
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    read();

    return 0;
}