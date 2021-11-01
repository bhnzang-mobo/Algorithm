#include<iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define MAXN 100002
#define MAXK 18

int n;

struct Node
{
	vector<int> child;
};

Node node[MAXN];
int dp[MAXK][MAXN];
int depth[MAXN] = { 0, };

void setDepthAndDP0()
{
	int idx, parent;
	queue < pair<int, int>> q;
	q.push({ 1,0 });
	while (!q.empty())
	{
		idx = q.front().first;
		parent = q.front().second;
		q.pop();
		dp[0][idx] = parent;
		depth[idx] = depth[parent] + 1;
		for (int i = node[idx].child.size() - 1; i >= 0; i--)
			q.push({ node[idx].child[i],idx });
	}
}

void makeDp()
{
	for (int i = 1; i < MAXK; i++)
	{
		for (int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	}
}

vector<int> order;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		order.clear();
		cin >> n;
		int parent;
		for (int i = 1; i <= n; i++)
			node[i].child.clear();

		for (int i = 2; i <= n; i++)
		{
			cin >> parent;
			node[parent].child.push_back(i);
		}

		int start = 0, nowidx, size;
		order.push_back(1);
		while (start < order.size())
		{
			nowidx = order[start++];
			size = node[nowidx].child.size();
			for (int i = 0; i < size; i++)
				order.push_back(node[nowidx].child[i]);
		}

		setDepthAndDP0();
		makeDp();
		int a, b, c, diff, maxtop;
		long long result = 0;
		for (int i = 1; i < n; i++)
		{
			a = order[i - 1];
			b = order[i];
			if (depth[a] > depth[b])
				swap(a, b); //a가 더 위에 있어야함
			diff = depth[b] - depth[a];
			int j = 0;
			while (diff != 0)
			{
				if (diff & 1)
					b = dp[j][b];
				j++;
				diff = diff >> 1;
			}
			if (a != b)
			{
				maxtop = MAXK - 1;
				while (maxtop != 0)
				{
					while (dp[maxtop][a] == dp[maxtop][b])
					{
						if (--maxtop < 0)
							break;
					}
					if (maxtop < 0)
						break;
					a = dp[maxtop][a];
					b = dp[maxtop][b];
				}
				c = dp[0][a];
			}
			else
				c = a;

			result += depth[order[i - 1]] + depth[order[i]] - (depth[c] << 1);
		}

		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}