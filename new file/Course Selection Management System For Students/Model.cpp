#include <stdio.h>
#include <string.h>
#include "Model.h"
#include "View.h"


void Init_Student_Course(Stud *&ST, list &l)
{
	for (int i = 1; i <= StudentNum; i++)
		l[i] = NULL;

	ST = new Stud;
	ST->next = NULL;
}

void Student_Create(Stud *&ST)
{
	int a = 0;
	extern int Student_Num;
	Stud *p = new Stud;
	Stud *s = new Stud;
	s = ST;

	printf("姓名： ");
	scanf("%s", p->chStud_Name);
	printf("\r\n性别： ");
	scanf("%s", p->chStud_Sex);
	printf("\r\n学号： ");
	scanf("%d", &(p->chStud_Number));

	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = p;
	p->next = NULL;
	Student_Num++;
	printf("\r\n信息导入成功！ ");

	printf("\r\n是否继续导入信息？\r\n");
	printf("1、确认\t\t2、返回\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Student_Create(ST);
	}
	else
		printf("返回菜单！\r\n");
}

void Course_Create(Stud *ST, list &l)
{
	Course *q = new Course;
	int a = 0;
label:
	printf("请输入添加学生学号：");
	scanf("%d", &a);
	while (ST != NULL)
	{
		if (ST->chStud_Number == a)
		{
			printf("是否是该学生？\r");
			printf("姓名： "); puts(ST->chStud_Name);
			printf("性别： "); puts(ST->chStud_Sex);
			printf("学号： "); printf("%d", ST->chStud_Number);
			break;
		}
		else
			ST = ST->next;
		if (ST == NULL)
		{
			printf("\r\n输入有误！请重试！\r\n");
			goto label;
		}
	}

	l[a] = q;
	do
	{
		Course *p = new Course;
		printf("\r\n请输入课程： ");
		scanf("%s", p->chCourse_Name);
		printf("\r\n成绩： ");
		scanf("%lf", &(p->dCourse_Score));
		q->after = p;//尾插法加入结点
		q = q->after;
		printf("\r\n继续输入请按1，退出输入请按0\r\n");
		scanf("%d", &a);
	} while (a);
	q->after = NULL;
	printf("\r\n课程导入成功！ ");

	printf("\r\n是否继续导入其他同学课程？\r\n");
	printf("1、确认\t\t2、返回\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Course_Create(ST, l);
	}
	else
		printf("返回菜单！\r\n");
}

void Update_Student(Stud *&ST)
{
	printf("请输入需要修改的学生姓名：");
	Stud *p = new Stud;//指向修改学生结点
	p = ST;
	int a = 0;//switchf判断与x循环变量
	char chInput[MaxSize];
	scanf("%s", chInput);
	while (p != NULL)
	{
		if ((strcmp(p->chStud_Name, chInput)) == 0)
		{
			printf("\r\n学生信息如下：\r\n");
			printf("1、姓名： "); puts(p->chStud_Name);
			printf("2、性别： "); puts(p->chStud_Sex);
			printf("3、学号： "); printf("%d", p->chStud_Number);
			break;
		}
		p = p->next;
	}

	printf("\r请输入修改项:（1 2）\n");
	do
	{
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("修改后的姓名：");
			memset(p->chStud_Name, 0, sizeof(p->chStud_Name));
			scanf("%s", p->chStud_Name);
			a = 0;
			printf("信息修改成功！\r\n");
			break;

		case 2:
			printf("修改后的性别：");
			memset(p->chStud_Sex, 0, sizeof(p->chStud_Sex));
			scanf("%s", p->chStud_Sex);
			a = 0;
			printf("信息修改成功！\r\n");
			break;

		default:
			printf("输入有误！请重试！\r\n");
		}

	} while (a);

}

