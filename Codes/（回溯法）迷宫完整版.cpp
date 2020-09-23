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
#define N 8
int dir[4][4] = { {1,0},{-1,0},{0,1},{0,-1} };
char map1[N][N];
int vis[N][N] = { 0 };
//vector<char> map[N];
//   *****迷宫问题****
/*
输入格式 4 4 5 ->行列和走的步数
	S..X
	....
	.X..
	...D
*/
int n,m, t;
int sx, sy, ex, ey,ans=0;

bool canmove(int x, int y,int cur)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y])   //越界+不走回头路
		return false;
	else if (map1[x][y] == 'X')                            //遇到墙了
		return false;
	else if (x == ex && y == ey && t - cur != 1)           //时间没到就到门口了
		return false;
	else if (abs(x - ex) + abs(y - ey) > t - cur)          //超时走不完了
		return false;
	//else if (((x + y) & 1) ^ ((ex + ey) & 1) ^ ((t - cur) & 1))  //0-1 奇偶剪枝  ???有点问题
	//	return false;
	return true;
}

int dfs(int x, int y, int dep)  //此种算法只能得出一种解。
{
	int dx, dy;
	if (x == ex && y == ey && t==dep)
	{
		ans = dep;
		cout << ans << endl;
		return 1;
	}
	for (int i = 0;i < 4;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (!canmove(dx, dy,dep))
			continue;
		vis[dx][dy] = 1;
		if (dfs(dx, dy, dep + 1))
			return 1;
		vis[dx][dy] = 0;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	char ch;
	while (cin >> n >> m >> t)
	{
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				cin >> ch;
				map1[i][j] = ch;
				if (ch == 'S')
					sx = i, sy = j;
				else if (ch == 'D')
					ex = i, ey = j;
			}
		vis[sx][sx] = 1;
		if (!canmove(sx, sy, t))
			cout << "NO" << endl;
		if (dfs(sx, sy, 0))   
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
