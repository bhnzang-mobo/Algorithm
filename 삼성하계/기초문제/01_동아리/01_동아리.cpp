#pragma warning(disable:4996)
#include <iostream>
#define DIV 1000000007
int N;
unsigned long long arrdp[10001][20];

int play() {
	char ch;
	scanf("%c", &ch);
	int idx = 1;

	ch -= 'A';
	int tmp = 1 << (3 - ch);
	tmp |= 1 << 3;
	for (int i = 1; i < 16; i++) {
		if ((i&tmp)==tmp) {
			arrdp[idx][i] = 1;
		}
	}
	idx++;
	scanf("%c", &ch);

	while ('A'<=ch && ch<='Z') {
		ch -= 'A';
		int tmp = 1 << (3 - ch);
		for (int i = 1; i < 16; i++) {
			if (i&tmp) {
				unsigned long long ret = 0;
				for (int j = 1; j < 16; j++) {
					if (i&j) {
						ret += arrdp[idx - 1][j];
						ret %= DIV;
					}
				}
				arrdp[idx][i] = ret;
			}
		}
		idx++;
		scanf("%c", &ch);
	}
	return idx-1;
}
void init() {
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < 16; j++) {
			arrdp[i][j] = 0;
		}
	}
}
unsigned long long calRet(int idx) {
	unsigned long long ret = 0;
	for (int i = 1; i < 16; i++) {
		ret += arrdp[idx][i];
	}
	return ret % DIV;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		init();
		int idx = play();
		printf("#%d %llu\n", i + 1, calRet(idx));
	}


	return 0;
}
