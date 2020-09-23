#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include<vector>
#include<queue>
#include <set>
#include <windows.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

ll extend_gcd(ll a, ll b, ll& x, ll &y)
{
	ll m;
	if (a == 0 && b == 0)
		return -1;
	else if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	m = extend_gcd(b, a%b, x, y);
	ll tmp = x;
	x = y, y = tmp - (a / b)*y;
	return m;
}

int main()
{
	ios::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	ll x = 0, y = 0;
	ll d = extend_gcd(a, b, x, y);
	if (c%d != 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	ll m = a / d;
	ll n = b / d;
	ll g = c / d;
	ll ansx = -g * x + n;
	ll ansy = -g * y - m;
	cout << ansx << " " << ansy;
	return 0;
}