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
//������ģ����
#define MOD 1000000009
#define K 100004
int n, a, b, k,s[K];

bool isprime(int x)
{
	if (!(x & 1) && x != 2)
		return false;
	else if (x == 2)
		return true;
	for (int i = 3; i*i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

long long pow1(long long a, long long n)
{
	if (n == 0)
		return 1;
	long long tmp = pow1(a, n >> 1);
	if (n % 2 == 1)
	{
		return (a%MOD * tmp%MOD * tmp%MOD) % MOD;
	}
	else
	{
		return tmp%MOD * tmp % MOD;
	}
}
long long inv(long long a, long long m) {
	
	return a == 1 ? 1 : (m - m / a) * inv(m % a, m) % m;
}


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (!isprime(n) && n != 4)
	{
		cout << "NO" << endl;
		return 0;
	}
	else if (n == 4)
	{
		cout << "YES" << endl;
		cout << "1\n3\n2\n4" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1; i < n; i++)
	{
		if (i > 1)
			cout << i * inv(i-1,n)%n << endl;
		else
			cout << i << endl;
	}
	cout << n << endl;
	return 0;
}
