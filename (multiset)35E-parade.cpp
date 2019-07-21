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
#include <stack>
#pragma warning(disable:4996);
using namespace std;
#define N 100005

struct node
{
	int left;
	int right;
	int height;
	node(int h,int l,int r):left(l),height(h),right(r){}
	bool operator <(const node &n1)const {
		return height < n1.height;
	}
};

vector<pair<int, int> >p,ans;
multiset<int> ms;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		p.clear(); ans.clear(); ms.clear();
		for (int i = 0; i < n; i++)
		{
			int h, l, r;
			cin >> h >> l >> r;
			p.push_back(make_pair(l, h));
			p.push_back(make_pair(r, -h));
		}
		sort(p.begin(), p.end());
		ms.insert(0);
		int maxh = 0;
		for (int i = 0,j; i < n*2; i=j)
		{
			for ( j = i; j < n*2 && p[i].first==p[j].first; j++)
			{
				if (p[j].second > 0)
					ms.insert(p[j].second);
				else
					ms.erase(ms.lower_bound(-p[j].second));
			}
			if (*(ms.rbegin()) != maxh) {
				ans.push_back(make_pair(p[i].first, maxh));
				ans.push_back(make_pair(p[i].first, *(ms.rbegin())));
				maxh = *(ms.rbegin());
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}
