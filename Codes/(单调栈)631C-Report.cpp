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
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
#define N 200005
int m, n, a[N],ans[N];
vector<pair<int, int> >p;
//631/problem/C
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int order, num;
	int order1 = 0, order2 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		//cin >> a[i];
		scanf("%d", &a[i]);
	}
	//直接从最大的一部开始记录，之前较小的部分在大排序中会重新排序
	for (int i = 0; i < m; i++)
	{
		//cin >> order >> num;
		scanf("%d %d", &order, &num);
		pair<int, int> tmp = make_pair(order, num);
		while (!p.empty() && p[p.size() - 1].second <= num) {
			p.pop_back();
		}
		p.push_back(tmp);
	}
	int left=0, right=p[0].second-1;
	for (int i = right+1; i < n; i++)
	{
		ans[i] = a[i];
	}
	sort(a, a + right+1);
	p.push_back(make_pair(1, 0));

	//如过把当前有效操作都进行一次排序，依然会超时
	//p是一个递减序列，则每次更新p[i]-p[i+1]之间的元素
	//1选择n个最大的元素，2选择n个最小的元素
	for (int i = 0; i < p.size()-1; i++)
	{
		order = p[i].first;
		num = p[i].second-p[i+1].second;
		if (order == 1) {
			for (int j = p[i].second-1; j > p[i+1].second-1; j--) {
				ans[j] = a[right];
				right--;
			}
		}
		else {
			for (int j = p[i].second - 1; j > p[i + 1].second - 1; j--) {
				ans[j] = a[left];
				left++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << ans[i];
		if (i == n - 1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}


