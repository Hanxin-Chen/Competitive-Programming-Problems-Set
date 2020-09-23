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
#define N 1000005
// codeforces 280B
// 本题题意：找出任意子序列中最大值和次大值的异或值的最大值
// 解法：维护一个单调递减的栈，每次向左比对，如果大于栈顶元素，则进行pop操作，这样每次都是最大值和次大值的比较
int n, a[N],ans=0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	stack<int> sa;
	sa.push(a[0]);
	for (int i = 1; i < n; i++){
		while (!sa.empty() && a[i]>sa.top())
		{
			ans = max(ans, a[i] ^ sa.top());
			sa.pop();
		}
		if (!sa.empty()) {
			ans = max(ans, a[i] ^ sa.top());
		}
		sa.push(a[i]);
	}
	cout << ans << endl;
	return 0;
}

