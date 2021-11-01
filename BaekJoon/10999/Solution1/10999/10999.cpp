#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
long long int arr[1000001];
queue<pair<int, long long int>> myqueue;

void read() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		myqueue.push(make_pair( i + 1, arr[i]));
	}
}

void makeFW() {
	while (myqueue.size()>=2) {
		pair<int, long long int> tmp1 = myqueue.front();
		myqueue.pop();
		pair<int, long long int> tmp2 = myqueue.front();
		myqueue.pop();
		int idx = tmp1.first > tmp2.first ? tmp1.first : tmp2.first;
		arr[idx] = tmp1.second + tmp2.second;
		myqueue.push(idx, arr[idx]);
	}
}
void play() {

}
int main()
{
	read();
	return 0;
}
