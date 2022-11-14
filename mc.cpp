#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
struct node {
	char shu[13];
	char op[3];   
};
int ran(int &x)
{
	x++;
	return x;
}
char *shu(int max, int sign5,int &x)
{
	char str[100];
	int a, i;
	srand(ran(x));
	for (i = 0; i < max; i++)
	{
		a = rand() % 9+1;
		str[i] = a + '0';
	}
	if (sign5 == 1) {
		str[i] = '.';
		srand(ran(x));
		for (i++; i < max + 3; i++)
		{
			a = rand() % 10;
			str[i] = a + '0';
		}
	}
	str[i] = '\0';
	return str;
}
int create1(int j1,node OF[][20],int max,int num,int sign5,int &x) {
	
	char op[10] = { '0','+','-','*','/' ,'0','0','0','0'};
	int i = 0, j = 0, p;
	int sign=0;
	while (1) {
		p = num % 10;
		num = num / 10;
		op[p + 4] = '1';
		if (num == 0)break;
	}
	srand(ran(x));
	strcpy(OF[j1][j++].shu ,shu(max,sign5,x));
	while (1) {
		srand(ran(x));
		while (1) {
			srand(ran(x));
			i = rand() % 5;
			if (op[i + 4] == '1') {
				OF[j1][j].op[0] = op[i];
				OF[j1][j++].op[1] = '\0';
				break;
			}
			if (j>=3&&i == 0){
				sign = 1;
				break;
		    }
		}
		if (sign == 1 || j > 8)break;
		srand(ran(x));
		strcpy(OF[j1][j++].shu, shu(max, sign5,x));
		if (sign == 1 || j > 8)break;
	}
	return j;
}
void qian(char *a) {
	char b[13];
	b[0] = '(';
	b[1] = '\0';
	strcat(b, a);
	strcpy(a, b);
}

void hou(char *a) {
	char b[2];
	b[0] = ')';
	b[1] = '\0';
	strcat(a, b);
}
void create2(node OF[][20],int i,int j,int &x) {
	int a = 0, j1 = 0;
	int kuohao = 0;
	while (1) {
		if (kuohao == 0 && j1 == j - 1){
			break;
		}
		if (kuohao == 1 && j1 == j - 1) {
			hou(OF[i][j-1].shu); 
			break;
		}
		
		if (kuohao == 0) {
			srand(ran(x));
			a = rand() % 2;
			if (a == 1) {
				qian(OF[i][j1].shu);
				kuohao = 1;
			}
		}
		else {
			srand(ran(x));
			a = rand() % 2;
			if (a == 1) {
				hou(OF[i][j1].shu);
				kuohao = 0;
			}
		}
		j1=j1+2;
	}
}
void cun(char str[][100], int m)
{
	FILE *p1;
	int i;
	p1 = fopen("C://wang.txt", "rb");
	for (i = 0; i < m; i++)
		fprintf(p1, "%s", str[i]);
	fclose(p1);
	printf("\n修改已完成，请打开文件 wang.txt 进行查看         \n");
}
int main()
{
	char str[100][100];
	node OF[100][20];
	int i, j, k, n, max, num, sign4, sign5, sign6;
	int x = 512;
	printf("定制小学计算题\n");
	printf("1.定制题目数量:");
	scanf("%d", &n);
	printf("2.设置数的范围为几位数：");
	scanf("%d", &max);
	printf("3.选择运算符(输入的序号之间没有间隔)：1.+   2.-  3.*  4/   :");
	scanf("%d", &num);
	printf("4.选择是否有括号:   1.有  2.无  :");
	scanf("%d", &sign4);
	printf("5.选择是否有小数：  1.有  2.无  :");
	scanf("%d", &sign5);
	printf("6.是否输出到文件：  1.是  2.否  :");
	scanf("%d", &sign6);
	printf("\n<<<<<<<随机出题>>>>>>>\n");
	for (i = 0; i < n; i++)
	{
		printf("%d.", i+1);
		srand(ran(x));
		j = create1(i,OF, max, num, sign5,x);
		if (sign4 == 1)create2(OF, i, j,x);
		for (k = 0; k < j; k++)
		{
			if (k % 2 == 0) {
				strcat(str[i], OF[i][k].shu);
				printf("%s", OF[i][k].shu);
			}
			else {
				strcat(str[i], OF[i][k].op);
				printf("%s", OF[i][k].op);
			}
		}
		printf("\n");
	}
	if (sign6 == 1)cun(str, n);
	return 0;
}
