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
using namespace std;
#define N 1000
#define inf 1<<30;
int a[N];
int dp[N];
int c[N];
int ccount;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int k;
	int m;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	//优化
	c[0] = -inf;
	ccount = 1;
	for (int i = 0;i < n;i++)
	{
		//在c中查找第一个比i大的元素下标
		k = upper_bound(c, c + ccount, a[i])-c;
		dp[i] = k;
		c[k] = a[i];
		if (k >= ccount)
			ccount++;
	}
	cout << ccount-1 << endl;
	for (int i = 1;i < ccount;i++)
		cout << c[i] << " ";
	cout << endl;
	return 0;
}