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
int c[N];
int n;

int lowbit(int t)
{
	return t & (-t);
}

void update(int x, int val) {

	while (x>0)
	{
		c[x] += val;
		x -= lowbit(x);
	}
}

int getsum(int x) {
	int ans = 0;
	while (x<=n)
	{
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n,n)
	{
		int a, b;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			update(b, 1);
			update(a - 1, -1);
		}
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				cout << " ";
			cout << getsum(i);
		}
		cout << endl;
	}
	return 0;
}

