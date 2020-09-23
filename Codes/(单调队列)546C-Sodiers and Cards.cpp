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

//codeforces 546C

int main() {
	int n, k1, k2, x;
	cin >> n >> k1;//注意是k1、k2分开输 
	queue<int> l;
	queue<int> r;
	for (int i = 0; i < k1; i++) {//入队 
		cin >> x;
		l.push(x);
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		cin >> x;
		r.push(x);
	}
	//cout<<r.front()<<" "<<l.front()<<endl;
	int ans = 0;
	while (1) {
		if (l.front() > r.front()) {//当1大时按顺序分别将r的队顶元素和l的队顶元素插入l队尾 
			l.push(r.front());
			l.push(l.front());
			l.pop();//注意弹出已插入的元素 
			r.pop();
			ans++;
		}
		else if (l.front() < r.front()) {//同上 
			r.push(l.front());
			r.push(r.front());
			r.pop();
			l.pop();
			ans++;
		}
		if (l.empty()) {//若l为空时，2 win 
			cout << ans << " " << "2" << endl;
			return 0;
		}
		if (r.empty()) {
			cout << ans << " " << "1" << endl;
			return 0;
		}
		if (ans == 100000) {//认为是死循环
			cout << "-1" << endl;
			return 0;
		}
	}
	return 0;
}
