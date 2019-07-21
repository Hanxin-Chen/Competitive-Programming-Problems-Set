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
#define M 1000001
long long prime[M];
int tot = 0;
//素数筛法
void prime1()
{
	for (int i = 2;i < M;i++)
	{
		if (prime[i] == 0)          //判断i是不是素数
		{
			tot++;                  //如果是素数，则位置+1
			for (int j = i;j < M;j += i)   //则i的倍数都不是素数
				prime[j] = tot;           //更新答案为当前位置
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	prime1();
	while (scanf_s("%d",&n)!=EOF)
	{
		printf("%d\n", prime[n]);
	}
	return 0;
}
