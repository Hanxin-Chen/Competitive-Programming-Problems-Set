#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<vector>
#include<queue>
using namespace std;
#define N 110
int n, m,dis[N],disn[N],vis[N],tot=0,d,cnt[N];
vector<int> g[N];
int paths1[N], pathsn[N];


void dfs(int cur)
{
	int now;
	if (cur == n)
	{
		tot++;
		for (int i = 2; i < n; i++)
		{
			cnt[i] += vis[i];
		}
		return;
	}
	for (int i = 0; i < g[cur].size(); i++)
	{
		now = g[cur][i];
		if (dis[now] + disn[now] != d || dis[now]!=dis[cur]+1)
			continue;
		vis[now] = 1;
		dfs(now);
		vis[now] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int to, from,now,cur,safe;
	cin >> n >> m;
	queue<int> qu;
	for (int i = 0; i < m; i++)
	{
		cin >> to >> from;
		g[to].push_back(from);
		g[from].push_back(to);

	}
	qu.push(1);
	vis[1] = 1;
	dis[1] = 0;
	paths1[1] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			now = g[cur][i];
			if (vis[now])
			{
				if (dis[now] == dis[cur] + 1)
					paths1[now] += paths1[cur] + 1;
				continue;
			}
			dis[now] = dis[cur] + 1;
			vis[now] = 1;
			paths1[now] = paths1[cur];
			qu.push(now);
		}
	}
	d = dis[n];
	memset(vis, 0, sizeof(vis));
	qu.push(n);
	vis[n] = 1;
	disn[n] = 0;
	pathsn[1] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			now = g[cur][i];
			if (vis[now])
			{
				if (disn[now] == disn[cur] + 1)
					pathsn[now] += pathsn[cur] + 1;
				continue;
			}
			disn[now] = disn[cur] + 1;
			pathsn[now] = pathsn[cur];
			vis[now] = 1;
			qu.push(now);
		}
	}
	memset(vis, 0, sizeof(vis));
	tot = paths1[n];
	//cout << tot << endl;
	//sort(cnt, cnt + n, greater<int>());
	safe = 0;
	for (int i = 2;i < n; i++)
	{
		if (paths1[i] * pathsn[i] > safe)
			safe = paths1[i] * pathsn[i];
	}
	safe = max(2 * safe, tot);
	double ans = 1.0*safe / tot;
	
	cout << setprecision(12) << fixed << showpoint << ans << endl;
	return 0;
}