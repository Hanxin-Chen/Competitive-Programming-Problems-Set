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
int room[250];
int main()
{
	ios::sync_with_stdio(false);
	int t,a,b;
	while (cin>>t)
	{
		while (t--)
		{
			int n;
			memset(room, 0, sizeof(room));
			cin >> n;
			for (int i = 0;i < n;i++)
			{
				cin >> a >> b;
				a = ceil(1.0*a / 2);
				b = ceil(1.0*b / 2);
				for (int j = min(a, b);j <= max(a, b);j++)
					room[j]++;
			}
			sort(room, room + 200, greater<int>());
			int ans;
			ans = room[0] * 10;
			cout << ans << endl;
		}
	}
	return 0;
}
