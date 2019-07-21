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
#define N 20
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
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
int n, m, t;
int sx, sy, ex, ey;
int ans;
int ok;
int k;
bool canmove(int x, int y, int cur)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y])   //越界+不走回头路
		return false;
	else if (map1[x][y] == 'X')                            //遇到墙了
		return false;
	//else if (x == ex && y == ey && t - cur != 1)           //时间没到就到门口了
	//	return false;
	//else if (abs(x - ex) + abs(y - ey) > t - cur)          //超时走不完了
	//	return false;
	//else if (!((x + y) & 1) ^ ((ex + ey) & 1) ^ ((t - cur) & 1))  //0-1 奇偶剪枝  ???有点问题
	//	return false;
	return true;
}

void dfs1(int x, int y, int dep)  //此种算法只能得出一种解。
{
	int dx, dy;
	if (x == ex && y == ey && t == dep)
	{
		ok = 1;
		return;
	}
	ans = t - dep - abs(ex - x) - abs(ey - y);
	if (ans < 0 || ans & 1)
		return;
	for (int i = 0;i < 4;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (!canmove(dx, dy, dep))
			continue;
		vis[dx][dy] = 1;
		dfs1(dx, dy, dep + 1);
		vis[dx][dy] = 0;
	}
}
void dfs(int x, int y, int time)
{
	int i, ans;
	if (x == ex && y == ey && time == t) ok = 1;
	if (ok) return;
	if (x<0 || y<0 || x>=n || y>=m) return;  //搜索到边界 。 
	ans = t - time - abs(ex - x) - abs(ey - y);
	if (ans<0 || ans & 1) return;
	for (i = 0;i<4;i++)
	{
		if (map1[x + dir[i][0]][y + dir[i][1]] != 'X')
		{
			map1[x + dir[i][0]][y + dir[i][1]] = 'X';
			dfs(x + dir[i][0], y + dir[i][1], time + 1);
			map1[x + dir[i][0]][y + dir[i][1]] = '.';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	char ch;
	while (scanf_s("%d %d %d",&n,&m,&t)!=EOF)
	{
		if ((n == 0 && m == 0 && t == 0))
			break;
		memset(vis, 0, sizeof(vis));
		memset(map1, 0, sizeof(map1));
		k = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				cin >> ch;
				map1[i][j] = ch;
				if (ch == 'S')
					sx = i, sy = j;
				else if (ch == 'D')
					ex = i, ey = j;
				if (ch == 'X')
					k++;
			}
		if (n*m - k < t)
			printf("NO\n");
			//cout << "NO" << endl;
		else
		{
			vis[sx][sx] = 1;
			map1[sx][sy] = 'X';
			ok = 0;
			dfs(sx, sy, 0);
			if (ok)
				printf("YES\n");
				//cout << "YES" << endl;
			else
				printf("NO\n");
				//cout << "NO" << endl;
		}
	}
	return 0;
}
