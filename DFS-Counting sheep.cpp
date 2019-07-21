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
char a[105][105];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int w, h,ans;
int vis[105][105];

void dfs(int x, int y) {
	int dx, dy;
	for (int i = 0; i < 4; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx < 0 || dy < 0 || dx >= h || dy >= w  ) {
			continue;
		}
		if (a[dx][dy] == '#') {
			a[dx][dy] = '.';
			dfs(dx, dy);
			//a[dx][dy] = '#';
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> h >> w;
		ans = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (a[i][j] == '#') {
					a[i][j] = '.';
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}