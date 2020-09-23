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
#define N 100003
int a[N],c[N];
int n;

int lowbit(int t)
{
	return t & (-t);
}

int getsum(int x)
{
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
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
	int ans=0;
	/*for (int i = b; i > 0; i -= lowbit(i))
		ans += c[i];
	for (int i = a-1; i > 0; i -= lowbit(i))
		ans -= c[i];*/
	ans = getsum(b) - getsum(a - 1);
	printf("%d\n", ans);
}


void  modify(int x, int add) {
	while (x <= n) {
		c[x] += add;
		x += lowbit(x);
	}
}


int sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
void get(int x, int y) {
	 int ans= sum(y) - sum(x - 1);
	printf("%d\n", ans);
}


int main()
{
	ios::sync_with_stdio(false);
	int i1, j1;
	int t,cnt=0;
	scanf("%d", &t);
	
	while (t--)
	{
		cnt++;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			//modify(i, a[i]);
		}
		printf("Case %d:\n", cnt);
		ini();
		string order;
		while (cin >> order, order != "End")
		{
			scanf("%d %d", &i1,&j1);
			if (order == "Add")
			{
				add(i1, j1);
			}
			else if (order == "Sub")
			{
				//a[i1] += j1;
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

