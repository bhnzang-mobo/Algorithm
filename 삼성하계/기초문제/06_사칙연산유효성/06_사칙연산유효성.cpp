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
	bool isChar;
	pool* child;
}tree[1001];

void init() {
	numOfPool = 0;
	for (int i = 0; i < 1001; i++) {
		tree[i].child = nullptr;
		tree[i].parent = -1;
		tree[i].isChar = false;
	}
}

void insert(int parent, int child) {
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

			if (op == '+' || op == '-' || op == '*' || op == '/')tree[par].isChar = true;

		}
		else {
			int par = atoi(strtok(inp, " "));
			int num = atoi(strtok(NULL, " "));
		}
	}
}

int cal(int node) {
	if (tree[node].child == nullptr) return 1;

	int pos = 1;
	if (tree[node].isChar) return cal(tree[node].child->id)*cal(tree[node].child->prev->id);
	else return 0;

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
