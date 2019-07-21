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
#include<utility>
#define N 40000
using namespace std;
int a[N];
int b[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int count=0;
		for (int i = 0; i < n; i++)
		{
			int f = 1;
			for (int j = 0;j < count;j++)
				if (b[j] >= a[i])
				{
					f = 0;
					b[j] = a[i];
					break;
				}
			if (f)	
				b[count++] = a[i];
		}
		cout << count << endl;
	}
	return 0;
}
