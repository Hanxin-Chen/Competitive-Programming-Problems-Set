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
long long int n, m;
struct ROAD
{
	int len;
	int robber;
}road[10005];
bool cmp(ROAD a, ROAD b)
{
	return a.robber > b.robber;
}
int main()
{
	ios::sync_with_stdio(false);
	long long int ans;
	while (cin>>n>>m&&(n!=0||m!=0))
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> road[i].len >> road[i].robber;
			ans += road[i].len*road[i].robber;
		}
		sort(road, road + n, cmp);
		for (int i = 0; i < n; i++)
		{
			if (m == 0)
				break;
			if (m >= road[i].len)
			{
				ans -= road[i].len*road[i].robber;
				m -= road[i].len;
			}
			else
			{
				ans -= m * road[i].robber;
				m = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
