/*
 * =====================================================================================
 *
 *       Filename:  struct_rational.c
 *
 *    Description:  结构体习题2-有理数结构体
 *
 *        Version:  1.1
 *        Created:  Tuesday, December 31, 2013 09:45:45 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Li_Mao (lm), cfanmaoli@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>
struct rational {
	long int x,y;
};

long int get_gdc(long int a, long int b)	/*  注意调用的时候传0进来 */
{
	long int c;
	if(a<0 || b<0) {
	a = labs(a);
	b = labs(b);
	}
	if(a < b) {
		c = a; a = b; b = c;
	}
	if(a%b == 0) {
		return b;
	}
	else	return get_gdc(b, a%b);
}

struct rational make_rational(long int a, long int b)
{
	struct rational c;
	if(b < 0) {
		b = -b; a = -a;
	}
	if(a == 0) {
		c.x = a;
		c.y = b;
	}
	else {
		long int gdc;
		gdc = get_gdc(a, b);
		if(gdc == 1) {
			c.x = a;
			c.y = b;
		}
		c.x = a/gdc;
		c.y = b/gdc;
	}
	return c;
}

void print_rational(struct rational a)
{
	if(a.x<0 || a.y<0)
		printf("-%ld/%ld\n", labs(a.x), labs(a.y));
	else printf("%ld/%ld\n", a.x, a.y);
}

long int mol_part(struct rational a)
{
	return a.x;
}

long int den_part(struct rational a)
{
	return a.y;
}

struct rational add_rational(struct rational a, struct rational b )
{

	return make_rational(mol_part(a) * den_part(b) + mol_part(b) * den_part(a), den_part(a) * den_part(b));
}

struct rational sub_rational(struct rational a, struct rational b )
{
	return make_rational(mol_part(a) * den_part(b) - mol_part(b) * den_part(a), den_part(a) * den_part(b));
}

struct rational mul_rational(struct rational a, struct rational b )
{
	return make_rational(mol_part(a) * mol_part(b), den_part(a) * den_part(b));
}

struct rational div_rational(struct rational a, struct rational b )
{
	if(b.x == 0) {
		printf("除数为零，跳过除法运算");
		return;
	}
	else
		return make_rational(mol_part(a) * den_part(b), den_part(a) * mol_part(b));
}

int main(void)
{
	long int a1, a2, b1, b2;
S:	printf("请以分数形式输入2个有理数\n");
	scanf("%ld/%ld %ld/%ld", &a1, &a2, &b1, &b2);
	printf("=============================================================\n");
	if(a2 == 0 || b2 ==0) {
		printf("分母不能为0\n");
		goto S;
	}
	else {
	struct rational a = make_rational(a1, a2);
	struct rational b = make_rational(b1, b2);
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));
	}
	return 0;
}
