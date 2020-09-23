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
long long qpow(long long a, long long n, long long p)
{
	if (n == 1)
		return a;
	long long tmp;
	tmp = qpow(a, n >> 1, p);
	if (n & 1)
		return a * tmp%p*tmp%p;
	else
		return tmp % p * tmp%p;
}

bool isprime(int x)
{
	long long a;
	srand(time(NULL));
	if (x == 2)
		return true;
	for (int i = 0;i < 4;i++)
	{
		a = rand() % (x - 2) + 2;  //2~x-1
		if (qpow(a, x - 1, x) % x != 1)
			return false;
	}
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		int cnt = 0;
		int a;
		for (int i = 0;i < n;i++)
		{
			cin >> a;
			if (isprime(a))
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
