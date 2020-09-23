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
int a[N];
int dp[N];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int k;
	int m;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	dp[0] = 1;
	for (int i = 1;i < n;i++)
	{
		m = 0;
		for (k = 0;k < i;k++)
			if (a[i] >= a[k] && dp[k] > m)
				m = dp[k];
		dp[i] = m + 1;
	}
	m = dp[0];
	for (int i = 0;i < n;i++)
		if (m < dp[i])
			m = dp[i];
	cout << m << endl;
	m = 1;
	for(int i=0;i<n;i++)
		if (dp[i] == m)
		{
			cout << a[i] << " ";
			m++;
		}
	return 0;
}