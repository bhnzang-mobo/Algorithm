#pragma warning(disable:4996)
#include <iostream>


char digit[101];
int arr[100][100];
int visit[100][100];

void init() {
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j < 100; j++) {
			int ret = i * j;
			while (ret % 10 == 0) {
				ret /= 10;
			}
			arr[i][j] = ret%100;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	init();
	char d;
	int num = 0;
	while (scanf("%c", &d) == 1) {
		digit[num++] = d - '0';
	}
	int fib = 1;
	for (int i = 2; i < 99; i++) {
		visit[fib][i] = 1;
		printf("%d ", fib);
		fib = (fib*i) % 100;
		while (fib%100 == 0) {
			fib /= 10;
		}
		if (visit[i+1][fib] == 1) {
			printf("last word : %d * %d ", fib,i+1);
			break;
		}
	}

	return 0;

}
