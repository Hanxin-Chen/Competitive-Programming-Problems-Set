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
#include<cstdlib>
#define maxdigit 1000
#define plus 1
#define minus -1
using namespace std;
class bignumber
{
	friend ostream & operator <<(ostream &cout, bignumber &bn);
	friend int  compare(bignumber&a, bignumber&b);
private:
	char digits[maxdigit];
	int signbit;
	int lastdigit;
public:
	bignumber();
	bignumber(long long num);
	bignumber(const char *s);
	bignumber operator+(bignumber &a);
	bignumber operator-(bignumber &a);
	bignumber operator*(bignumber &a);
	void digit_left_move(int d);
	void zero_justify()
	{
		for (int i = lastdigit;i >= 0;i--)
		{
			if (digits[i] == '0') lastdigit--;
			else break;
		}
	}

};
void bignumber::digit_left_move(int d)
{
	int i;
	for (i = lastdigit; i >= 0; i++)
		digits[i + d] = digits[i];
	for (i = 0;i < d;i++)
		digits[i] = '0';
}
bignumber::bignumber()
{
	lastdigit = 0;
	signbit = plus;
	digits[0] = '0';
	for (int i = 0;i < maxdigit;i++)
		digits[i] = '0';
}
bignumber::bignumber(long long num)
{
	if (num<0)
	{
		signbit = minus;
		num = abs(num);
	}
	else
	{
		signbit = plus;
	}
	lastdigit = -1;
	while (num)
	{
		digits[++lastdigit] = num % 10 + '0';
		num /= 10;
	}
}
bignumber::bignumber(const char *s)               //若不加const， “123” 等无法输入；
{
	if (s[0] == '-')
	{
		signbit = minus;
		lastdigit = strlen(s) - 2;
		for (int i = 0;i <= lastdigit;i++)
		{
			digits[i] = s[lastdigit + 1 - i];
		}
	}
	else
	{
		signbit = plus;
		lastdigit = strlen(s) - 1;
		for (int i = 0;i <= lastdigit;i++)
		{
			digits[i] = s[lastdigit - i];
		}
	}
}
ostream & operator <<(ostream &cout, bignumber &bn)
{
	if (bn.signbit == minus) cout << '-';
	for (int i = bn.lastdigit;i >= 0;i--)
	{
		cout << bn.digits[i];
	}
	return cout;
}

int compare( bignumber &a,  bignumber &b)
{
	if ((a.signbit == minus) && (b.signbit == plus))
		return plus;
	if ((a.signbit == plus) && (b.signbit == minus))
		return minus;

	if (b.lastdigit > a.lastdigit)
		return plus * a.signbit;
	if (a.lastdigit > b.lastdigit)
		return minus * a.signbit;
	for (int i = a.lastdigit; i >= 0; i--) {
		if (a.digits[i] > b.digits[i])
			return minus * a.signbit;
		if (b.digits[i] > a.digits[i])
			return plus * a.signbit;
	
	}
	return 0;
}


bignumber bignumber::operator+(bignumber &a)
{
	bignumber c;
	bignumber();
	if (signbit == a.signbit)
	{
		c.signbit = signbit;
		c.lastdigit = max(lastdigit, a.lastdigit) + 1;
		int carry = 0;
		int temp;
		for (int i = 0;i<c.lastdigit;i++)
		{
			temp = digits[i] - '0' + a.digits[i] - '0' + carry;
			c.digits[i] = temp % 10 + '0';
			carry = temp / 10;
		}
		c.zero_justify();
	}
	else
	{
		if (signbit == minus)
		{
			signbit = plus;
			//c=a-*this;
			signbit = minus;
		}
		else
		{
			a.signbit = plus;
			//c=*this-a;
			a.signbit = minus;
		}
	}
	return c;
}
bignumber bignumber::operator-(bignumber& a)
{
	bignumber c;
	if (signbit == minus || a.signbit == minus)
	{
		a.signbit = -1 * a.signbit;
		c = *this + a;
		a.signbit = -1 * a.lastdigit;
	}
	else
	{
		if (compare(*this, a) == minus)
		{
			c = a - *this;
			c.signbit = minus;
			return c;
		}
		c, lastdigit = max(lastdigit, a.lastdigit);
		c.signbit = plus;
		int borrow = 0,v;
		for (int i = 0; i < c.lastdigit; i++)
		{
			v = digits[i] - a.digits[i] - borrow;
			if (v <= 0)
			{
				v += 10;
				borrow = 1;
			}
			else
			{
				borrow = '0';
			}
			c.digits[i] = v + '0';
		}
	}
	return c;
}
bignumber bignumber::operator*(bignumber &a)
{
	bignumber c;
	c.signbit = signbit + a.signbit;
	c.lastdigit = lastdigit + a.lastdigit + 1;
	for (int i = 0; i <= a.lastdigit; i++)
	{
		bignumber tmp;
		for (int j = 0; j < a.digits[i]; j++)
		{
			tmp = tmp + *this;
		}
		tmp.digit_left_move(i);
		c = c + tmp;
	}
	zero_justify();
	return c;
}
int main()
{
	bignumber bn("1313");             //“1313”传入为const类型
	bignumber num(524);
	bignumber zero;
	cout << bn << endl;
	cout << num << endl;
	cout << zero << endl;
	zero = bn + num;
	cout << zero << endl;
	system("pause");
	return 0;
}
