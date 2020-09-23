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
	ll a, b, c,a1,a2,b1,b2,L,R;
	ll cnt = 0;
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	a = a1, b = -a2, c = b2 - b1;
	ll x = 0, y = 0;
	ll d = extend_gcd(a, b, x, y);
	ll m = a / d;
	ll n = b / d;
	ll g = c / d;
	if (c%d || L>R)
	{
		cout << "0" << endl;
		return 0;
	}
	ll ans;
	for (ll i = min(((L-b1-a*x*c/d)*d/b/a), ((R -b1- a*x*c/d)*d/b/a)); i <= max(((L -b1- a * x*c / d)*d / b / a), ((R -b1- a * x*c / d)*d / b / a)); i++)
	{
		ans = a*x * c / d + a*i * b / d+b1;
		if (ans >= L && ans <= R &&(x * c / d +   i * b / d)>=0 && (ans-b2)/a2>=0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
