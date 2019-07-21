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
typedef long long ll;
int c[N], ans[N];
ll n, q;
ll er[63] = { 1 };
ll lowbit(ll t)
{
	return t & (-t);
}

ll cal(ll n)
{
	ll ans = 0, x;
	for (ll i = 0; (1ll << i) <= n; i++)
	{
		x = (1ll << i);
		ans += (n / x - n / (x * 2))*(1ll << i);
	}
	return ans;
}

void update(int x, int val) {

	while (x > 0)
	{
		c[x] += val;
		x -= lowbit(x);
	}
}

int getsum(int x) {
	int ans = 0;
	while (x <= n)
	{
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int type;
	ll a, b;
	while (scanf("%lld %lld", &n, &q) != EOF)
	{
		while (q--)
		{
			scanf("%d", &type);
			ll ans = 0;
			if (type == 1) {
				//cin >> a >> b;
				scanf("%lld %lld", &a, &b);
				ans = cal(b) - cal(a - 1);
			}
			else if (type == 2) {
				//cin >> a;
				scanf("%lld", &a);
				while (a <= n)
				{
					a += lowbit(a);
					ans++;
				}
			}
			//cout << ans << endl;
			printf("%lld\n", ans);
		}
	}
	return 0;
}

