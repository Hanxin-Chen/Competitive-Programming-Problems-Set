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
/*
算法：nim博弈，nim博弈的必胜点在于维持一个平衡位置，有点类似于有n堆石子，a1,a2....an;两人轮流从中去石子，只要
a1^a2^a3....^an == 0 ,则第二位取的必胜，否则第一位取的必胜。
这题同样：可以将两个棋子的相对位置看做石子对，相对位置的绝对值看做石子堆的个数，不同的是这个石子堆既可以减少也可以增加，
不过由于增加的数目有限，所以可以不考虑，这样我们只要维持相对位置的绝对值的那个平衡位置，无论距离增加还是减少，总会有措施保持
这种平衡态。
所以我们要判断的就是
abs(a1-b1-1)^abs(a2-b2-1)^.....abs(an-bn-1) == 0 ,则第二位走的人胜利，否则第一位走的人胜利。
*/
int main()
{
	int n, m;
	while (cin >> n>>m)
	{
		int a, b, ans = 0;
		while (n--)
		{
			cin >> a >> b;
			ans ^= (abs(a - b)-1);
		}
		if (ans == 0)
			cout << "BAD LUCK!" << endl;
		else
			cout << "I WIN!" << endl;
	}
}
