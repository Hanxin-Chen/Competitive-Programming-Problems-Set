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

const int maxn = 22;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char ma[maxn][maxn];
int step[(1 << 11)][maxn][maxn];
int N, M, T;
int key;
struct Node
{
	int state;
	int x, y;
};
queue<Node> q;

void init()
{
	key = 0;
	memset(step, -1, sizeof(step));
	while (!q.empty()) q.pop();
}

bool Wall(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return true;
	if (ma[x][y] == '*') return true;
	return false;
}

//ÅÐ¶ÏÔÚstate×´Ì¬ÏÂ£¬ÄÜ·ñ
bool door(int x, int y, int state)
{
	if (ma[x][y] >= 'A' && ma[x][y] <= 'J')
	{
		int s = ma[x][y] - 'A' + 1;
		if (((1 << s) & state) != 0)
			return false;
		else
			return true;
	}
	return false;
}

int bfs()
{
	while (!q.empty())
	{
		Node n = q.front();
		q.pop();
		if (step[n.state][n.x][n.y] >= T) return -1;
		if (ma[n.x][n.y] == '^')
			return step[n.state][n.x][n.y];

		int newstate = n.state;
		for (int i = 0; i < 4; i++)
		{
			int nx = n.x + dir[i][0];
			int ny = n.y + dir[i][1];
			if (Wall(nx, ny) || door(nx, ny, n.state)) continue;
			if (step[newstate][nx][ny] != -1) continue;
			if (ma[nx][ny] >= 'a' && ma[nx][ny] <= 'j')
				newstate = ((1 << (ma[nx][ny] - 'a' + 1)) | n.state);
			else
				newstate = n.state;
			Node tmp;
			tmp.state = newstate, tmp.x = nx, tmp.y = ny;
			step[newstate][nx][ny] = step[n.state][n.x][n.y] + 1;
			q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	while (scanf("%d %d %d", &N, &M, &T) != EOF)
	{
		getchar();
		init();
		int i, j;
		Node s;
		s.state = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				char c = getchar();
				if (c >= 'A' && c <= 'J' && c - 'A' + 1 > key)
					key = c - 'A' + 1;
				else if (c == '@')
					s.x = i, s.y = j;
				ma[i][j] = c;
			}
			getchar();
		}
		step[0][s.x][s.y] = 0;
		q.push(s);
		int ans = bfs();
		printf("%d\n", ans);
	}
	return 0;
}
