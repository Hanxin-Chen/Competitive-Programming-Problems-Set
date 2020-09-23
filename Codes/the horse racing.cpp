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
#define N 1005
#define money 200
using namespace std;
int tianji[N];
int king[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,a,b;
	while (cin>>n,n)
	{
		memset(tianji, 0, sizeof(tianji));
		memset(king, 0, sizeof(king));
		for (int i = 0; i < n; i++)
			cin >> tianji[i];
		for (int i = 0;i < n;i++)
			cin >> king[i];
		sort(tianji, tianji + n, greater<int>());
		sort(king, king + n, greater<int>());
		int win = 0,tie=0,loss=0;
		int t1 = 0, t2 = n - 1;
		int k1 = 0, k2 = n - 1;
		while (n--)
		{
			if (tianji[t1] > king[k1])      //比较田和国王的最快的马
			{
				win++;
				t1++;
				k1++;
			}
			else if (tianji[t2] > king[k2])   //比较最慢的马
			{
				win++;
				t2--;
				k2--;
			}
			else if (tianji[t2] < king[k1])   //用tianji最慢的换国王最快的
			{
				win--;
				t2--;
				k1++;
			}
		}
		cout << win * money << endl;
	}
	return 0;
}