void Update_Course(Stud *ST, list &l)
{
	int a = 0;
	double b = 0;
Begin:
	printf("\n请输入查询学生姓名：");
	char chinput[MaxSize];
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
				printf("成绩： ");
				printf("%.2lf", q->dCourse_Score);
			}
			break;
		}
		ST = ST->next;
	}
	if (ST == NULL)
	{
		printf("\r\n该学生信息未检索到！\r\n");
		goto Begin;
	}
	q = l[ST->chStud_Number];//重新置为起点
	printf("\r\n请输入要修改的课程：");
	memset(chinput, 0, sizeof(chinput));
	scanf("%s", chinput);
	while (q->after != NULL)
	{
		q = q->after;
		if (strcmp(q->chCourse_Name, chinput) == 0)
		{
			printf("\r\n课程： ");
			puts(q->chCourse_Name);
			printf("成绩： ");
			printf("%.2lf", q->dCourse_Score);
			break;
		}
	}
	do
	{
		printf("\r\n修改成绩输入1，修改课程输入2：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("\r\n请输入修改后的成绩：");
			scanf("%lf", &b);
			q->dCourse_Score = b;
			printf("成绩修改成功！");
			break;
		case 2:
			printf("\r\n请输入修改后的课程：");
			memset(q->chCourse_Name, 0, sizeof(q->chCourse_Name));
			scanf("%s", q->chCourse_Name);
			printf("课程修改成功！");
			break;
		default:
			printf("\r\n输入错误请重试！");
			a = 0;
		}
	} while (a == 0);

}

void Delete_Student(Stud *&ST, list &l)
{
	Stud *pre, *s;//前驱节点
	s = pre = ST;
	int a = 0;
	//extern int Student_Num;
Begin:
	printf("\r\n请输入查询学生姓名：");
	char chinput[MaxSize];
	Course *q, *p;
	scanf("%s", chinput);
	while (s != NULL)
	{
		if ((strcmp(s->chStud_Name, chinput)) == 0)
		{
			printf("查询成功！\r\n");
			printf("姓名： "); puts(s->chStud_Name);
			printf("性别： "); puts(s->chStud_Sex);
			printf("学号： "); printf("%d", s->chStud_Number);
			q = l[s->chStud_Number];
			if(q->after != NULL)
			{
				while (q->after != NULL)
				{
					q = q->after;
					printf("\r\n课程： ");
					puts(q->chCourse_Name);
					printf("成绩： ");
					printf("%.2lf", q->dCourse_Score);
				}
				break;
			}
			else
			{
				printf("----------我是有底线的----------");
			}
		}
		pre = s;
		s = s->next;
	}
	if (ST == NULL)
	{
		printf("\r\n该学生信息未检索到！\r\n");
		goto Begin;
	}
	printf("\r\n确认是否删除？\r\n");
	printf("1、确认\t\t2、返回\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		pre->next = s->next;
		delete s;
		Student_Num--;
		printf("删除成功！");
	}
	else
		printf("取消删除。");
}

void Sort_Student(Stud* ST, list l)
{
	int a[StudentNum];//用于存放学生学号
	double b[StudentNum];//用于存放学生成绩
	int i = 1, j = 0, k;//学号,数组值,存放j获取的值
	int temp1, temp2;//存放中间值
	Course *q;
	extern int Student_Num;
	char chinput[MaxSize];
	printf("请输入要查询排名的课程：");
	scanf("%s", chinput);
	for (i; i <= Student_Num; i++)
	{
		q = l[i];
		while (q != NULL)
		{
			if (strcmp(q->chCourse_Name, chinput) == 0)
			{
				a[j] = i;//将所有成绩及学号存入其中，稍后进行排序
				b[j] = q->dCourse_Score;
				j++;
				break;
			}
			else
				q = q->after;
		}
	}
	k = j;
	for (int i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp1 = b[j + 1];
				b[j + 1] = b[j];
				b[j] = temp1;
				temp2 = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp2;
			}
		}
	}
	for (i = 0; i < k; i++)
		printf("第%d名 学号：%d 成绩：%.2lf\r\n", (i + 1), a[i], b[i]);
}

void Info_Leading(Stud*& ST, list* l)
{
	while (1)
	{
		int a = 0;
		extern int Student_Num;
		Stud* p = new Stud;
		Stud* s = new Stud;
		s = ST;

		printf("姓名： ");
		scanf("%s", p->chStud_Name);
		printf("\r\n性别： ");
		scanf("%s", p->chStud_Sex);
		printf("\r\n学号： ");
		scanf("%d", &(p->chStud_Number));

		while (s->next != NULL)
		{
			s = s->next;
		}
		s->next = p;
		p->next = NULL;
		Student_Num++;
	}

}
