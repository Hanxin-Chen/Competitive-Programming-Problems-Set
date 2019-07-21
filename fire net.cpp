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
#include<cstdlib>
#define N 1<<15
using namespace std;
 int a[5][5];
 int a2[5][5];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	char b;
	while (cin>>n,n)
	{
		memset(a, 0, sizeof(a));
		memset(a2, 0, sizeof(a2));
		for (int i = 0; i < n; i++)
		{
			getchar();
			for (int j = 0; j < n; j++)
			{
				cin >> b;
				if (b == 'X')
					a[i][j] = 1;
			}
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] != 1)
				{
					for (int k = i - 1;k >= 0 && a[k][j] != 1;k--)  //up
						a2[i][j]++;
					for (int k = i + 1;k < n&&a[k][j] != 1;k++)  //down
						a2[i][j]++;
					for (int k = j - 1;k >= 0 && a[i][k] != 1;k--)  //left
	 					a2[i][j]++;
					for (int k = j + 1;k < n&&a[i][k] != 1;k++)   //right
						a2[i][j]++;
					a2[i][j]++;
				}
			}
		}
		int cnt = 0;
		int min;
		int x, y;
		for (int i = 0;i < n;i++)
		{
			min = 8;
			for (int j = 0; j < n; j++)
			{
				if(a2[i][j]>0&&min>a2[i][j])
				{
					min = a2[i][j];
					x = i;
					y = j;
				}
			}
			if (min != 8)
			{
				cnt++;
				for (int k = x - 1;k >= 0 && a[k][y] != 1;k--)  //up
					a2[k][y] = 8;
				for (int k = x + 1;k < n&&a[k][y] != 1;k++)  //down
					a2[k][y] = 8;
				for (int k = y - 1;k >= 0 && a[x][k] != 1;k--)  //left
					a2[x][k] = 8;
				for (int k = y + 1;k < n&&a[x][k] != 1;k++)   //right
					a2[x][k] = 8;
				a2[x][y] = 8;
				i--;
			}
		}
		cout << cnt << endl;
		
	}
	return 0;
}