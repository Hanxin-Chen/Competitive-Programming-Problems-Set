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
typedef  long long ll;
long long  c[N],attack[N];
int n,m,k;

ll lowbit(ll t)
{
	return t & (-t);
}

void update(ll x, ll val) {

	while (x>0)
	{
		c[x] += val;
		x -= lowbit(x);
	}
}

long long  getsum(ll x) {
	long long ans = 0;
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
		scanf("%d", &m);
		ll  a, b,val,ans=0;
		memset(c, 0, sizeof(c));
		memset(attack, 0, sizeof(attack));
		for (int i = 0; i < m; i++)
		{
			scanf("%I64d %I64d %I64d", &a,&b,&val);
			update(b, val);
			update(a - 1, -val);
		}
		cin >> k;
		for (int i = n; i > 0; i--)
		{
			attack[i] = attack[i + 1] + getsum(i);
		}
		for (int i = 0; i < k; i++)
		{
			scanf("%I64d %I64d", &a, &b);
			if (a > attack[b])
				ans++;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

