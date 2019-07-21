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
#define N 30
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
char a[N][N];


int n, m, t;
int sx, sy;
int cnt;

void dfs(int x, int y)  
{
	int dx, dy;
	for (int i = 0;i < 4;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx<0 ||dx>=n || dy<0 ||dy>=m)
			continue;
		if (a[dx][dy] == '.')
		{
			a[dx][dy] = '#';
			cnt++;
			dfs(dx, dy);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	while (cin>>m>>n&&(n!=0||m!=0))
	{
		cnt = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		a[sx][sy] = '#';
		dfs( sx,  sy);
		cout << cnt+1 << endl;
	}
	return 0;
}
