#pragma warning(disable:4996)
#include <iostream>
int T, N;
int app[10];

bool isComplete() {
	for (int i = 0; i < 10; i++) {
		if (app[i] == 0) return false;
	}
	return true;
}
void visit(int num) {
	while (num != 0) {
		app[num % 10] = 1;
		num /= 10;
	}
}
void init() {
	for (int i = 0; i < 10; i++) {
		app[i] = 0;
	}
}
int play() {
	scanf("%d", &N);
	int num = N;
	while (!isComplete()) {
		visit(num);
		num += N;
	}
	return num-N;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		init();
		printf("#%d %d\n",i+1,play());
	}
	return 0;
}
