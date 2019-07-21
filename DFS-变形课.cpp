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
//#pragma warning(disable:4996);
using namespace std;
struct node
{
	char head, end;
}a[10000];
int ans=0;
int vis[10000];
int cnt = 0;

void dfs(char x) {
	if (x == 'm') {
		ans = 1;
		return;
	}
	if (ans)
		return;
	for (int i = 0; i < cnt; i++)
	{
		if (vis[i])
			continue;
		if (a[i].head ==x ) {
			vis[i] = 1;
			dfs(a[i].end);
			vis[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	while (cin >> str)
	{
		if (str == "0")
			continue;
		ans = 0;
		cnt = 0;
		a[0].head = str[0];
		a[0].end = str[str.size() - 1];
		cnt++;
		while (cin >> str, str != "0")
		{
			a[cnt].head = str[0];
			a[cnt].end = str[str.size() - 1];
			cnt++;
		}

		for (int i = 0; i < cnt; i++)
		{
			if (a[i].head == 'b')
			{
				memset(vis, 0, sizeof(vis));
				vis[i] = 1;
				dfs(a[i].head);
			}
			if (ans)
				break;
		}
		if (ans == 1) {
			printf("Yes.\n");
		}
		else
		{
			printf("No.\n");
		}
	}
	return 0;
}