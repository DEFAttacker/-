#include <stdio.h>
#include <string.h>

#include "View.h"
#include "Model.h"


void Retrieve_Student_Display(Stud *ST, list l)
{
	printf("\n�������ѯѧ��������");
	char chinput[MaxSize];
	int nCourseNum = 0;
	double dCourseSum = 0;
	Course *q;
	scanf("%s", chinput);
	while (ST != NULL)
	{
		if ((strcmp(ST->chStud_Name, chinput)) == 0)
		{
			printf("��ѯ�ɹ���\r\n");
			printf("������ "); puts(ST->chStud_Name);
			printf("�Ա� "); puts(ST->chStud_Sex);
			printf("ѧ�ţ� "); printf("%d", ST->chStud_Number);
			q = l[ST->chStud_Number];
			while (q->after != NULL)
			{
				q = q->after;
				printf("\r\n�γ̣� ");
				puts(q->chCourse_Name);
				nCourseNum++;
				printf("�ɼ��� ");
				printf("%.2lf", q->dCourse_Score);
				dCourseSum += q->dCourse_Score;
			}
			printf("\r\n%s�Ŀγ�ƽ���ɼ�Ϊ��%.2lf", ST->chStud_Name, dCourseSum / nCourseNum);
			break;
		}
		ST = ST->next;

	}
	if (ST == NULL)
		printf("\r\n��ѧ����Ϣδ��������\r\n");

	int a = 0;
	printf("\r\n�Ƿ�������ң�\r\n");
	printf("1��ȷ��\t\t2������\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Retrieve_Student_Display(ST, l);
	}
	else
		printf("���ز˵���\r\n");
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
	printf("��������Ҫ���ҵĿγ����ƣ�");
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

		if (q == NULL)//δ���ҵ���ֱ�Ӳ�����һ��
			break;

		while (p != NULL)
		{
			if (p->chStud_Number == i)
				break;
			else
				p = p->next;
		}
		printf("ѧ����%s\t", p->chStud_Name);
		printf("�ɼ���%.2lf\r\n", q->dCourse_Score);
		nStudent_num++;
		dScore_Sum += q->dCourse_Score;
		p = ST;
	}
	printf("\r\n%s��%d��ѡ�ޣ�%s��ƽ���ɼ�Ϊ%.2lf\r\n", chinput, nStudent_num, chinput, dScore_Sum / nStudent_num);
}

void Student_Display(Stud* ST)
{
	printf("Ϊ����ʾ���е�ѧ����Ϣ��\r\n");
	while (ST->next != NULL)
	{
		ST = ST->next;
		printf("\r\n������ ");
		printf("%s\t", ST->chStud_Name);
		printf("\r\n�Ա� ");
		printf("%s\t", ST->chStud_Sex);
		printf("\r\nѧ�ţ� ");
		printf("%d\r\n", ST->chStud_Number);
	}
	printf("\r\n����Ϊȫ��ѧ����Ϣ��");
}