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
#define N 100200
vector<int>g[N];
int n, dis[N], max_dis, max_index, m;
int ans = 0;
pair<int, int>tmp;
map<pair<int,int>,int> city;
void dfs(int cur, int parent) {
	int now;
	tmp = make_pair(cur, parent);
	dis[cur] = dis[parent] + city[tmp];
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
	int to, from, value;
	cin >> n;
	pair<int, int> va;
	for (int i = 0; i < N; i++)
	{
		g[i].clear();
	} 
	for (int i = 0; i < n - 1; i++)
	{
		cin >> to >> from >> value;
		g[to].push_back(from);
		g[from].push_back(to);
		va = make_pair(to, from);
		city[va] = value;
		va = make_pair(from, to);
		city[va] = value;
	}
	memset(dis, 0, sizeof(dis));
	max_dis = 0;
	dfs(1, 0);
	memset(dis, 0, sizeof(dis));
	max_dis = 0;
	dfs(max_index, 0);
	ans = max_dis * 10 + max_dis * (max_dis + 1) / 2;

	cout << ans << endl;
	return 0;
}