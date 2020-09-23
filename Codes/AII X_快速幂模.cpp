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
long long int x;
long long int m;
long long int k, c,xmod;
long long pow1(long long int m,long long int mod)
{
	long long  res = 1;
	long long  tmp = 10;
	while (m)
	{
		if (m & 1)
		{
			res *= tmp;
			res %= mod;
		}
		tmp *= tmp;
		tmp %= mod;
		m >>= 1;
	}
	return res;

}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		printf("Case #%d:\n", ++cnt);
		cin >> x >> m >> k >> c;
		k = 9 * k;
		xmod = (pow1( m, k) - 1 + k) % k;
		xmod = (xmod * x)%k;
		if (xmod == (c*9)%k)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}