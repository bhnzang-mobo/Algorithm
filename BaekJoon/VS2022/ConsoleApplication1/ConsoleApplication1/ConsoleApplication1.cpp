#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int map[22][22]; //N이 작기때문에 대충 N^3으로 돌려버릴 예정 ^^
int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,1,0,-1 };
int stud[401][401];//각 학생들마다 4명의 취향이 존재한다고하자 취향의 존재를 4번 반복해서 조회하고싶지만, 그냥 0과 10으로 표시해본다.
queue<int> prio;

int satisfy(int r, int c, int n) { //(r,c)에서 i 번 학생의 예상 만족도를 리턴.
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		//@@@ if (map[r][c] != 0)continue;  바깥으로 빼줘야함. 네 번 다 continue 되서 ret = 0 으로 리턴될 경우 문제가 있음
		//@@@ 이 구조는 play() 의 sat<tmp를 무조건 한 번은 실행되기 때문에, (r,c)에 자리가 이미 있어도
		//@@@ 만족도가 0인 경우로 계산해 자리를 차지하게 될 수 있다. 
		//@@@ 따라서 자리가 차지된 경우 아예 계산하지 않도록 이 구문은 바깥으로 빼는게 좋다.
		if (map[r + dx[i]][c + dy[i]] == 0) { //빈칸이면 1 추가
			ret++;
			continue;
		}
		if (map[r + dx[i]][c + dy[i]] != -1) {//벽이 아니라면
			ret += stud[n][map[r + dx[i]][c + dy[i]]]; //거기 앉아 있는 사람에 대해 n의 취향에따라 10을 더하거나 0을 더함
		}
	}
	return ret;
}
void play() {
	while (!prio.empty()) {
		int n = prio.front();
		prio.pop();
		int sat = -1;
		int best_r = 0;
		int best_c = 0;
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (map[r][c] != 0)continue;//빈칸이 아니면 다음 자리로
				int tmp = satisfy(r, c, n);
				if (sat < tmp) {
					sat = tmp;
					best_r = r;
					best_c = c;
				}

			}
		}
		map[best_r][best_c] = n;
	}

}

int ans() { //모든 작업이 끝난 뒤 만족도를 구한다.
	int ans = 0;
	for (int r= 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int tmp = 1;
			for (int i = 0; i < 4; i++) {
				if (map[r + dx[i]][c + dy[i]] != -1 && stud[map[r][c]][map[r + dx[i]][c + dy[i]]] !=0) {//벽이 아니라면
					tmp *= stud[map[r][c]][map[r + dx[i]][c + dy[i]]]; //거기 앉아 있는 사람에 대해 n의 취향에따라 10을 더하거나 0을 더함
				}
			}
			ans += tmp / 10;
		}
	}
	return ans;
}

void init() {
	scanf("%d", &N);
	for (int r =0; r <= N+1; r++) { //맵 초기화. 빈칸과 바깥을 구분
		map[0][r] = -1;
		map[N+1][r] = -1;
		map[r][0] = -1;
		map[r][N+1] = -1;
	}
	for (int i = 0; i < N*N; i++) { // 인원수대로
		int i1, i2, i3, i4, i5;
		scanf("%d %d %d %d %d", &i1, &i2, &i3, &i4, &i5);
		prio.push(i1);
		stud[i1][i2] = 10;
		stud[i1][i3] = 10;
		stud[i1][i4] = 10;
		stud[i1][i5] = 10;//꼭 서로 좋아해야한다는 보장은 없다.
	}
}
int main()
{

	freopen("input.txt", "r", stdin);
	init();
	play();
	printf("%d", ans());
	return 0;
}
