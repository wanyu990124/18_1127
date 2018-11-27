/*通过键盘输入3名学生4门课程的成绩，
分别求每个学生的平均成绩和每门课程的平均成绩。
要求所有成绩均放入一个4行5列的数组中，输入时同一人数据间用空格,不同人用回车
其中最后一列和最后一行分别放每个学生的平均成绩、每门课程的平均成绩及班级总平均分。*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
int main() {
	float a[4][5], sum1, sum2;
	int i, j;
	for (i = 0; i<3; i++)
		for (j = 0; j<4; j++)
			scanf("%f", &a[i][j]);
	for (i = 0; i<3; i++) {
		sum1 = 0;
		for (j = 0; j<4; j++)
			sum1 += a[i][j];
		a[i][4] = sum1 / 4;
	}
	for (j = 0; j<5; j++) {
		sum2 = 0;
		for (i = 0; i<3; i++)
			sum2 += a[i][j];
		a[3][j] = sum2 / 3;
	}
	for (i = 0; i<4; i++) {
		for (j = 0; j<5; j++)
			printf("%6.2f", a[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}

/*一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程
　　　找出1000以内的所有完数。*/
#include<stdio.h>
#include<stdlib.h>
int main() {
	static int k[10];
	int i, j, n, s;
	for (j = 2; j<1000; j++) {
		n = -1;
		s = j;
		for (i = 1; i<j; i++) {
			if ((j%i) == 0) {
				n++;
				s = s - i;
				k[n] = i;
			}
		}
		if (s == 0) {
			printf("%d is a wanshu: ", j);
			for (i = 0; i<n; i++)
				printf("%d,", k[i]);
			printf("%d\n", k[n]);
		}
	}
	system("pause");
	return 0;
}

/*完善程序，实现将输入的字符串反序输出，
如输入windows 输出swodniw。*/
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int main() {
	char c[200], c1;
	int i, j, k;
	printf("Enter a string: ");
	scanf("%s", c);
	k = strlen(c);
	for (i = 0, j = k - 1; i<k / 2; i++, j--) {
		c1 = c[i]; c[i] = c[j]; c[j] = c1;
	}
	printf("%s\n", c);
	system("pause");
	return 0;
}


//指针法:
void invert(char *s)
{
	int i, j, k;
	char t;
	k = strlen(s);
	for (i = 0, j = k - 1; i<k / 2; i++, j--)
	{
		t = *(s + i); *(s + i) = *(s + j); *(s + j) = t;
	}
}

int main() {
	FILE *fp;
	char str[200], *p, i, j;
	if ((fp = fopen("p9_2.out", "w")) == NULL) {
		printf("cannot open the file\n");
		exit(0);
	}
	printf("input str:\n");
	gets(str);
	printf("\n%s", str);
	fprintf(fp, "%s", str);
	invert(str);
	printf("\n%s", str);
	fprintf(fp, "\n%s", str);
	fclose(fp);
}