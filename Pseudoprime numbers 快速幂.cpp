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
#include<ctime>
using namespace std;

int isprime(__int64 m)
{
	for (__int64 i = 2; i <=sqrt(m); i++)      //建议用  i*i<m 速度较快
	{
		if (m%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int qpow(__int64 a, __int64 b)
{
	__int64 tmp = a, res = 1, mod = b;
	while (b)
	{
		if (b & 1)
		{
			res = res * tmp%mod;
		}
		tmp = tmp * tmp%mod;
		b = b >> 1;
	}
	if (res == a)
		return 1;
	else
		return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	__int64 p, a;
	while (cin>>p>>a&&(p!=0||a!=0))
	{
		if (!isprime(p) && qpow(a, p))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}