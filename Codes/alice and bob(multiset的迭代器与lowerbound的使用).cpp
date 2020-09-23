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
#define N 100050
using namespace std;
struct card
{
	int h;
	int w;
}alice[N],bob[N];
bool cmp(card a, card b)
{
	return a.h < b.h;
}
multiset<int> mst;
multiset<int>::iterator it;
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin >> t;
	while (t--)
	{
		mst.clear();
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> alice[i].h >> alice[i].w;
		for (int i = 0;i < n;i++)
			cin >> bob[i].h >> bob[i].w;
		sort(alice, alice + n, cmp);
		sort(bob, bob + n, cmp);
		int ans = 0;
		for (int j=0,i = 0; i < n; i++)
		{
			for ( ; j < n&&alice[i].h>=bob[j].h; j++)
			{
				mst.insert(bob[j].w);
			}
			if (mst.empty())
				continue;
			it = mst.lower_bound(alice[i].w);
			if (mst.size() > 0 && it != mst.begin())
				it--;
			if (mst.size()>0&&(*it) <= alice[i].w)
			{
				ans++;
				mst.erase(it);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

