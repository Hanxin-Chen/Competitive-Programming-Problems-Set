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
set<int> mst;
set<int>::iterator it;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin>>n>>m)
	{
		mst.clear();
		int a;
		for (int i = 0; i < n+m; i++)
		{
			cin >> a;
			mst.insert(a);
		}
		for (it = mst.begin();it != mst.end();it++)
		{
			if (it != mst.begin())
				cout << " ";
			cout << (*it);
		}
		cout << endl;
	}
	return 0;
}