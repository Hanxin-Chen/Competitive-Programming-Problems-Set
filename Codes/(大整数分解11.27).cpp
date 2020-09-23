#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

ll mod(ll a, ll b, ll c)
{
	ll ret = 0, t = a;
	while (b)
	{
		if (b & 1) ret += t;
		ret %= c;
		t <<= 1;
		t %= c;
		b >>= 1;
	}
	

	return ret;
}

ll factor(int n,int k)
{
	ll x1 = rand() % n,p;
	ll x2;
	while (1)
	{
		x2 = (mod(x1, x1, n) + k) % n;
		p = gcd(abs(x2 - x2), n);
		if (p > 1)
			return p;
		if (x2 == x1)
			return -1;
		if (p == n)
			return 0;
		x1 = x2;
	}
}
ll f[100];
int cnt = 0;

void all_factor(ll n)
{
	ll p;
	p=factor(n, 1);
	if (p == 0) //nÊÇËØÊý
	{
		f[cnt++] = n;
	}
	else if (p > 1)
	{
		all_factor(p);
		all_factor(n / p);
	}
	else
	{
		all_factor(n);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	all_factor(1000);
	for (int i = 0; i < cnt; i++)
	{
		cout << f[i] << endl;
	}
	return 0;
}
