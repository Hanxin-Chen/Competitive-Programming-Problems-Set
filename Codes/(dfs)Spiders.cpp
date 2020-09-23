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
#define N 102
vector<int>g[N];
int n,dis[N],max_dis,max_index,m;
int ans = 0;
//parent is the root point of cur
void dfs(int cur,int parent) {
	int now;
	dis[cur] = dis[parent] + 1;
	if (max_dis < dis[cur])
	{
		max_dis = dis[cur];
		max_index = cur;
	}
	for (int i = 0; i < g[cur].size(); i++)
	{
		now = g[cur][i];
		if (now == parent)
			continue;

		dfs(now, cur);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int to, from;
	cin >> n;
	while (n--)
	{
		cin >> m;
		for (int i = 0; i < N; i++)
		{
			g[i].clear();
		}
		for (int i = 0; i < m-1; i++)
		{
			cin >> to >> from;
			g[to].push_back(from);
			g[from].push_back(to);
		}
		memset(dis, 0, sizeof(dis));
		max_dis = 0;
		dis[0] = -1;
		dfs(1,0);
		memset(dis, 0, sizeof(dis));
		dis[0] = -1;
		max_dis = 0;
		dfs(max_index, 0);
		ans += max_dis;
	}
	cout << ans << endl;
	return 0;
}