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
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int floor[105] = { 0 };
	int time;
	while (cin >> n, n)
	{
		time = 0;
		for (int i = 1;i <= n;i++) {
			cin >> floor[i];
			if (floor[i] > floor[i - 1])
				time += 6 * (floor[i] - floor[i - 1]);
			else
				time += 4 * (floor[i - 1] - floor[i]);
		}
		time += 5 * n;
		cout << time << endl;
	}
	return 0;
}