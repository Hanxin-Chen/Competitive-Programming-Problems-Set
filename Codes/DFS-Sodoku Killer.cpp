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
//#pragma warning(disable:4996);
using namespace std;
char a[12][12];
int b[12][12];

bool Judge1(int x, int y, int n)
{
	int i;

	for (i = 0; i < 9; i++)
	{
		//判断 列
		if ((b[i][y] == n) && (i != x))
			return false;
		//判断 行
		if ((b[x][i] == n) && (i != y))
			return false;
	}

	return true;
}

//判断填在空白位置的数字在九宫格之内是否符合要求
bool Judge2(int x, int y, int n)
{
	int xx, yy, i, j;
	xx = x / 3;
	yy = y / 3;
	for (i = xx * 3; i < xx * 3 + 3; i++)
		for (j = yy * 3; j < yy * 3 + 3; j++)
			if (b[i][j] == n)
				if (i == x && j == y)
					continue;
				else
					return false;
	return true;
}

void dfs(int m) {
	if (m >= 81) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j)
					cout << " ";
				cout << b[i][j];
			}
			cout << "\n";
		}
		return;
	}
		
	int  x, y;
	x = m / 9;
	y = m % 9;
	if (b[x][y] == 0) {
		for (int i = 1; i <= 9; i++)
		{
			if (Judge1(x, y, i) && Judge2(x, y, i))
			{
				b[x][y] = i;
				dfs(m + 1);
				b[x][y] = 0;
				
			}
		}
	}
	else
		dfs(m + 1);
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	while (cin>>a[0][0])
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j <9 ; j++)
			{
				if (i == 0 && j == 0)
					continue;
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (a[i][j] == '?')
					b[i][j] = 0;
				else
					b[i][j] = a[i][j] - '0';
			}
		}
		
		if (cnt != 0)
			cout << "\n";
		cnt++;
		dfs(0);
	}
	return 0;
}