#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
int map[302][302];
int arr[302][302];
int visit[302][302];
int N;
int dir_x[] = { -1,-1,0,1,1,1,0,-1 }; //북부터 시계방향
int dir_y[] = { 0,1,1,1,0,-1,-1,-1 };
int dir = 8;
int numOfBomb;
void init() {
	for (int i = 0; i < 302; i++) {
		for (int j = 0; j < 302; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	numOfBomb = 0;
}
int DFS(int x,int y) {//방문한 적 없는 map[x][y]== 0
	queue<pair<int, int>> myqueue;
	visit[x][y] = 1;
	myqueue.push(make_pair(x, y));
	int ret = 0;
	while (!myqueue.empty()) {
		ret++;
		pair<int, int> tmp;
		tmp = myqueue.front();
		myqueue.pop();
		if (map[tmp.first][tmp.second] == 0) {
			//폭탄자리 방문하는가?
			//
			for (int i = 0; i < dir; i++) {
				int dest_x = tmp.first + dir_x[i];
				int dest_y = tmp.second + dir_y[i];
				if (visit[dest_x][dest_y] == 0 && map[dest_x][dest_y] >= 0) {
					visit[dest_x][dest_y] = 1;
					myqueue.push(make_pair(dest_x, dest_y));
				}
			}
		}
	}
	return ret;
}
void read() {
	scanf("%d", &N);
	char c;
	scanf("%c", &c);//줄바꿈
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c ", &c);
			if (c == '*') {
				numOfBomb++;
				map[i][j] = -99;
				for (int d = 0; d < 8; d++) {
					int dest_x = i + dir_x[d];
					int dest_y = j + dir_y[d];
					map[dest_x][dest_y]++;
				}
			}
		}
	}
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = -1;
		map[0][i] = -1;
		map[N + 1][i] = -1;
		map[i][N + 1] = -1;
	}
}
int play() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == 0 && map[i][j] == 0) {
				ret+=DFS(i, j)-1; //클릭한 횟수를 계산하기위해 매번 1을 빼준다
			}
		}
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int testcase;
	scanf("%d",&testcase);
	for (int i = 1; i <= testcase; i++) {
		init();
		read();
		printf("#%d %d\n",i, N*N-play()-numOfBomb);
	}

	return 0;
}
