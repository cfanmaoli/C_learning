/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  复制输入到输出，并将其中的多个空格替换成一个空格
 *
 *        Version:  1.0
 *        Created:  01/13/2014 12:21:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Li_Mao (lm), cfanmaoli@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int c;
	bool m = false;
	c = getchar();
	while(c != EOF) {
		if(c != ' ') {
			putchar(c);
			m = false;
		}
	  	else 
			if(m == false) {
				putchar(c);
				m = true;
			}
		c = getchar();
	}
	return 0;
}
