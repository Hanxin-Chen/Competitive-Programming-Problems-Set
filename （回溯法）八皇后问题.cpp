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
#define N 9
int x[N],ans=0;

bool canput(int row, int col)
{
	int i;
	for ( i = 1;i < col;i++)
		if (x[i] == row || abs(row-x[i])==abs(col-i))
			return false;
	return true;
}

void dfs(int dep)
{
	int i;
	if (dep > 8) {
		for (i = 1;i < 9;i++)
			cout << x[i] << " ";
		cout << endl;
		ans++;
		return;
	}
	for ( i = 1;i < 9;i++)
	{
		if (canput(i,dep)) 
		{
			x[dep] = i;
			dfs(dep + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	dfs(1);
	cout << ans << endl;
	return 0;
}
