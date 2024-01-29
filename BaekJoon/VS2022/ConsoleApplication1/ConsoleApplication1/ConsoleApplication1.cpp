#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int map[22][22]; //N�� �۱⶧���� ���� N^3���� �������� ���� ^^
int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,1,0,-1 };
int stud[401][401];//�� �л��鸶�� 4���� ������ �����Ѵٰ����� ������ ���縦 4�� �ݺ��ؼ� ��ȸ�ϰ������, �׳� 0�� 10���� ǥ���غ���.
queue<int> prio;

int satisfy(int r, int c, int n) { //(r,c)���� i �� �л��� ���� �������� ����.
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		//@@@ if (map[r][c] != 0)continue;  �ٱ����� �������. �� �� �� continue �Ǽ� ret = 0 ���� ���ϵ� ��� ������ ����
		//@@@ �� ������ play() �� sat<tmp�� ������ �� ���� ����Ǳ� ������, (r,c)�� �ڸ��� �̹� �־
		//@@@ �������� 0�� ���� ����� �ڸ��� �����ϰ� �� �� �ִ�. 
		//@@@ ���� �ڸ��� ������ ��� �ƿ� ������� �ʵ��� �� ������ �ٱ����� ���°� ����.
		if (map[r + dx[i]][c + dy[i]] == 0) { //��ĭ�̸� 1 �߰�
			ret++;
			continue;
		}
		if (map[r + dx[i]][c + dy[i]] != -1) {//���� �ƴ϶��
			ret += stud[n][map[r + dx[i]][c + dy[i]]]; //�ű� �ɾ� �ִ� ����� ���� n�� ���⿡���� 10�� ���ϰų� 0�� ����
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
				if (map[r][c] != 0)continue;//��ĭ�� �ƴϸ� ���� �ڸ���
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

int ans() { //��� �۾��� ���� �� �������� ���Ѵ�.
	int ans = 0;
	for (int r= 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int tmp = 1;
			for (int i = 0; i < 4; i++) {
				if (map[r + dx[i]][c + dy[i]] != -1 && stud[map[r][c]][map[r + dx[i]][c + dy[i]]] !=0) {//���� �ƴ϶��
					tmp *= stud[map[r][c]][map[r + dx[i]][c + dy[i]]]; //�ű� �ɾ� �ִ� ����� ���� n�� ���⿡���� 10�� ���ϰų� 0�� ����
				}
			}
			ans += tmp / 10;
		}
	}
	return ans;
}

void init() {
	scanf("%d", &N);
	for (int r =0; r <= N+1; r++) { //�� �ʱ�ȭ. ��ĭ�� �ٱ��� ����
		map[0][r] = -1;
		map[N+1][r] = -1;
		map[r][0] = -1;
		map[r][N+1] = -1;
	}
	for (int i = 0; i < N*N; i++) { // �ο������
		int i1, i2, i3, i4, i5;
		scanf("%d %d %d %d %d", &i1, &i2, &i3, &i4, &i5);
		prio.push(i1);
		stud[i1][i2] = 10;
		stud[i1][i3] = 10;
		stud[i1][i4] = 10;
		stud[i1][i5] = 10;//�� ���� �����ؾ��Ѵٴ� ������ ����.
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
