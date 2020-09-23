#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<vector>
#include<queue>
#include <set>
using namespace std;
#define N 300005
vector<pair<int,int> > g[N];
int n,k,d,vis[N],vise[N];
int tot = 0, del[N],belongs[N];
set<int> deal;

int main()
{
	ios::sync_with_stdio(false);
	queue<int> qu;
	cin >> n >> k >> d;
	int to, from, cur, now;
	for (int i = 0; i < k; i++)
	{
		cin >> to;
		qu.push(to);
		vis[to] = 1;
		belongs[to] = to;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> to >> from;
		g[to].push_back(make_pair(from, i));
		g[from].push_back(make_pair(to, i));
	}
	pair<int, int> tmp;
	int ei;
	while (!qu.empty())  
	{
		cur = qu.front();
		qu.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			tmp = g[cur][i];
			now = tmp.first;
			ei = tmp.second;
			if (vis[now])
			{
				if (!vise[ei])
				{
					//del[tot++] = ei;
					deal.insert(ei);
				}
				continue;
			}
			vis[now] = 1;
			vise[ei] = 1;
			qu.push(now);
		}
	}
	cout << deal.size() << endl;
	set<int>::iterator it;
	for (it=deal.begin(); it!= deal.end(); it++)
	{
		if (it != deal.begin())
			cout << " ";
		cout << *it;

	}
	cout << endl;
	return 0;
}