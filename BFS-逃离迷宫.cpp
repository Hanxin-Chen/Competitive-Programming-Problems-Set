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
int n, m,k,stx,sty,endx,endy;
char a[105][105];
int vis[105][105];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node
{
	int x, y;
	int turn;
	node():turn(0){}
};

bool bfs(int x, int y) {
	node  s, tmp;
	memset(vis, 0, sizeof(vis));
	tmp.x = x;
	tmp.y = y;
	tmp.turn = -1;
	queue<node> q;
	q.push(tmp);
	vis[x][y] = 1;
	while (!q.empty())
	{
		s = q.front();
		if (s.turn >= k)
			break;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			tmp.x = s.x + dir[i][0];
			tmp.y = s.y + dir[i][1];
			tmp.turn = s.turn + 1;
			while (true)
			{
				if (tmp.x >= 0 && tmp.x < n &&tmp.y >= 0 && tmp.y < m &&a[tmp.x][tmp.y] == '.')
				{
					if (tmp.x == endx && tmp.y == endy )
					{
						return true;
					}
					if (vis[tmp.x][tmp.y] == 0)
					{
						vis[tmp.x][tmp.y] = 1;
						q.push(tmp);
					}
					tmp.x += dir[i][0];
					tmp.y += dir[i][1];
				}
				else break;
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
		cin >> n >> m ;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> k >> sty >> stx >> endy >> endx;
		stx -= 1;
		sty -= 1;
		endx -= 1;
		endy -= 1;
		if (bfs(stx, sty)) {
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}