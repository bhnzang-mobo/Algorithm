#pragma warning(disable:4996)
#include <iostream>
int N, T;
int arr[300][2]; // 0 : 들어갔는지 1: 현재 위치 2: 목표 위치
void read() {
	scanf("%d", &N);
	int from, to;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &from, &to);
		if (from > to) {
			from ^= to;
			to ^= from;
			from ^= to;
		}
		arr[(from-1)/2][0]++;
		arr[(to-1)/2][1]--;
	}
}

void init() {
	for (int i = 0; i < 300; i++) {
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
}
int calTime() {
	int max = 0;
	int val = 0;
	for (int i = 0; i < 300; i++) {
		if (arr[i] != 0) {
			val += arr[i][0];
			if (max < val) max = val;
			val += arr[i][1];
		}
	}
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		init();
		read();
		printf("#%d %d\n", i + 1, calTime());
	}
	return 0;
}
