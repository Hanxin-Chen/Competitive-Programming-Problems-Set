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
using namespace std;
#define N 100005
int a[N], b[N], ret[N], vis[N];
int n;
struct node
{
	int parent;
	int sum;
	node() :sum(0) {

	}
}da[N];

int find(int x)
{
	if (x == da[x].parent)
		return x;
	da[x].parent = find(da[x].parent);
	return da[x].parent;
}

void Union(int x, int y) {
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
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		memset(b, 0, sizeof(b));
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			//da[i].sum = a[i];
		}
		for (int i = 0;i < n;i++)
			cin >> b[i];
		ini();
		int kk;
		ret[n - 1] = 0;
		priority_queue<int>pq;
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
			cout << ret[i] << endl;
	}
	return 0;
}