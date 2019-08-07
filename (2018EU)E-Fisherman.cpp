#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
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
const int N = 2e5 + 9;
typedef int ll;
struct BaseFenwick
{
	vector<ll> v;
	BaseFenwick(int n) : v(n, 0) {}
	void add(int x, ll w)
	{
		for (; x < v.size(); x += x & -x)
			v[x] += w;
	}
	ll ask(int x)
	{
		ll ans = 0;
		for (; x; x -= x & -x)
			ans += v[x];
		return ans;
	}
};
struct Point
{
	int x, y, id;
	bool operator<(const Point &rhs) const
	{
		if (x != rhs.x)
			return x < rhs.x;
		if (y != rhs.y)
			y < rhs.y;
		return id < rhs.id;
	}
};
struct Ranker : vector<int>
{
	void init()
	{
		sort(begin(), end()), resize(unique(begin(), end()) - begin());
	}
	int ask(int y)
	{
		return lower_bound(begin(), end(), y) - begin();
	}
} rk;
int n, m, l, ans[N];
int main()
{
	vector<Point> p;
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0, x, y; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		p.push_back({ y + x, y - x, -1 });
	}
	for (int i = 0, x; i < m; ++i)
	{
		scanf("%d", &x);
		p.push_back({ l + x, l - x, i });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); ++i)
		rk.push_back(p[i].y);
	rk.init();
	BaseFenwick t(rk.size() + 9);
	for (int i = 0, j = 0; i < p.size(); ++i)
	{
		for (; p[j].x < p[i].x - l * 2; ++j)
			if (p[j].id < 0)
				t.add(rk.ask(p[j].y) + 1, -1);
		if (p[i].id < 0)
			t.add(rk.ask(p[i].y) + 1, 1);
		else
			ans[p[i].id] = t.ask(rk.ask(p[i].y) + 1) - t.ask(rk.ask(p[i].y - l * 2));
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
}


