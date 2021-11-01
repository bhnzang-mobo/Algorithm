#pragma warning(disable:4996)
#include <iostream>
using namespace std;
char arr[300];
void init() {
	for (int i = 0; i < 300; i++) {
		arr[i] = -1;
	}
}
void read() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int idx; char ch;
		scanf("%d %c", &idx, &ch);//입력
		arr[idx] = ch;//처리
		if (2 * idx <= N) {//왼쪽 노드 존재
			if (2 * idx + 1 <= N) {//오른쪽 노드 존재
				int tmp1, tmp2;
				scanf("%d %d", &tmp1, &tmp2);
			}
			else {
				int tmp1;//오른쪽 노드 존재 안함
				scanf("%d", &tmp1);
			}
		}
	}
}

void inorder_trav(int idx) {
	if (arr[idx] != -1) {
		inorder_trav(2 * idx);
		printf("%c", arr[idx]);
		inorder_trav(2 * idx + 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	for (int i = 1; i <= 10; i++) {
		printf("#%d ", i);
		init();
		read();
		inorder_trav(1);
		printf("\n");
	}
	return 0;
}
