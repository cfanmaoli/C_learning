# include <stdio.h>
# include <math.h>
int print_diamond(int n,char a)
{
	int i, j;
	if(n%2 == 0) {
	printf("输入的是偶数，程序将自动+1\n");
	++n;
	}
	for(i=1;i<=n;++i) {	/*整个图形的循环*/
		for(j=1;j<=(abs((n-(2*i-1))/2));++j)	/*输出所有空格*/
		printf("\t");
	/*开始输出符号*/
		if(i<=((n+1)/2)) {	/*判断图形上下部分*/
			for(j=1;j<=(2*i-1);++j)	/*输出上部符号*/
			printf("%c\t",a);
		}
		else {	/*输出下部符号*/
			for(j=1;j<=((2*i-1)-4*(i-((n+1)/2)));++j)
			printf("%c\t",a);
		}
	printf("\n");
	}
	return 0;
}
int main(void)
{
	int n;
	char a;
	printf("请输入一个奇数和要显示的符号(用空格隔开)\n");
	scanf("%d %c",&n,&a);
	print_diamond(n,a);
	return 0;
}
