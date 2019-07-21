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
#define N 100050
int x[N];
int main()
{
	ios::sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--)
	{
		memset(x, 0, sizeof(N));
		cin >> n >> k;
		for (int i = 0;i < n;i++)
			cin >> x[i];
		sort(x, x + n);
		__int64 ans = 0;
		int p = 0;
		for (int c = 0; c<n; c++)		
		{
			while (x[p] - x[c] <= k && p<n) ++p;
			ans = ans + p - c - 1;
		}
		cout << ans << endl;
	}
	return 0;
}