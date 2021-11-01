#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int study[1000001];
int S,P,first,last;

void read() {
	scanf("%d %d", &S, &P);
	int idx;
	scanf("%d", &first);
	study[first] = 1;
	for (int i = 1; i < S; i++) {
		scanf("%d", &idx);
		study[idx] = 1;
	}
	last = idx;
}

int play() {
	int start;
	int end;
	int tmp = P;
	start = first-1;
	end = first;
	int cnt = 1;
	int max = 0;
	while (end+1<=last) {
		while (study[end + 1] == 1) {
			cnt++;
			end++;
		}
		while (study[end + 1] == 0 && tmp > 0) {
			study[end + 1] = 2;
			cnt++;
			end++;
			tmp--;
			while (study[end + 1] == 1) {
				cnt++;
				end++;
			}
		}
		max = max > cnt ? max : cnt;
		while (tmp <= 0) {
			while (study[start + 1] == 1) {
				start++;
				cnt--;
			}
			while(study[start + 1] == 2){
				start++;
				cnt--;
				tmp++;
				break;
			}
		}
	}
	max = max > end-start + tmp ? max : end - start + tmp;
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read();
		printf("#%d %d\n", i, play());
	}
	return 0;
}
