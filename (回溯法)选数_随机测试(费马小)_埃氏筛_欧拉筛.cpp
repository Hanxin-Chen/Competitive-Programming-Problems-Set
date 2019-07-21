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
#define M 100004
#define N 7
int a[] = { 12,27,3,4,5,6 };
int x[N];
int vis[N];
int n = 6;
int k = 3;
int cnt = 0;
int sum = 0;
//埃氏筛法
long long prime[M],check[M];
int tot = 0;
void gprime()
{
	for (int i = 2;i < M;i++)
	{
		if (!check[i])
		{
			prime[tot++] = i;
			for (int j = 2;i*j < M;j++)
				check[i*j] = 1;
		}
	}
}
//欧拉筛法
void ogprime()
{
	for (int i = 2;i < M;i++)
	{
		if (check[i])
		{
			prime[tot++] = i;
		}
		for (int j = 0;j < tot;j++)
		{
			if (prime[j] * i >= M)
				break;
			check[prime[j] * i] = 1;
			if (i%prime[j] == 0)
				break;
		}
		
	}
}

//随机测试
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

bool isprime1(int x)
{
	long long a;
	srand(time(0));
	for (int i = 0;i < 4;i++)
	{
		a = rand() % (x - 2) + 2;  //2~x-1
		if (qpow(a, x - 1,x) % x != 1)
			return false;
	}
	return true;
}
//普通版本
bool isprime(int x)
{
	if (!(x & 1) && x != 2)
		return false;
	else if(x==2)
		return true;
	for (int i = 3;i*i <= x;i+=2)
		if (x % i == 0)
			return false;
	return true;
}

void dfs(int st,int dep)
{
	if (dep >= k)
	{
		sum = 0;
		for (int i = 0;i < k;i++)
			sum += x[i];
		//素数的判定
		if (isprime(sum))
			cnt++;
		return;
	}
	for (int i = st;i < n;i++)
	{
		x[dep] = a[i];
		dfs(i+1,dep + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	gprime();
	dfs(0,0);
	cout << cnt << endl;
	return 0;
}
