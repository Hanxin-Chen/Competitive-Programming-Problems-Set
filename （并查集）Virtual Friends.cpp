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
int  n;
const int maxn = 200000 + 20;
int p[maxn], root_cnt[maxn];
map<string, int>Map;
int Find(int x) 
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}
int Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb) { p[pb] = pa;root_cnt[pa] += root_cnt[pb]; }
	return root_cnt[pa];
}

map<string, int>ma;

int main()
{
	int t;
	ios::sync_with_stdio(false);
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			ma.clear();
			int cnt = 0;
			scanf("%d", &n);
			for (int i = 1; i < 2 * n; i++)
			{
				p[i] = i;
				root_cnt[i] = 1;
			}
			for(int i=1;i<=n;i++)
			{
				char s1[25], s2[25];
				scanf("%s %s", s1, s2);
				if (ma[s1] == 0)
					ma[s1] = ++cnt;
				if (ma[s2] == 0)
					ma[s2] = ++cnt;
				int ans=Union(ma[s1], ma[s2]);
				cout << ans << endl;
			}

		}
	}
	return 0;
}
