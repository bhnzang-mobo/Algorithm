#pragma warning(disable:4996)
#include <iostream>
int N, K;
int bits[1001][2];
int pattern[1001][2];
int arr[1001];
void read() {
	scanf("%d %d", &N, &K);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", arr+i);
		if (arr[i] & 1)bits[i%K][0]++;//짝수로 만들기 위해 변경이 필요한 비트 수
		else bits[i%K][1]++;//홀수로 만들기 위해 - -
	}
}
int min(int a, int b) {
	if (a < b) return a;
	return b;
}
void dp() { //bits[i][0] : i번째까지 짝합을 만들기 위한 최소 비트 변경 횟수, 1: 홀합을 만들기 위한 치소 변경 횟수
	for (int i = 1; i < K; i++) {
		int even, odd;
		if (bits[i][0] + bits[i - 1][0] > bits[i][1] + bits[i - 1][1]) {
			even = bits[i][1] + bits[i - 1][1];
			pattern[i][0] = 1;
		}
		else {
			even = bits[i][0] + bits[i - 1][0];
			pattern[i][0] = 0;
		}

		if (bits[i][0] + bits[i - 1][1] > bits[i][1] + bits[i - 1][0]) {
			odd = bits[i][1] + bits[i - 1][0];
			pattern[i][1] = 0;
		}
		else {
			odd = bits[i][0] + bits[i - 1][1];
			pattern[i][1] = 1;
		}
		bits[i][0] = even;
		bits[i][1] = odd;
	}
}
int solve() {
	int ret = bits[K - 1][0];
	int from = 0;
	int to = pattern[K - 1][from];
	for (int i = K - 2; i >= 0; i--) {
		pattern[i + 1][0] = from ^ to;
		from = to;
		to = pattern[i][from];
	}
	pattern[0][0] = from ^ to;
	printf("%d\n", ret);
	return ret;
}
int main()
{
	freopen("input.txt","r",stdin);
	read();
	dp();
	solve();
	for (int i = 0; i < N; i++) {
		if ((arr[i]&1)^pattern[i%K][0]) {
			arr[i]++;
		}
		printf("%d ", arr[i]);
	}
	
	return 0;
}

