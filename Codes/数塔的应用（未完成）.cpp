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
using namespace std;
#define N 1000
#define inf 1<<30;
int dp[N][2];
int n,MAX,sx,sy;
struct node
{
	int lx, rx;
	int h;
	int w;
	bool operator <(node &n1) const {
		return h < n1.h;
	}
}layer[N];

int down(int x,int st, int h)
{
	for (int j = st;j >= 0;j--)
	{
		if (h - layer[j].h > MAX)
			return -1;
		if (x<layer[j].rx && x>layer[j].lx)
			return j;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int lx, rx;
	int dl, dr;
	while (t--)
	{
		cin >> n >> sx >> sy >> MAX;
		layer[0].lx = layer[0].rx = sx;
		layer[0].h = sy;
		layer[1].lx = -inf;
		layer[1].rx = inf;
		layer[1].h = 0;
		for (int i = 2;i <= n+1;i++)
		{
			cin >> layer[i].lx >> layer[i].rx >> layer[i].h;
		}
		sort(layer, layer + n + 2);
		for (int i = 1;i <= n+1;i++)
		{
			lx = layer[i].lx;
			rx = layer[i].rx;
			dl = down(lx, i - 1,layer[i].h);
			dr = down(rx, i - 1,layer[i].h);
			if (dl > 0)
				dp[i][0] = min(dp[dl][0] + lx - layer[dl].lx, dp[dl][1] + layer[dl].rx - rx);
			else
				dp[i][0] = inf;
			if (dr > 0)
				dp[i][1] = min(dp[dr][0] + rx - layer[dr].lx, dp[dr][1] + layer[dr].rx - rx);
			else
				dp[i][1] = inf;


		}
		cout << dp[n+1][0] + sy << endl;
	}
	
	return 0;
}
