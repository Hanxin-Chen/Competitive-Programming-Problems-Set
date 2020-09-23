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
#define L 1000
char dg1[500], dg2[500];
char ans[10000];
char ans2[500][500];

string mul(string a, string b)
{
	string s;
	int na[L], nb[L], nc[L], La = a.size(), Lb = b.size();
	fill(na, na + L, 0);fill(nb, nb + L, 0);fill(nc, nc + L, 0);
	for (int i = La - 1;i >= 0;i--) na[La - i] = a[i] - '0';
	for (int i = Lb - 1;i >= 0;i--) nb[Lb - i] = b[i] - '0';
	for (int i = 1;i <= La;i++)
		for (int j = 1;j <= Lb;j++)
			nc[i + j - 1] += na[i] * nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
	for (int i = 1;i <= La + Lb;i++)
		nc[i + 1] += nc[i] / 10, nc[i] %= 10;//统一处理进位
	if (nc[La + Lb]) s += nc[La + Lb] + '0';//判断第i+j位上的数字是不是0
	for (int i = La + Lb - 1;i >= 1;i--)
		s += nc[i] + '0';
	return s;
}
void p(string a, string b)
{
	int carry = 0;
	int len1;
	memset(dg1, 0, sizeof(dg1));
	memset(dg2, 0, sizeof(dg2));
	memset(ans, 0, sizeof(ans));
	strcpy_s(dg1, a.c_str());
	strcpy_s(dg2, b.c_str());
	len1 = max(a.length(), b.length());
	int k, cnt = 0;
	int le1 = a.length();
	int le2 = b.length();
	for (int i = 0; i < len1; i++)
	{
		if ((le1 - 1 - i) >= 0 && (le2 - 1 - i) >= 0)
			k = dg1[le1 - 1 - i] - '0' + dg2[le2 - 1 - i] - '0' + carry;
		else if ((le1 - 1 - i) >= 0)
		{
			k = dg1[le1 - 1 - i] - '0' + carry;
		}
		else if((le2 - 1 - i)>=0)
			k= dg2[le2 - 1 - i] - '0' + carry;
		carry = k / 10;
		ans[i] = k % 10 + '0';
		cnt=i;
	}
	if (carry)
	{
		cnt++;
		ans[cnt] = carry + '0';
	}
	int len;
	len = max(a.length(), b.length()+1);           
	len = max(len, cnt+1);
	cout << right << setw(len) << a << endl;
	b.insert(b.begin(), '+');
	cout << right << setw(len) << b << endl;
	b.erase(b.begin());
	for (int i = 0; i < len; i++)
		cout << "-";
	cout << endl;
	if (cnt + 1 < len)
	{
		int dd = abs(cnt + 1 - len);
		for (int i = 0; i < dd; i++)
		{
			cout << ' ';
		}
	}
	for (int i = cnt;i >= 0;i--)
		cout << ans[i];
	cout << endl;
	
} 
void m(string a, string b)
{
	int carry = 0;
	int len1;
	memset(dg1, 0, sizeof(dg1));
	memset(dg2, 0, sizeof(dg2));
	memset(ans, 0, sizeof(ans));
	strcpy_s(dg1, a.c_str());
	strcpy_s(dg2, b.c_str());
	len1 = max(a.length(), b.length());
	int k, cnt = 0;
	int le1 = a.length();
	int le2 = b.length();
	string ans;
	int na[L] = { 0 }, nb[L] = { 0 };
	int la = a.size(), lb = b.size();
	for (int i = 0;i<la;i++) na[la - 1 - i] = a[i] - '0';
	for (int i = 0;i<lb;i++) nb[lb - 1 - i] = b[i] - '0';
	int lmax = la>lb ? la : lb;
	for (int i = 0;i<lmax;i++)
	{
		na[i] -= nb[i];
		if (na[i]<0) na[i] += 10, na[i + 1]--;
	}
	while (!na[--lmax] && lmax>0);lmax++;
	for (int i = lmax - 1;i >= 0;i--) ans += na[i] + '0';
	cnt = ans.size() - 1;
	int len,len2;
	len2 = max(cnt + 1, le2 + 1);
	len = max(le1, le2 + 1);
	cout << right << setw(len) << a << endl;
	b.insert(b.begin(), '-');
	cout << right << setw(len) << b << endl;
	b.erase(b.begin());
	for (int i = 0;i < len - len2;i++)
		cout << ' ';
	for (int i = 0; i < len2; i++)
		cout << "-";
	cout << endl;
	if (cnt + 1 < len)
	{
		int dd = abs(cnt + 1 - len);
		for (int i = 0; i < dd; i++)
		{
			cout << ' ';
		}
	}
	cout << ans << endl;
} 
void multiply(string left, string right)
{
		string res = mul(left, right);
		if (res[0] == '0') res = "0";
		if (right.length() == 1)
		{

			int maxsize = 2>res.length() ? 2 : res.length();
			int max = maxsize>left.length() ? maxsize : left.length();
			for (int i = 1;i <= max - left.length();i++) cout << " ";
			cout << left << endl;
			for (int i = 1;i <= max - right.length() - 1;i++) cout << " ";
			cout << "*" << right << endl;
			for (int i = 1;i <= max - maxsize;i++) cout << " ";
			for (int i = 1;i <= maxsize;i++) cout << "-";
			cout << endl;
			for (int i = 1;i <= max - res.length();i++) cout << " ";
			cout << res << endl;
		}
		else
		{
			string lasttemp = mul(left, to_string(right[0] - '0'));
			string firsttemp = mul(left, to_string(right[right.length() - 1] - '0'));
			if (firsttemp[0] == '0') firsttemp = "0";
			int maxsize1 = (right.length() + 1)>firsttemp.length() ? (right.length() + 1) : firsttemp.length();
			int maxsize2 = lasttemp.length() + right.length() - 1>res.length() ? (lasttemp.length() + right.length() - 1) : res.length();
			int max = maxsize1>maxsize2 ? maxsize1 : maxsize2;
			for (int i = 1;i <= max - left.length();i++) cout << " ";
			cout << left << endl;
			for (int i = 1;i <= max - right.length() - 1;i++) cout << " ";
			cout << "*" << right << endl;
			for (int i = 1;i <= max - maxsize1;i++) cout << " ";
			for (int i = 1;i <= maxsize1;i++) cout << "-";
			cout << endl;
			int pos = 0;
			for (int i = right.length() - 1;i >= 0;i--)
			{
				string temp = mul(left, to_string(right[i] - '0'));
				if (temp[0] == '0') temp = "0";
				int space = max - temp.length() - pos;
				for (int i = 1;i <= space;i++) cout << " ";
				cout << temp << endl;
				pos++;
			}
			for (int i = 1;i <= max - maxsize2;i++) cout << " ";
			for (int i = 1;i <= maxsize2;i++) cout << "-";
			cout << endl;
			for (int i = 1;i <= max - res.length();i++) cout << " ";
			cout << res << endl;
		}
}
int main()
{
	string s;
	int n;
	while (cin>>n)
	{
		while (n--)
		{
			cin >> s;
			string d1, d2, t;
			char op;
			int c = 1;
			for (int i = 0;i < s.length();i++)
			{
				if (s[i] == '+' || s[i] == '-' || s[i] == '*')
				{
					op = s[i];
					s[i] = ' ';
					break;
				}
			}
			stringstream str(s);
			while (str >> t)
			{
				if (c)
					d1 = t;
				else
					d2 = t;
				c--;
			}
			switch (op)
			{
			case '+':
				p(d1, d2);
				break;
			case '-':
				m(d1, d2);
				break;
			case '*':
				multiply(d1, d2);
				break;
			}

				cout << endl;
		}
	}
	return 0;
}