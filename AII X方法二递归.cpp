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
long long pow1(long long int n,long long int mod)
{
	if (n == 0)
		return 1;
	long long int tmp = pow1( n >>1, mod);
	if (n % 2 == 1)
	{
		return (10 * tmp * tmp) % mod;
	}
	else
	{
		return tmp * tmp % mod;
	}

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