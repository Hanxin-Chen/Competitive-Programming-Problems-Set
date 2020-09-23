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
#define N 105
int dir[8][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 },{-1,-1},{-1,1},{1,1},{1,-1} };
char a[N][N];
int idx[N][N];
int n, m;

void dfs(int x, int y,int dep)  
{
	int dx, dy;
	if (x < 0 || x >= n || y < 0 || y >= m)
		return;
	if (idx[x][y] > 0 || a[x][y] != '@')
		return;
	idx[x][y] = dep;          //´æ·ÅÁªÍ¨±àºÅ
	for (int i = 0;i < 8;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		dfs(dx, dy,dep);
		
	}
}


int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>m&&(n!=0||m!=0))
	{
		int  cnt = 0;
		memset(a, 0, sizeof(a));
		memset(idx, 0, sizeof(idx));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				cin >> a[i][j];
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				if (idx[i][j] == 0 && a[i][j] == '@')
				{
					dfs(i, j, ++cnt);
				}
			}
		cout << cnt << endl;
	}
	return 0;
}
