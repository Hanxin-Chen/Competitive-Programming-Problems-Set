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
#include<queue>
using namespace std;
#define	N 100
vector<pair<int,int> > g[N];
int vis[N][N];
int dir[8][2] = { {-2,-1},{-2,1},{2,1},{2,-1},{1,2},
				   {1,-2},{-1,2},{-1,-2} };
int cnt = 0;

int main()
{
	string a, b;
	int x, y;
	int dx, dy;
	pair<pair<int, int>, int> from,cur,now;
	pair<int, int>cur1, to;
	queue<pair<pair<int,int>,int> > qu;
	cin >> a >> b;
	x = a[0] - 'a' + 1;
	y = a[1]-'1'+1;
	from = make_pair(make_pair(x, y),0);
	qu.push(from);
	vis[x][y] = 1;
	x = b[0] - 'a' + 1;
	y = b[1]-'1'+1;
	to = make_pair(x, y);

	while (!qu.empty())
	{
		cur = qu.front();
		cur1 = cur.first;
		x = cur1.first;
		y = cur1.second;
		if (cur1 == to)
		{
			cout << "To get from " << a << " to " << b << " takes " << cur.second << " knight moves." << endl;
			break;
		}
		qu.pop();
		for (int i = 0; i < 8; i++)
		{
			dx = x + dir[i][0];
			dy = y + dir[i][1];
			if (dx < 1 || dx>8 || dy < 1 || dy>8)
				continue;
			if (vis[dx][dy])
				continue;
			vis[dx][dy] = 1;
			qu.push(make_pair(make_pair(dx, dy),cur.second+1));
		}
		
	}

	return 0;
}