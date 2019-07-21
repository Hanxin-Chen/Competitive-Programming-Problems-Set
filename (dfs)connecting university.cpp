#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>                                                
#include<cstdio>                                                   
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cctype>
#include<sstream>
#include<queue>
using namespace std;
#define N 200004
vector<int>g[N];
int u[N] = { 0 };
int n, k;
long long num[N];

void dfs(int cur, int par)
{
	int now;
	if (u[cur])
		num[cur]++;
	for (int i = 0; i < g[cur].size();i++)
	{
		now = g[cur][i];
		if (now == par)
			continue;
		dfs(now, cur);
		//rollback
		num[cur] += num[now];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int to, from;
	cin >> n >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		cin >> to;
		u[to] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> to >> from;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	dfs(1, 0);
	long long ret = 0;
	for (int i = 2; i <= n; i++)
	{
		ret += min(num[i], 2 * k - num[i]);//one side and the other side;
	}
	cout << ret << endl;
	return 0;
}