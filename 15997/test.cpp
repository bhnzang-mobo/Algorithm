#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

//출처 : http://wookje.dance/2018/11/15/boj-15997/
//해당 소스코드를 비교해 DFS방식으로 모든 경우의 수를 조사한 방식에 대해 탐구.

map<string, int> m; //팀 이름을 숫자로 매칭 
struct abc {
	int x, y;
	double w, d, l;
} a[6]; //a라는 이름의 구조체 배열 6짜리

int s[4];//팀의 점수를 나타냄. 인덱스번호 = 팀 번호
double r[4];//각 팀의 우승 확률.
pair<int, int> t[4];

void go(int n, double p) {
	if (n == 6) {
		for (int i = 0; i < 4; i++) {
			t[i].fst = s[i];//i번째 팀의 점수
			t[i].snd = i;//i번째 팀의 인덱스
		}
		sort(t, t+4);//럴수 오름차순 이엇나봄 개짜증
		int A = t[0].fst, B = t[1].fst, C = t[2].fst, D = t[3].fst;//1등 팀의 점수
		int a = t[0].snd, b = t[1].snd, c = t[2].snd, d = t[3].snd;//1등 팀의 팀 인덱스
		//여기서부터 확률처리 과정. 동점자 처리 기준이 있으므로 약간 짜증

		if (B != C) { //2등과 3등이 다른경우
			r[c] += p; r[d] += p;
		} else if (A == B && C == D) { //2등과 3등이 같으면서(첫 if문) 1등과 2등이 같고 동시에 3등과 4등이 같은경우, 즉 모두 동률인 경우
			r[a] += p/2.0; r[b] += p/2.0;
			r[c] += p/2.0; r[d] += p/2.0;
		} else if (A == B) {//2등과 3등이 같으면서 3등과 4등이 같고 1등만 다른 경우.
			r[a] += p/3.0; r[b] += p/3.0;
			r[c] += p/3.0; r[d] += p;
		} else if (C == D) {// 2등과 3등이 같고, 1등과 2등이 같음. 4등은 탈락 확정인 경우.
			r[b] += p*2.0/3.0; r[c] += p*2.0/3.0;
			r[d] += p*2.0/3.0;
		} else {//2등과 3등만 같고 나머지는 서로 다른 경우. 1등은 진출 확정 2등과 3등의 추첨
			r[b] += p/2.0; r[c] += p/2.0;
			r[d] += p;
		}
		return;
	}

	int x = a[n].x, y = a[n].y; //x는 경기 진행상 왼쪽팀, y는 오른쪽 팀

	s[x] += 3;
	go(n+1, p*a[n].w); //이 DFS는 확률과 진행 경과를 인자로 받고, 점수는 글로벌 변수에 저장한다.
	s[x] -= 3;

	s[x] += 1; s[y] += 1;
	go(n+1, p*a[n].d);
	s[x] -= 1; s[y] -= 1;

	s[y] += 3;
	go(n+1, p*a[n].l);
	s[y] -= 3;
}

int main() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		m[str] = i;//팀 이름과 숫자를 매칭
	}

	for (int i = 0; i < 6; i++) {
		string s1, s2;
		cin >> s1 >> s2 >> a[i].w >> a[i].d >> a[i].l;
		a[i].x = m[s1]; //a라는 배열은 경기 횟수 6회에 대한 정보 저장.
		a[i].y = m[s2];
	}//인풋

	go(0, 1.0);

	for (int i = 0; i < 4; i++) {
		printf("%.18lf\n", r[i]);
	}

	return 0;
}
//느낀점 : 호구같이 C쓰지말고 C++쓰면서 라이브러리 쓰는 방법을 배우자. 물론 몇가지 함수나 구현법을 외우는건 기특하다.