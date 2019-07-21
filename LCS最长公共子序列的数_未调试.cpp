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
#include<queue>
using namespace std;
#define N 1000
#define M 1000
string a, b;
int f[N][M];
int n, m;
char x[N];
int cnt = 0;

void dfs(int i, int j)
{
	if (i == 0 || j == 0)
	{
		for (int k = 0;k < n;k++)
			cout << x[k] << " ";
		cout << endl;
		return;
	}
		
	if (a[i] == b[j])
	{
		x[cnt++] = a[i];
		dfs(i - 1,j - 1);
		cnt--;
	}
	else {
		if (f[i - 1][j] > f[i][j - 1])
			dfs(i - 1, j);
		else if (f[i - 1][j] < f[i][j - 1])
			dfs(i, j - 1);
		else
		{
			dfs(i - 1, j);
			dfs(i, j - 1);
		}
	}
}
int main()
{
	dfs(n, m);
	return 0;
}