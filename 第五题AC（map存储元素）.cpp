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
typedef long long ll;
const int N = 1e5 + 9;
int a[N];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int, int>mp;
		for (int i = 0;i<n;i++) {
			cin >> a[i];
				mp[a[i]]++;
		}
		ll ans = 0;
		for (int i = 0;i<n;i++) {
			mp[a[i]]--;
			for (int j = 0;j<32;j++) {
				int x = (1 << j) - a[i];
				ans += mp[x];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
