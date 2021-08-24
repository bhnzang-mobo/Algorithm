#pragma warning(disable : 4996)
#include <iostream>
#define PAY 8
int N;
int pay[] = { 50000,10000,5000,1000,500,100,50,10 };
int ways[8];
void read() {
	int charges;
	scanf("%d", &charges);
	for (int i = 0; i < PAY; i++) {
		ways[i] = charges / pay[i];
		charges %= pay[i];
	}
}

void ans() {
	for (int i = 0; i < 8; i++) {
		printf("%d ", ways[i]);
	}
	printf("\n");
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		read();
		printf("#%d\n", i + 1);
		ans();
	}
	return 0;
}
