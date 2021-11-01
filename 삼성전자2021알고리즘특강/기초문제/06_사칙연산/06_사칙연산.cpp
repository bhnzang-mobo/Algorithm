#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;
int numOfPool;
struct pool {
	int id;
	struct pool * prev;
}listPool[1001];

struct treeNode {
	int parent;
	int data;
	pool* child;
}tree[1001];

void init() {
	numOfPool = 0;
	for (int i = 0; i < 1001; i++) {
		tree[i].child = nullptr;
		tree[i].parent = -1;
	}
}

void insert(int parent,int child) {
	pool* tmp = &listPool[numOfPool++];

	tmp->id = child;
	tmp->prev = tree[parent].child;

	tree[parent].child = tmp;
	tree[child].parent = parent;
}

int numOfChar(char * inp) {
	int cnt = 1;
	while (*inp != '\n') {
		if (*inp == ' ') cnt++;
		inp++;
	}
	return cnt;
}

void read() {
	int N;
	scanf("%d ", &N);
	char inp[100], sp[100];
	for (int i = 0; i < N; i++) {
		fgets(inp, 100, stdin);
		if (numOfChar(inp) == 4) {
			int par = atoi(strtok(inp, " "));
			char op = strtok(NULL, " ")[0];
			int child1 = atoi(strtok(NULL, " "));
			int child2 = atoi(strtok(NULL, " "));
			insert(par, child1);
			insert(par, child2);
			tree[par].data = op;

		}
		else {
			int par = atoi(strtok(inp, " "));
			int num = atoi(strtok(NULL, " "));
			tree[par].data = num;
		}
	}
}

float cal(int node) {
	if (tree[node].child == NULL) return tree[node].data;

	float right = cal(tree[node].child->id);
	float left = cal(tree[node].child->prev->id);
	if (tree[node].data == '+') {
		return left + right;
	}
	else if (tree[node].data == '-') {
		return left - right;
	}
	else if (tree[node].data == '*') {
		return left * right;
	}
	else {
		return left / right;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		init();
		read();
		printf("#%d %d\n", i, (int)cal(1));
	}
	return 0;
}
