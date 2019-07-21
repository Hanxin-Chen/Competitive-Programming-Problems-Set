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
#include<ctime>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	__int64 k;
	cin >> k;
	while (k--)
	{
		__int64 n;
		cin >> n;
		__int64 m;
		m = ((__int64)sqrt(1 + 8 * (n - 1)) - 1) / 2;    //n-1∑¿÷πn∏’∫√µ»”⁄m(m+1)/2
		n -= m * (m + 1) / 2;
		__int64 ans;
		ans = n % 9 != 0 ? n % 9 : 9;
		cout << ans << endl;
	}
	return 0;
}