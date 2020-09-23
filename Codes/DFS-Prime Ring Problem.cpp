#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
#include <map>
#include <ctime>
#include <sstream>
//#pragma warning(disable:4996);
using namespace std;
#define M 1000
int n;
int a[25], vis[25], check[M];

void gprime()
{
	for (int i = 2; i < M; i++)
	{
		if (!check[i])
		{
			for (int j = 2; i*j < M; j++)
				check[i*j] = 1;
		}
	}
}

void dfs(int s)
{
	if (s == n && check[a[1] + a[n]]==0)  
	{
		for (int i = 1; i < n; i++)
			cout << a[i] << " ";
		cout << a[n] << endl;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (!vis[i] && check[i + a[s]]==0)  
			{
				a[s + 1] = i;
				vis[i] = 1;         
				dfs(s + 1);
				vis[i] = 0;            
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	gprime();
	while (cin>>n)
	{
		a[1] = 1;
		printf("Case %d:\n", ++t);
		memset(vis, 0, sizeof(vis));
		//clock_t str, end;
		//str = clock();
		dfs(1);
		cout << "\n";
		//end = clock();
		//double time = (double)(end - str)/CLOCKS_PER_SEC;
		//cout << time << endl;
	}
	return 0;
}