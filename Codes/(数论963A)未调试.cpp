#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include<vector>
#include<queue>
#include <set>
#include <ctime>
using namespace std;
typedef long long ll;
//快速幂模运算
#define MOD 1000000009
#define K 100004
int n, a, b, k,s[K];
long long pow1(long long a, long long n)
{
	if (n == 0)
		return 1;
	long long tmp = pow1(a, n >> 1);
	if (n % 2 == 1)
	{
		return (a * tmp * tmp) % MOD;
	}
	else
	{
		return tmp * tmp % MOD;
	}
}
long long inv(long long a, long long m) {
	while (a < 0)
	{
		a += m;
	}
	a %= m;
	return a == 1 ? 1 : (m - m / a) * inv(m % a, m) % m;
}


int main()
{
	ios::sync_with_stdio(false);
	char ch;
	ll a1 = 0;
	cin >> n >> a >> b >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> ch;
		if (ch == '+')
			s[i] = 1;
		else if (ch == '-')
			s[i] = -1;
	}
	for (int i = 0; i < k; i++)
	{
		a1 = (a1 + s[i] * pow1(a, n - 1) % MOD*pow1(b, i) % MOD + MOD) % MOD;
	}
	int n1 = (n + 1) / k;
	long long q = pow1(b, k)*pow1(inv(a, MOD), k) % MOD;
	if (q == 1)
	{
		cout << n1 * a1%MOD;
		return 0;
	}
	long long ret;
	ret = a1 * (pow1(q, n1))%MOD*inv(q-1,MOD)%MOD;
	cout << ret << endl;
	return 0;
}
