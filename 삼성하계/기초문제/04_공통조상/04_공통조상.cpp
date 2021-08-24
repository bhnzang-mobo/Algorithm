#pragma warning(disable:4996)
#include <iostream>

int map[10001][2]; // 이진트리 표기 방법
int visit[10001];
int s, e;
				   //1. 트리 노드를 사용
//2. 배열 인덱스를 활용. **
void init() {
	for (int i = 0; i < 10001; i++) {
		map[i][0] = 0;
		map[i][1] = 0;
		visit[i] = 0;
	}
}

void read() {
	int V, E;
	scanf("%d %d %d %d", &V, &E, &s, &e);
	for (int i = 0; i < E; i++) {
		int parent, child;
		scanf("%d %d", &parent, &child);
		map[parent][0] > 0 ? map[parent][1] = child : map[parent][0] = child;
	}
}

int traverse(int V_idx,int s, int e) {
	if (visit[V_idx]) return -1;
	int ret = 0;
	if (map[V_idx][0]) ret+=traverse(map[V_idx][0], s, e);
	if (V_idx == s) ret += 1;
	if (V_idx == e) ret += 2;
	if (map[V_idx][1]) ret+=traverse(map[V_idx][1], s, e);
	return ret;
}

int play() {
	int max = 0;
	for (int i = 0; i < 10001; i++) {
		if (map[i][0]) {
			if (traverse(i, s, e) == 3) {
				visit[i] = 1;
				max = i;
			}
		}
	}
	return max;
}

int height(int node) {
	int ret = 0;
	int left = 0;
	int right = 0;
	if (!(map[node][0] || map[node][1])) return 0;
	if (map[node][0]) left =1+ height(map[node][0]);
	if (map[node][1]) right =1+ height(map[node][1]);
	return left + right;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		read();
		int node = play();
		printf("#%d %d %d\n", i, node,1+height(node));
	}
	return 0;
}
