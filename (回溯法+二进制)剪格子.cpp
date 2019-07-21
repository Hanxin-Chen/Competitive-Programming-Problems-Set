#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int a[18], c, m[6][6], vis[6][6], ans;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
// 连通返回1，不连通返回0 
int bfs(int x, int y) {
	int x1, y1, dx, dy, cnt = 0;
	queue<pair<int, int> > qu;
	qu.push(make_pair(x, y));
	pair<int, int>pa;
	vis[x][y] = 1;
	while (!qu.empty()) {
		pa = qu.front();
		qu.pop();
		cnt++;
		x1 = pa.first;
		y1 = pa.second;
		for (int i = 0; i < 4; i++) {
			dx = x1 + dir[i][0];
			dy = y1 + dir[i][1];
			if (vis[dx][dy])
				continue;
			if (m[dx][dy] == 1)
				continue;
			if (dx < 0 || dy < 0 || dx>5 || dy>5)
				continue;
			qu.push(make_pair(dx, dy));
			vis[dx][dy] = 1;
		}
	}
	return (cnt == 18);
}
void dfs(int depth) {
	int x, y, i, j;
	if (depth == 18) {
		//for(int i=0; i<18; i++)
		//	cout<<a[i];
		//cout<<endl;
		for (int i = 0; i < 18; i++) {
			x = i / 6;
			y = i % 6;
			m[x][y] = a[i];
			m[5 - x][5 - y] = 1 - a[i];
		}
		for (i = 0; i < 6; i++)
			for (j = 0; j < 6; j++) {
				if (m[i][j] == 0) {
					memset(vis, 0, sizeof(vis));
					ans += bfs(i, j);
					return;
				}
			}

	}
	a[depth] = 0;
	dfs(depth + 1);
	a[depth] = 1;
	dfs(depth + 1);
}


int main() {
	ios::sync_with_stdio(false);
	int i, j, x, y;
	// 方法1 
	dfs(0);
	cout << ans << endl;

	ans = 0;
	// 方法2
	for (i = 0; i <= (1 << 18) - 1; i++) {
		for (j = 0; j < 18; j++) {
			x = j / 6;
			y = j % 6;
			m[x][y] = ((i >> j) & 1);
			m[5 - x][5 - y] = 1 - ((i >> j) & 1);
		}
		for (int i1 = 0; i1 < 6; i1++) {
			for (j = 0; j < 6; j++) {
				if (m[i1][j] == 0) {
					memset(vis, 0, sizeof(vis));
					ans += bfs(i1, j);
					break;
				}
			}
			if (j < 6)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}

