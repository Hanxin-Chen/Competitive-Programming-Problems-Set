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
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
#define N 107
char a[N][N];
int ans = 0, vis[N][N];

void dfs(int x, int y) {
	int dx = x, dy = y;
	if (a[x][y] == 'U') {
		dx -= 1;
	}
	else if (a[x][y] == 'D') {
		dx += 1;
	}
	else if (a[x][y] == 'L') {
		dy -= 1;
	}
	else if (a[x][y] = 'R') {
		dy += 1;
	}
	if (dx < 0 || dx>9 || dy < 0 || dy>9) {
		ans++;
		return;
	}
	if (vis[dx][dy] == 0) {
		vis[dx][dy] = 1;
		dfs(dx, dy);
	}
	else
	{
		return;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			memset(vis, 0, sizeof(vis));
			vis[i][j] = 1;
			dfs(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}