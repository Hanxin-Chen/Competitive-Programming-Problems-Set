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
int n;

int lowbit(int t)
{
	return t & (-t);
}

void update(int x, int val) {

	while (x<32005)
	{
		c[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x) {
	int ans = 0;
	while (x>0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int x, y;
	while (cin >> n)
	{
		memset(c, 0, sizeof(c));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			x++;
			ans[getsum(x)]++;
			update(x, 1);
		}
		
		for (int i = 0; i < n; i++)
		{
			cout << ans[i] << endl;
		}
	}
	return 0;
}

