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
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;

int main()
{
	int i, n, a, t;
	while (scanf("%d", &n) != EOF)
	{
		t = 0;
		while (n--)
		{
			cin >> a;
			t ^= a;
		}
		//cout << t << endl;
		if (t == 0)
			printf("Lose\n");
		else
			printf("Win\n");
	}
	return 0;
}

