#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<vector>
#include<queue>
#include <set>
using namespace std;
#define N 1002
int n,m,  g[N][N];
int vis[N][N][5];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
struct node
{
	int x;
	int y;
	int rots;
	int len;
	node():rots(0),len(0){}
	node(int x1,int y1,int r1,int l1):x(x1),y(y1),rots(r1),len(l1){}
};

int  convert(char ch)
{  //TODO
	switch (ch)
	{
	case '+':
		return 15;
		break;
	case '-':
		return 5;
		break;
	case '*':
		return 0;
		break;
	case '^':
		return 8;
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int stx, sty, enx, eny;
	int x, y, dx, dy,rot;
	node n1,n2;
	queue<node> qu;
	cin >> n >> m;
	char ch;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch;
			g[i][j] = convert(ch);
		}
	}
	int ret;
	cin >> stx >> sty >> enx >> eny;
	qu.push(node(stx,sty,0,0));
	vis[stx][sty][0] = 1;
	while (!qu.empty())
	{
		node n1 = qu.front();
		qu.pop();
		x = n1.x;
		y = n1.y;
		rot = n1.rots;
		if (x == enx && y == eny)
		{
			ret = n1.len;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			dx = x + dir[i][0];
			dy = y + dir[i][1];
			if (vis[dx][dy][rot])
				continue;
			if (((g[x][y] >> rot + g[x][y] << (4 - i)) &(1 << i)) && (g[dx][dy] & (1 << (i + 2) % 4)))
			{
				qu.push(node(dx, dy, rot, n1.len + 1));
				vis[dx][dy][rot] = 1;
			}
		}
		if (vis[x][y][(rot + 1)%4])
			continue;
		qu.push(node(x,y,(rot+1)%4,n1.len));

	}
	if (qu.empty())
		cout << -1 << endl;
	else
		cout << ret << endl;
	return 0;
}