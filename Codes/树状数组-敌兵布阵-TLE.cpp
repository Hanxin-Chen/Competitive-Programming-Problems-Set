#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
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
using namespace std;
#define N 50005
int a[N],c[N];
int n;

int lowbit(int t)
{
	return t & (-t);
}

int getsum(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += c[i];
	return ans;
}

void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += y;
}

void sub(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] -= y;
}


void ini() {
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j =1; j<=i; j++)
		{
			if (i - lowbit(i) + j > i)
				break;
			tmp += a[i - lowbit(i) + j];
		}
		c[i] = tmp;
	}
}

void query(int a,int b)
{
	int ret;
	ret = getsum(b) - getsum(a - 1);
	cout << ret << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int i1, j1;
	int t,cnt=0;
	cin >> t;
	string order;
	
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		printf("Case %d:\n", ++cnt);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		ini();
		while (cin >> order, order != "End")
		{
			cin >> i1 >> j1;
			if (order == "Add")
			{
				add(i1, j1);
			}
			else if (order == "Sub")
			{
				sub(i1, j1);
			}
			else if (order == "Query")
			{
				query(i1, j1);
			}
		}
	}
	return 0;
}

