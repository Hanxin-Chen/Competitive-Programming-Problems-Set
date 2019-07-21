#include<stdio.h>

void AddOne()
{
	static int ilnt=3;     /*定义static整型变量*
    ilnt=ilnt*3;           /*变量乘3*/
	printf("%d\n",ilnt);   /*显示结果*/
}
int main()
{
    printf("第一次调用："); /*显示结果*/
	AddOne();               /*调用AddOne函数*/
	printf("第二次调用: ");  /*显示结果*/
	AddOne();               /*调用AddOne函数*/
	return 0;               /*程序结束*/
}
