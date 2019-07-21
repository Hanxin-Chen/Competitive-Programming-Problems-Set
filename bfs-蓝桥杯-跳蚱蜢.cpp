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
struct node
{
	string order;
	int pos,step;
	node():pos(0),step(0){}
};
int d[4] = { -1,-2,1,2 };
bool judge(node a) {
	if (a.order == "087654321")
		return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	node tmp;
	tmp.order = "012345678";
	tmp.pos = 0;
	queue<node> q;
	q.push(tmp);
	int ans = 0xfffffff;
	map<string,int> ma;
	ma[tmp.order]++;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (judge(tmp)) {
			ans = min(ans, tmp.step);
		}
		for (int i = 0; i < 4; i++)
		{
			node tmp2 = tmp;
			swap(tmp2.order[tmp2.pos], tmp2.order[(tmp2.pos + d[i] + 9) % 9]);
			tmp2.pos = (tmp2.pos + d[i] + 9) % 9;
			tmp2.step++;
			if (ma[tmp2.order] == 0)
			{
				q.push(tmp2);
				ma[tmp2.order]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}