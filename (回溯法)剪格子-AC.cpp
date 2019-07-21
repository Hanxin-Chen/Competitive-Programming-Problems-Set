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
int dir[4][2] = { 0,1, 0,-1, 1,0, -1,0 };
int vis[10][10];
int ans = 0;
void dfs(int x, int y) {
	if (x == 0 || y == 0 || x == 6 || y == 6) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];

		int x2 = 6 - x1;
		int y2 = 6 - y1;

		if (x1 >= 0 && y1 >= 0 && x1 <= 6 && y1 <= 6) {
			if (!vis[x1][y1]) {
				vis[x1][y1] = vis[x2][y2] = 1;
				dfs(x1, y1);
				vis[x1][y1] = vis[x2][y2] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vis[3][3] = 1;
	dfs(3, 3);
	cout << ans / 4;
	return 0;
}
