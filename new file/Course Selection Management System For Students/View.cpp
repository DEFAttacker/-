#include <stdio.h>
#include <string.h>

#include "View.h"
#include "Model.h"


void Retrieve_Student_Display(Stud *ST, list l)
{
	printf("\n请输入查询学生姓名：");
	char chinput[MaxSize];
	int nCourseNum = 0;
	double dCourseSum = 0;
	Course *q;
	scanf("%s", chinput);
	while (ST != NULL)
	{
		if ((strcmp(ST->chStud_Name, chinput)) == 0)
		{
			printf("查询成功！\r\n");
			printf("姓名： "); puts(ST->chStud_Name);
			printf("性别： "); puts(ST->chStud_Sex);
			printf("学号： "); printf("%d", ST->chStud_Number);
			q = l[ST->chStud_Number];
			while (q->after != NULL)
			{
				q = q->after;
				printf("\r\n课程： ");
				puts(q->chCourse_Name);
				nCourseNum++;
				printf("成绩： ");
				printf("%.2lf", q->dCourse_Score);
				dCourseSum += q->dCourse_Score;
			}
			printf("\r\n%s的课程平均成绩为：%.2lf", ST->chStud_Name, dCourseSum / nCourseNum);
			break;
		}
		ST = ST->next;

	}
	if (ST == NULL)
		printf("\r\n该学生信息未检索到！\r\n");

	int a = 0;
	printf("\r\n是否继续查找？\r\n");
	printf("1、确认\t\t2、返回\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Retrieve_Student_Display(ST, l);
	}
	else
		printf("返回菜单！\r\n");
}

void Retrieve_Course_Display(Stud *ST, list l)
{
	int nStudent_num = 0;
	double dScore_Sum = 0;
	int i = 1;
	Stud *p;
	Course *q;
	p = ST;
	char chinput[MaxSize];
	extern int Student_Num;
	printf("请输入你要查找的课程名称：");
	scanf("%s", chinput);
	for (i; i <= Student_Num; i++)
	{
		q = l[i];
		while (q != NULL)
		{
			if (strcmp(q->chCourse_Name, chinput) == 0)
				break;
			else
				q = q->after;
		}

		if (q == NULL)//未查找到则直接查找下一个
			break;

		while (p != NULL)
		{
			if (p->chStud_Number == i)
				break;
			else
				p = p->next;
		}
		printf("学生：%s\t", p->chStud_Name);
		printf("成绩：%.2lf\r\n", q->dCourse_Score);
		nStudent_num++;
		dScore_Sum += q->dCourse_Score;
		p = ST;
	}
	printf("\r\n%s共%d人选修，%s的平均成绩为%.2lf\r\n", chinput, nStudent_num, chinput, dScore_Sum / nStudent_num);
}

void Student_Display(Stud* ST)
{
	printf("为您显示所有的学生信息：\r\n");
	while (ST->next != NULL)
	{
		ST = ST->next;
		printf("\r\n姓名： ");
		printf("%s\t", ST->chStud_Name);
		printf("\r\n性别： ");
		printf("%s\t", ST->chStud_Sex);
		printf("\r\n学号： ");
		printf("%d\r\n", ST->chStud_Number);
	}
	printf("\r\n以上为全部学生信息。");
}