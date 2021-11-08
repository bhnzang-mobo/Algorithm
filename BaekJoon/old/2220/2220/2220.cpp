#pragma warning(disable : 4996)
#include <iostream>

int N;
typedef struct heap{
	int arr[100001];
	int numOfEle;
}Rheap;

void heapInit(Rheap* hp) {
	hp->arr[N] = 1;
	hp->numOfEle = 1;
}

void heapInsert(Rheap* hp, int data) {
	hp->arr[1] = data;
	hp->arr[++hp->numOfEle] = 1;
	int idx = hp->numOfEle;
	int rt = idx / 2;
	while (rt>0) {
		hp->arr[idx] = hp->arr[rt];
		idx = rt;	
		rt /= 2;
	}
	hp->arr[1] = 1;
}


int main()
{
	scanf("%d", &N);
	heap hp;
	heapInit(&hp);
	for (int i = 2; i < N; i++) {
		heapInsert(&hp, i);
	}
	hp.arr[1] = N;
	hp.arr[N] = 1;
	for (int i = 1; i <=N; i++) {
		printf("%d ", hp.arr[i]);
	}

	return 0;
}

