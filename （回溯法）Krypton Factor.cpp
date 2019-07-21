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
#define N 100
int n, k;
int cnt = 0;
int flag = 1;
char a[N];

bool check(int num)
{
	int x = (num + 1) / 2;
	for (int i = 1;i <= x;i++)
	{
		int flag = 1;
		for (int j = num;j >= num + 1 - i && flag;j--)
		{
			if (a[j] != a[j - i])
				flag = 0;
		}
		if (flag)
			return false;
	}
	return true;
}

void dfs(int dep)
{
	if (cnt++ == n)
	{
		for (int i = 0;i < dep;i++)
		{
			cout << a[i];

			if ((i + 1) % 4 == 0 && i != dep - 1 && (i + 1) % 64 != 0)
				cout << " ";
			if ((i + 1) % 64 == 0 && i<dep-1)
				cout << endl;
		}
		cout << endl;
		cout << dep << endl;
		flag = 0;
		return;
	}
	if (flag)
	{
		for (int i = 0;i < k;i++)
		{
			a[dep] = i + 'A';
			if (check(dep))
				dfs(dep + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>k && (n!=0||k!=0) )
	{
		cnt = 0;
		flag = 1;
		dfs(0);
	}
	return 0;
}
