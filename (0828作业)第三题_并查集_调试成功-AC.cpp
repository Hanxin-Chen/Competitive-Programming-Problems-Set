#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>                                                
#include<cstdio>                                                   
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cctype>
#include<sstream>
#include<queue>

/*
  并查集，从后往前思考，注意数据类型 long long 
  priority_queue 优先队列的应用-----
 */
using namespace std;
typedef long long ll;
#define N 100005
ll a[N], b[N], ret[N], vis[N];
int n;
struct node
{
	ll parent;
	ll sum;
	node() :sum(0) {
	}
}da[N];

ll find(ll x)
{
	if (x == da[x].parent)
		return x;
	da[x].parent = find(da[x].parent);  //路径优化
	return da[x].parent;
}

void Union(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x != y)
	{
		da[x].parent = y;
		da[y].sum += da[x].sum;
	}

}

void ini()
{
	for (int i = 1;i <= n;i++)
	{
		da[i].parent = i;
		da[i].sum = a[i];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		memset(b, 0, sizeof(b));
		memset(ret, 0, sizeof(ret));
		for (int i = 1;i <= n;i++)
		{
			scanf_s("%lld", &a[i]);
			//da[i].sum = a[i];
		}
		for (int i = 0;i < n;i++)
			scanf_s("%lld", &b[i]);
		ini();
		ll kk;
		ret[n - 1] = 0;
		priority_queue<ll>pq;
		for (int i = n - 1;i > 0;i--)
		{
			pq.push(da[b[i]].sum);
			if (b[i] > 1 && vis[b[i] - 1])
			{
				Union(b[i], b[i] - 1);
				kk = find(b[i]);
				pq.push(da[kk].sum);
			}
			if (b[i] < n && vis[b[i] + 1])
			{
				Union(b[i], b[i] + 1);
				kk = find(b[i]);
				pq.push(da[kk].sum);
			}

			ret[i - 1] = pq.top();
			vis[b[i]] = 1;
		}
		for (int i = 0;i < n;i++)
			printf("%lld\n", ret[i]);
			//cout << ret[i] << endl;
	}
	return 0;
}