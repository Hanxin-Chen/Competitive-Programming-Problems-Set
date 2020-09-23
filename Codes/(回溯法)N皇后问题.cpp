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
#define N 15
int n;
int x[N], ret[N],ans=0;

bool canput(int row, int col)
{
	int i;
	for (i = 1;i < col;i++)
		if (x[i] == row || abs(row - x[i]) == abs(col - i))
			return false;
	return true;
}

void dfs(int dep)
{
	int i;
	if (dep > n) {
		ans++;
		return;
	}
	for (i = 1;i < n+1;i++)
	{
		if (canput(i, dep))
		{
			x[dep] = i;
			dfs(dep + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 1;i <= 10;i++)
	{
		ans = 0;
		n = i;
		dfs(1);
		ret[i] = ans;
	}
	while (cin>>n,n)
	{
		cout << ret[n] << endl;
	}
	
	return 0;
}
