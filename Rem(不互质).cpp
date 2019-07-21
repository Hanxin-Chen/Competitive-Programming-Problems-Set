#include<iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;
//不互质的情况

typedef long long ll;

ll exGcd(ll a, ll b, ll& x, ll &y)
{
	ll m;
	if (a == 0 && b == 0)
		return -1;
	else if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	m = exGcd(b, a%b, x, y);
	ll tmp = x;
	x = y, y = tmp - (a / b)*y;
	return m;
}

long long inv(long long a, long long m){  
    return a == 1 ? 1 : (m - m / a) * inv(m % a, m) % m;  
}

long long Rem(long long a[],long long n[],int num){
    long long n1=n[0],a1=a[0],n2,a2,k1,k2,x0,gcd,c;
    for(int i=1;i<num;i++){
        n2=n[i],a2=a[i];
        c=a2-a1;
        gcd=exGcd(n1,n2,k1,k2);//解得：n1*k1+n2*k2=gcd(n1,n2) 
        if(c%gcd){
             int flag=1;
            return 0;//无解 
        }
        x0=c/gcd*k1;//n1*x0+n2*(c/gcd*k2)=c  PS:k1/gcd*c错误！
        int t=n2/gcd; 
        x0=(x0%t+t)%t;//求n1*x0+n2*y=c的x0的最小解 
        a1+=n1*x0;
        n1=n2/gcd*n1; 
    }
    return a1;
}

int main(){
    ios::sync_with_stdio(false);

    return 0;
}