#include<iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;
//互质的情况

long long inv(long long a, long long m){  
    return a == 1 ? 1 : (m - m / a) * inv(m % a, m) % m;  
}

long long chinaRem(int b[],int m[],int n)
{
    long long ret=0,M=1,M1;
    for(int i=0;i<n;i++)
    {
        M*=m[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        M1=M/m[i];
        ret=(ret+b[i]*M1*inv(M1,m[i])%M+M)%M;
    }
    
}
int main(){
    ios::sync_with_stdio(false);

    return 0;
}