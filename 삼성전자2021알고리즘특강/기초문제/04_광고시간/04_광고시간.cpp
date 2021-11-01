#pragma warning(disable:4996)
#include <iostream>
int L, S;
int mytime[100001][2]; //s, e for each
int dp[100001]; // dynamically saved
void read() {
	scanf("%d %d",&L, &S);
	for (int i = 0; i < S; i++) {
		scanf("%d %d", &mytime[i][0], &mytime[i][1]);
	}
	dp[1] = mytime[0][1] - mytime[0][0];
	for (int i = 1; i < S; i++) {
		dp[i+1] = dp[i] + mytime[i][1] - mytime[i][0];
	}
}

int play() {
	int max = 0;
	for (int i = 0; i < S; i++) {
		int s = 0;
		int e = S - 1;
		while (s <= e) {
			int m = (s + e) / 2;
			if (mytime[i][0] + L == mytime[m][0]) {
				s = m+1;
				break;
			}
			if (mytime[i][0] + L < mytime[m][0]) {
				e = m-1;
			}
			else {
				s = m+1;
			}
		}
		int tmp;
		s--;
		if (mytime[s][1] < mytime[i][0] + L) {
			tmp = dp[s + 1] - dp[i];
		}
		else {
			tmp = dp[s + 1] - (mytime[s][1] - (mytime[i][0] + L)) - dp[i];
		}
		max = max > tmp ? max : tmp;
	}
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		read();
		play();
		printf("#%d %d\n", i, play());
	}
	return 0;
}

