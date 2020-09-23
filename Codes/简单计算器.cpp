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
	string s;
	string str;
	int n;
	int flag;
	while (getline(cin,s)&&s!="0")
	{
		int ai = 0, opi = 0;
		int a[200];
		string op;
		stringstream ss(s);
		stringstream stream;
		while (ss>>str)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				op += str;
				opi++;
			}
			else
			{
				stream.clear();
				stream << str;
				stream >> a[ai];
				ai++;
			}
		}
		double p = 0;
		double q = a[0];
		int f = 1;
		for (int i = 0; i < opi; i++)
		{
			switch (op[i])
			{
			case '+':
				p += q * f;
				f = 1;
				q = a[i + 1];
				break;
			case '-':
				p += q * f;
				f = -1;
				q = a[i + 1];
				break;
			case '*':
				q *= 1.0*a[i + 1];
				break;
			case '/':
				q /= 1.0*a[i + 1];
				break;
			}
		}
			p += q * f;
			printf("%.2lf\n", p); //用Cout会出现精度问题？？？
	}
	return 0;
}