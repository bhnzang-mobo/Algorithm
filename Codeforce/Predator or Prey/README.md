이 문제는 정렬과 이진탐색을 활용해 해결한 문제이다.

각 원소가 모든 원소와 상호작용해서 포식자인지 피식자인지 판단해야한다면
O(n^2)의 시간복잡도가 걸리므로
Hard 버전의 문제는 해결할 수 없을 것이다.

Hard문제를 포괄 할 수 있을 방법을 고안해본다.

이 문제의 특징은, 피식자와 포식자의 범위를 정해두면 해결할 수 있다.
피식자와 포식자는 a, b로 계산할 수 있다.
그 수는 계산된 값의 인덱스값을 살펴보고 서로 차이를 구하면 알아낼 수 있겠다.

정렬된 배열에 특정 값의 인덱스를 가장 빨리 찾기 위해 이진탐색법을 사용한다. O(logN)
정렬에 사용한 알고리즘은 mergeSort로 O(nlogn)이다

따라서 이 문제의 전체적인 시간복잡도는 O(nlogn)이다

간단히 구현한 binarySearch의 함수가 upper bound인지 lower bound인지,
그리고 찾아야할 포식자 피식자 범위를 어떻게 정할지
재정렬은 어떻게할지 정하다보니 너무 오래 걸렸다.

그리고 정렬하고 다시 원래 순서로 원복시키기위해 2차원 배열로 인덱스 값을 따로 저장했다.

아래는 참고할만한 코드.

// keqing best girl <3
// Problem: D2. Predator or Prey (Hard Version)
// Attempted: 2024-04-21 16:06:11 EST

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
#define all(x) x.begin(), x.end()

int in_range(int a, int b, vector<ll>& v){
	int r = upper_bound(all(v), b) - v.begin();
	int l = lower_bound(all(v), a) - v.begin();
	return r - l;
}

void solve(){
	ll n, a, b; cin >> n >> a >> b;
	vector<ll> p(n);
	for(ll& i: p) cin >> i;
	vector<ll> sp = p;
	sort(all(sp));
	for(int i = 0; i < n; i++){
		cout << in_range(p[i] + a, p[i] + b - 1, sp) << " " << in_range(p[i] - b + 1, p[i] - a, sp) << "\n";
	}
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	while(T--) solve();
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/