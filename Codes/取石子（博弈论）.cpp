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

int main()
{
	int x, y, a, b, m;
	while (cin >> x >> y)
	{
		int k = abs(x - y);
		a = min(x, y);
		if (a == (int)(1.0*k*(sqrt(5) + 1) / 2))
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
}
