#pragma warning(disable:4996)
#include <iostream>
using namespace std;
char inp[2][1001];
int arr[1001][1001];// 0: 위치, 1:길이

int len1, len2;
void read() {
	char tmp;
	scanf("%c", &tmp);
	len1 = 0;
	while ('a' <= tmp && tmp <= 'z') {
		inp[0][len1++] = tmp;
		scanf("%c", &tmp);
	}
	scanf("%c", &tmp);
	len2 = 0;
	while ('a' <= tmp && tmp <= 'z') {
		inp[1][len2++] = tmp;
		if (scanf("%c", &tmp) < 0) break;
	}

}

int max(int a, int b) {
	return a > b ? a : b;
}

void dp() {
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (inp[0][i-1] == inp[1][j-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	
}
void init() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			arr[i][j] = 0;
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d ", &T);
	for (int i = 1; i <= T; i++) {
		init();
		read();
		dp();
		printf("#%d %d", i, arr[len1][len2]);
	}
	return 0;
}
