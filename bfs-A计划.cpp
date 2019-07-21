#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
#include <map>
#include <ctime>
#include <sstream>
#pragma warning(disable:4996);
using namespace std;
int n, m, t;
char a[2][12][12];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node
{
	int x, y, z, time;
	node() :time(0) {}
}r,s,tmp;

bool bfs(int x, int y, int z) {
	r.x = x;
	r.y = y;
	r.z = z;
	r.time = 0;
	queue<node> q;
	q.push(r);
	a[x][y][z] = '*';
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			tmp = s;
			tmp.y = s.y + dir[i][0];
			tmp.z = s.z + dir[i][1];
			tmp.time = s.time + 1;
			if (tmp.z >= 0 && tmp.y >= 0 && tmp.y < n && tmp.z < m && a[tmp.x][tmp.y][tmp.z] != '*')
			{
				if (a[tmp.x][tmp.y][tmp.z] == '#') {
					a[tmp.x][tmp.y][tmp.z] = '*';
					tmp.x = !s.x;
				}
				if (a[tmp.x][tmp.y][tmp.z] == 'P' && tmp.time <= t)
					return true;
				a[tmp.x][tmp.y][tmp.z] = '*';
				q.push(tmp);
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m >> t;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[0][i][j];
			}
		}
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[1][i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[0][i][j] == '#' && a[1][i][j] == '#') {
					a[0][i][j] = '*';
					a[1][i][j] = '*';
				}
				if (a[0][i][j] == '*' && a[1][i][j] == '#') {
					a[0][i][j] = '*';
					a[1][i][j] = '*';
				}
				if (a[0][i][j] == '#' && a[1][i][j] == '*') {
					a[0][i][j] = '*';
					a[1][i][j] = '*';
				}
			}
		}
		if (bfs(0, 0, 0)) {
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}