#pragma warning(disable:4996)

#include <iostream>
int N, M;

bool play() {
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; i ++) {
		if ((M & 1) ==0) {
			return false;
		}
		M >>= 1;
	}
	return true;
}
int main()
{
	int T;
	freopen("input.txt", "r",stdin);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		if (play())printf("#%d ON\n", i + 1);
		else printf("#%d OFF\n", i + 1);
	}
	return 0;
}
