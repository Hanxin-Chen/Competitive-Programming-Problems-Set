#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
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

// codeforces 821C

#define N 1000005
int n,ans = 0;
vector<int> sa;
int main()
{
	cin >> n;
	int num, cur = 0, top = -1;
	string com;
	for (int i = 0; i < 2 * n; i++) {
		cin >> com;
		if (com == "add") {
			cin >> num;
			sa.push_back(num);
		}
		else if (com == "remove") {
			cur++;
			if (sa.empty())    //栈空时直接跳过
				continue;
			if (cur == sa[sa.size() - 1])
				sa.pop_back();
			else {
				ans++;
				sa.clear(); //经过一次排序之后的序列必然可以remove，因此不需要考虑，直接清空栈即可
			}
		}

	}
	cout << ans << endl;
	return 0;
}

