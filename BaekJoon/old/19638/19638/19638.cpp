#pragma warning(disable:4996)
#include <iostream>

typedef struct heap {
	int numOfElement;
	int* arr;
	int(*comp)(int, int);
}heap;

void init(heap* hp, int size, int(*comp)(int, int)) {
	hp->comp = comp;
	hp->arr = (int*)malloc(sizeof(int)*size);
	hp->numOfElement = 0;
}

void heapInsert(heap* heap, int val) {
	int des = heap->numOfElement + 1;
	while (des >= 2) {
		int rt = des / 2;
		if (heap->comp(val, heap->arr[rt])) {
			heap->arr[des] = heap->arr[rt];
			des = rt;
		}
		else {
			break;
		}
	}
	heap->arr[des] = val;
	heap->numOfElement++;
}

int heapDelete(heap* hp) {
	int idx = 1;
	int delnode = hp->arr[1];
	while (idx<=hp->numOfElement/2) {
		int child;
		if (idx * 2 == hp->numOfElement) child = 2 * idx;
		else child = hp->comp(hp->arr[2 * idx], hp->arr[2 * idx + 1]) ? 2 * idx : 2 * idx + 1;

		if (hp->comp(hp->arr[child], hp->arr[hp->numOfElement])) {
			hp->arr[idx] = hp->arr[child];
			idx = child;
		}
		else {
			break;
		}
	}
	hp->arr[idx] = hp->arr[hp->numOfElement--];
	return delnode;
}

int isHeapEmpty(heap* hp) {
	if (hp->numOfElement <= 0) return 1;
	return 0;
}

int comp(int a, int b) {
	if (a >= b) return 1;
	return 0;
}
int N, H, T;
void read(heap* hp) {
	scanf("%d %d %d", &N, &H, &T);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		heapInsert(hp, tmp);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	heap myheap;
	init(&myheap, 100010, comp);
	read(&myheap);
	int time = 0;
	for (; time < T; time++) {
		int ret = heapDelete(&myheap);
		if (ret == 1 || ret<H) break;
		ret /= 2;
		heapInsert(&myheap, ret);
	}
	int tallest = heapDelete(&myheap);
	if (H > tallest) {
		printf("YES\n%d",time);
	}
	else {
		printf("NO\n%d", tallest);
	}
	return 0;
}
