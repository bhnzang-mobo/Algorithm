#pragma warning(disable:4996)
#include <iostream>

char name[20001][55];
int idx[20001];
int tmp[20001];

int N;

int comp(char* a, char* b) {
	char* A = a;
	char* B = b;
	if (strlen(a) < strlen(b)) return 0; //길이에 대한 우선순위가 빠졌었음.
	else if (strlen(a) > strlen(b)) return 1;
	while (*A && *B) {
		if (*A > *B) {
			return 0;
		}
		else if( *A<*B) {
			return 1;
		}
		A++; B++;
	}
	if (*A) return 0;
	if (*B) return 1;
}

void merge(int s, int m, int e) {
	if (s >= e) return;
	int lhand = s;
	int rhand = m + 1;
	int cur = lhand;
	while (lhand <= m && rhand <= e) {
		if (comp(name[idx[lhand]], name[idx[rhand]])) {
			tmp[cur++] = idx[lhand++];
		}
		else {
			tmp[cur++] = idx[rhand++];
		}
	}

	while (lhand <= m) {
		tmp[cur++] = idx[lhand++];
	}

	while (rhand <= e) {
		tmp[cur++] = idx[rhand++];
	}

	for (int i = s; i <= e; i++) {
		idx[i] = tmp[i];
	}
}
void mergeSort(int s, int e) {
	if (s < e) {
		int  m = (s + e) / 2;
		mergeSort(s, m);
		mergeSort(m+1, e);
		merge(s, m, e);
	}

}

void read() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		idx[i] = i;
		scanf("%s", name[i]);
	}
}



void printAll() {
	printf("%s\n", name[idx[0]]);
	for (int i = 1; i < N; i++) {
		if(strcmp(name[idx[i-1]], name[idx[i]])) printf("%s\n", name[idx[i]]);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		read();
		mergeSort(0, N - 1);
		printf("#%d\n", i);
		printAll();
	}
	return 0;
}
