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
#include <Windows.h>
using namespace std;
#define N 200003
struct node
{
	int x, y;
	int type;
}order[N];
int n,xi[N],m,maxy[4*N],k;
set<int>yi[N];

void push_up(int rt) {
	maxy[rt] = max( maxy[rt << 1], maxy[rt << 1 | 1 ] );
}

void update(int left, int right, int rt, int k, int v) {
	if (left == right) {
		maxy[left] = v;
		yi[left].insert(v);
		return;
	}
	int mid = (left + right) >> 1;
	if (k <= m)
		update(left, mid, rt << 1, k, v);
	else
		update(mid+1, right, rt << 1 | 1, k, v);
	push_up(rt);
}

void update_remove(int left, int right, int rt, int k, int v) {
	if (left == right) {
		yi[left].erase(v);
		if (yi[left].empty())
		{
			maxy[left] = 0;
		}
		else
			maxy[left] = *(yi[left].end()--);
		return;
	}
	int mid = (left + right) >> 1;
	if (k <= m)
		update(left, mid, rt << 1, k, v);
	else
		update(mid+1, right, rt << 1 | 1, k, v);
	push_up(rt);
}

int query(int left, int right, int rt, int k, int v) {
	int ret;
	if (maxy[rt] <= v) {
		return -1;
	}
	if (left == right) {
		return left;
	}
	int mid = (left + right) >> 1;
	if (mid < k) {
		ret=query(mid + 1, right, rt << 1 | 1, k, v);
	}
	else
	{
		int t=query(left, mid, rt << 1, k, v);
		if(t==-1)
			ret=query(mid + 1, right, rt << 1 | 1, k, v);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	string ord;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ord;
		if (ord == "add")
			order[i].type = 0;
		else if(ord=="remove")
			order[i].type = 1;
		else 
			order[i].type = 2;
		cin >> order[i].x >> order[i].y;
		xi[i] = order[i].x;

	}
	sort(xi, xi + n);
	m = unique(xi, xi + n) - xi; //去重，返回不重复的元素的地址，减去xi可得到数量m
	for (int i = 0; i < n; i++)
	{
		if (order[i].type == 0) {  //add
			k = lower_bound(xi, xi + m,order[i].x)-xi;
			update(0, m - 1, 1, k, order[i].y);
		}
		else if (order[i].type == 1) {  //remove
			update_remove(0, m - 1, 1, k, order[i].y);
		}
		else {   //find
			k=query(0, m - 1, 1, k+1, order[i].y);
			cout << xi[k] << " " << *yi[k].upper_bound(order[i].y) << endl;
		}
	}
	return 0;
}


