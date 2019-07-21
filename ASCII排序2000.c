#include<stdio.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
int main()
{	char a,b,c,d,e,f,z;
	while(scanf("%c%c%c%c",&a,&b,&c,&z)!=EOF)
	{	d=min(min(a,b),c);
		f=max(max(a,b),c);
		e=a+b+c-d-f;
		printf("%c %c %c\n",d,e,f);
	}
	return 0;
} 



