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
#define N 17
int n;
int dir[8][2] = { {-2,-1},{-2,1},{2,1},{2,-1},{1,2},
                   {1,-2},{-1,2},{-1,-2} };          //定义一个增量数组；
int vis[N][N];

struct point
{
	int x, y;
	int num;
	point() :num(0) {
	}
	bool operator < (point p1) const
	{
		return num < p1.num;
	}
};

bool canput(int dx, int dy)
{
	if (dx < 0 || dx >= n || dy < 0 || dy >= n)
		return false;
	else if (vis[dx][dy] == 1)
		return false;
	return true;
}

int canput_num(int x, int y)
{
	int dx, dy;
	int cnt = 0;
	for (int i = 0;i < 8;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (canput(dx, dy))
		{
			cnt++;
		}
	}
	return cnt;
}

int next(int x, int y, point ne[8])
{
	int dx, dy;
	int cnt = 0;
	for (int i = 0;i < 8;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (canput(dx, dy))
		{
			ne[cnt].x = dx;
			ne[cnt].y = dy;
			ne[cnt].num = canput_num(dx, dy);
			cnt++;
		}
	}
	sort(ne, ne + cnt);
	return cnt;
}

void dfs(int x, int y, int dep)
{
	int dx, dy,k;
	point ne[8];
	if (dep > n*n-1)
	{
		cout << "YES" << endl;
		//exit(0);
		return;
	}
	k = next(x, y,ne);  //返回个数

	for (int i = 0;i < k;i++)
	{
		dx = ne[i].x;
		dy = ne[i].y;
		if (canput(dx, dy))
		{
			vis[dx][dy] = 1;
			dfs(dx, dy, dep + 1);
			vis[dx][dy] = 0;
		}
	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n ;
	int x, y;
	cin >> x >> y;
	vis[x][y] = 1;
	dfs(x, y, 1);
	return 0;
}
