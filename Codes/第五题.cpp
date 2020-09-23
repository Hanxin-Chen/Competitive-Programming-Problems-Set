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
#define N 1000005
using namespace std;
int a[N];

int judge(__int64 k)
{
	int i;
	if (k <= 512)
		i = 0;
	else if (k <= 524288)
		i = 10;
	else
		i = 20;
	for (;pow(2, i) <= k;i++)
	{
		if (k == pow(2, i))
			return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	__int64 t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int cnt = 0;
		__int64 sum;
		for (int i = 0;i < n;i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum = a[i] + a[j];
				if (judge(sum))
					cnt++;
			}
		}
		cout << cnt << endl;

	}
	return 0;
}
