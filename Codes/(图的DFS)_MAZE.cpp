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
#define N 502
char g[N][N];
int n, m, k;
int n1 = 0;
int vis[N][N], cnt = 0;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(int x, int y)
{
	int dx, dy;
	cnt++;
	if (cnt == n1 - k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j] == '.'&&vis[i][j] == 0)
					cout << 'X';
				else
					cout << g[i][j];
			}
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;
		if (g[dx][dy] == '#' || vis[dx][dy])
			continue;
		vis[dx][dy] = 1;
		dfs(dx, dy);
		//vis[dx][dy] = 0;
		//if(cnt<=k)
		//g[i][j]='X'

	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	int sx, sy;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j] == '.')
			{
				n1++;
				sx = i, sy = j;
			}
		}
	}
	vis[sx][sy] = 1;
	dfs(sx, sy);

	return 0;
}