#pragma warning(disable:4996)
#include <iostream>

int dparr[101][1001];
int arr[110][2];
int N, C;
void read() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		int tmp_n, tmp_c;
		scanf("%d %d", &tmp_n, &tmp_c);
		arr[i][0] = tmp_n;//부피
		arr[i][1] = tmp_c;//가치
	}
}
void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 1000; j++) {
			dparr[i][j] = 0;
		}
	}
}

void dp() {
	for (int i = 0; i <= C; i++) {
		if (i >= arr[0][0]) dparr[0][i] = arr[0][1];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= C; j++) {
			if (j >= arr[i][0]) {
				dparr[i][j] = dparr[i - 1][j - arr[i][0]] + arr[i][1] > dparr[i - 1][j] ? dparr[i - 1][j - arr[i][0]] + arr[i][1] : dparr[i - 1][j];
			}
			else {
				dparr[i][j] = dparr[i - 1][j];
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		init();
		read();
		dp();
		printf("#%d %d\n", i, dparr[N - 1][C]);
	}
}
