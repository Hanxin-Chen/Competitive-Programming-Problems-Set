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
#define N 50003
int c[N],ans[N];
int n,m,maxnum;
map<int, int>ma;

int lowbit(int t)
{
	return t & (-t);
}

void update(int x, int val) {

	while (x>0)
	{
		ma[x] += val;
		x -= lowbit(x);
	}
}

int getsum(int x) {
	int ans = 0;
	while (x<=maxnum)
	{
		ans += ma[x];
		x += lowbit(x);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int t,k=0;
	int a, b;
	cin >> t;
	while (t--)
	{
		k++;
		maxnum = 0;
		ma.clear();
		cin >> n >> m;
		printf("Case #%d:\n", k);
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			maxnum = max(max(maxnum, a), b);
			update(b, 1);
			update(a - 1, -1);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a;
			cout << getsum(a) << endl;
		}
	}
	return 0;
}

