#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
using namespace std;
#define N 50003
int tree[N << 2];
int a[N];

void push_up(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void build(int left, int right, int rt)
{
	if (right == left)
	{
		tree[rt] = a[left];
	}
	int mid = (left + right) >> 1;
	build(left, right, rt << 1);
	build( mid + 1,right, rt << 1 |1);
	push_up(rt);
}

void update(int left, int right, int rt, int k, int v)
{
	if (left == right)
	{
		tree[rt] += v;

	}
	int mid = (left + right) >> 1;
	if (k <= mid)
		update(left, mid, rt << 1, k, v);
	else
		update(mid + 1, right, rt << 1 | 1, k, v);
	push_up(rt);
}

int query(int left, int right, int rt, int l, int r)
{
	if (left == l && right == r)
	{
		return tree[rt];
	}
	int mid = (left + right) >> 1;
	int ret = 0;
	if (r <= mid)
		ret+=query(left, mid, rt << 1, l, r);
	else if (l >= mid)
		ret+=query(mid + 1, right, rt << 1 | 1, l, r);
	else {
		ret+=query(left, mid, rt << 1, l, mid);
		ret+=query(mid + 1, right, rt << 1 | 1, mid + 1, r);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int i1, j1;
	string order;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(0, n - 1, 1);
	while (cin>>order,order!="END")
	{
		cin >> i1 >> j1;
		if (order == "Add")
		{
			update(0, n - 1, 1,i1,j1);
		}
		else if (order == "Sub")
		{
			update(0, n - 1, 1, i1, -j1);
		}
		else if (order == "Query")
		{
			query(0, n - 1, 1, i1, j1);
		}
	}
	return 0;
}


