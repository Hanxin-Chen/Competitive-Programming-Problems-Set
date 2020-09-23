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
#define M 1005
#define inf 1<<30
struct node
{
	int weight;
	int speed;
	int pos;
	int po2;
	bool operator <(node n1)const {
		return weight < n1.weight;
	}
}mice[M];

int dp[M];
int c[M];

void pr(int n)
{
	if (mice[n].po2)
		pr(mice[n].po2);
	cout << mice[n].pos << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	int cnt = 1;
	int x, y;
	int a;
	int ans = 0;
	while (cin>>x>>y)
	{
		a = cnt++;
		mice[a].weight = x;
		mice[a].speed = y;
		mice[a].pos = a;
		mice[a].po2 = 0;
	}
	mice[0].speed = inf;
	sort(mice+1, mice + cnt);
	dp[0] = 0;
	for (int i = 1;i < cnt;i++)
	{
		for (int j = 0;j < i;j++)
		{
			if (mice[i].speed<mice[j].speed && mice[i].weight>mice[j].weight)
				if (dp[j]+1 > dp[i])
				{
					dp[i] = dp[j] + 1;
					mice[i].po2 = j;
				}
		}
		if (dp[i] > dp[ans])
			ans = i;
	}
	cout << dp[ans] << endl;
	pr(ans);
	return 0;
}
