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
#define N 21
#define M 50005
long long prime[M], check[M];
int tot = 0,n;
/*
	1/x+1/y=1/n;
	令y=n+k;则x=n^2/k+n,则x是整数，k是n平方的因子
	n可以分解为多个素数的幂次方相乘，n=(p1^e1)(p2^e2)(p3^e3)...
	则总数 num=(1+e1)(1+e2)(1+en)..
	则n^2的素因数为num=(1+2*e1)(1+2*e2)(1+2*en)..
*/

void ogprime()
{
	for (int i = 2;i < M;i++)
	{
		if (!check[i])
		{
			prime[tot++] = i;
		}
		for (int j = 0;j < tot;j++)
		{
			if (prime[j] * i >= M)
				break;
			check[prime[j] * i] = 1;
			if (prime[j] != 0)
				if (i%prime[j] == 0)
					break;
		}

	}

}
int main()
{
	ios::sync_with_stdio(false);
	ogprime();
	int t;
	cin >> t;
	for (int  tcase = 1; tcase <= t; tcase++)
	{
		cin >> n;
		printf("Scenario #%d:\n", tcase);
		if (n == 0)
		{
			cout << "0" << endl;
			cout << endl;
			continue;
		}
		int sum = 1;
		int tmp = sqrt(n);
		for (int i = 0;i < tot;i++) 
		{
			int sign = 0;
			if (prime[i] > tmp)
									break;
			while (n%prime[i]==0)
			{
				sign++;
				n = n / prime[i];
			}
			sum *= (2 * sign + 1);
		}
		if (n > 1)
			sum *= 3;      //防止素因数为其本身
		cout << (sum + 1) / 2 << endl;
		cout << endl;
	}
	return 0;
}

