/*
 * =====================================================================================
 *
 *       Filename:  simplesum.c
 *
 *    Description:  简单的口算练习程序
 *
 *        Version:  1.0
 *        Created:  Wednesday, January 08, 2014 12:36:55 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Li_Mao (lm), cfanmaoli@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
enum operator_type {
	ADD, SUB, MUL, DIV
} opr;

char operator_char(int c)
{
	switch(c) {
	case ADD:
		opr = ADD;
		return '+';
		break;
	case SUB:
		opr = SUB;
		return '-';
		break;
	case MUL:
		opr = MUL;
		return '*';
		break;
	case DIV:
		opr = DIV;
		return '/';
		break;
	}
}
int main(void)
{
	long int max, a, b, rans, total = 0, wrong = 0;
	time_t start_time;
	double total_time;
	char c, ans[100] = "start", sans[100];
S:	printf("请输入可产生的最大数字");
	scanf("%ld", &max);
	printf("重设程序请输入reset，退出请输入exit\n");
	start_time = time(0);
	while(strcmp(ans, "exit") != 0) {
		total++;
R:		srandom(time(0));
		a = random()%max;
		b = random()%max;
		c = operator_char(random()%4);
		if(c == '/' && b == 0)
			goto R;
		printf("%ld%c%ld\n答案:", a, c, b);
		switch (opr) {
			case ADD:
				rans = a + b;
				break;
			case SUB:
				rans = a - b;
				break;
			case MUL:
				rans = a * b;
				break;
			case DIV:
				rans = a / b;
				break;
		}
		scanf("%s",&ans);
		if(strcmp(ans, "reset") == 0)
			goto S;
		sprintf(sans, "%ld", rans);	/* sprintf(),将数字类型转成字符串类型 */
		if(strcmp(ans, sans)) {	/* strcmp(),比较2个字符串是否相等，相等返回0,大于返回+数，小于返回-数 */
			wrong++;
			printf("答错了,正确答案是%ld\n", rans);
		}
	}
	total_time = (time(0) - start_time) / 60.0;
	printf("练习了%.1f分钟，总共%ld题，错了%ld道\n", total_time, --total, --wrong);
	return 0;
}
