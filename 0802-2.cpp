#include <cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>     
#include<map>
#include<iomanip>
#include<cctype>
#include<vector>
#include<set>
using namespace std;
int leap(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
		return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);  
	int t;
	int y, m, d;
	while (cin>>t)
	{
		for (int i = 0;i < t;i++)
		{
			int sum = 0;
			scanf("%d-%d-%d", &y, &m, &d);
			if (m == 2 && d == 29)
			{
				cout << "-1" << endl;
				continue;
			}
			if (m >= 3)
			{
				for (int k = y + 1;k <= y + 18;k++)
				{
					if (leap(k)) sum += 366;
					else sum += 365;
				}
			}
			else if (m < 3)
			{
				for (int k = y;k <= y + 17;k++)
				{
					if (leap(k)) sum += 366;
					else sum += 365;
				}
			}
			cout << sum << endl;

		}
	}
	return 0;
}


