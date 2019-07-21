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
double  n;
int main()
{
	while (cin >> n)
	{
		while (n>18) 
			n /= 18;

		if (n <= 9)
			cout << "Stan wins." << endl;
		else
			cout << "Ollie wins." << endl;
	}
}
