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

	printf("������ ");
	scanf("%s", p->chStud_Name);
	printf("\r\n�Ա� ");
	scanf("%s", p->chStud_Sex);
	printf("\r\nѧ�ţ� ");
	scanf("%d", &(p->chStud_Number));

	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = p;
	p->next = NULL;
	Student_Num++;
	printf("\r\n��Ϣ����ɹ��� ");

	printf("\r\n�Ƿ����������Ϣ��\r\n");
	printf("1��ȷ��\t\t2������\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Student_Create(ST);
	}
	else
		printf("���ز˵���\r\n");
}

void Course_Create(Stud *ST, list &l)
{
	Course *q = new Course;
	int a = 0;
label:
	printf("���������ѧ��ѧ�ţ�");
	scanf("%d", &a);
	while (ST != NULL)
	{
		if (ST->chStud_Number == a)
		{
			printf("�Ƿ��Ǹ�ѧ����\r");
			printf("������ "); puts(ST->chStud_Name);
			printf("�Ա� "); puts(ST->chStud_Sex);
			printf("ѧ�ţ� "); printf("%d", ST->chStud_Number);
			break;
		}
		else
			ST = ST->next;
		if (ST == NULL)
		{
			printf("\r\n�������������ԣ�\r\n");
			goto label;
		}
	}

	l[a] = q;
	do
	{
		Course *p = new Course;
		printf("\r\n������γ̣� ");
		scanf("%s", p->chCourse_Name);
		printf("\r\n�ɼ��� ");
		scanf("%lf", &(p->dCourse_Score));
		q->after = p;//β�巨������
		q = q->after;
		printf("\r\n���������밴1���˳������밴0\r\n");
		scanf("%d", &a);
	} while (a);
	q->after = NULL;
	printf("\r\n�γ̵���ɹ��� ");

	printf("\r\n�Ƿ������������ͬѧ�γ̣�\r\n");
	printf("1��ȷ��\t\t2������\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Course_Create(ST, l);
	}
	else
		printf("���ز˵���\r\n");
}

void Update_Student(Stud *&ST)
{
	printf("��������Ҫ�޸ĵ�ѧ��������");
	Stud *p = new Stud;//ָ���޸�ѧ�����
	p = ST;
	int a = 0;//switchf�ж���xѭ������
	char chInput[MaxSize];
	scanf("%s", chInput);
	while (p != NULL)
	{
		if ((strcmp(p->chStud_Name, chInput)) == 0)
		{
			printf("\r\nѧ����Ϣ���£�\r\n");
			printf("1�������� "); puts(p->chStud_Name);
			printf("2���Ա� "); puts(p->chStud_Sex);
			printf("3��ѧ�ţ� "); printf("%d", p->chStud_Number);
			break;
		}
		p = p->next;
	}

	printf("\r�������޸���:��1 2��\n");
	do
	{
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("�޸ĺ��������");
			memset(p->chStud_Name, 0, sizeof(p->chStud_Name));
			scanf("%s", p->chStud_Name);
			a = 0;
			printf("��Ϣ�޸ĳɹ���\r\n");
			break;

		case 2:
			printf("�޸ĺ���Ա�");
			memset(p->chStud_Sex, 0, sizeof(p->chStud_Sex));
			scanf("%s", p->chStud_Sex);
			a = 0;
			printf("��Ϣ�޸ĳɹ���\r\n");
			break;

		default:
			printf("�������������ԣ�\r\n");
		}

	} while (a);

}

void Update_Course(Stud *ST, list &l)
{
	int a = 0;
	double b = 0;
Begin:
	printf("\n�������ѯѧ��������");
	char chinput[MaxSize];
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
				printf("�ɼ��� ");
				printf("%.2lf", q->dCourse_Score);
			}
			break;
		}
		ST = ST->next;
	}
	if (ST == NULL)
	{
		printf("\r\n��ѧ����Ϣδ��������\r\n");
		goto Begin;
	}
	q = l[ST->chStud_Number];//������Ϊ���
	printf("\r\n������Ҫ�޸ĵĿγ̣�");
	memset(chinput, 0, sizeof(chinput));
	scanf("%s", chinput);
	while (q->after != NULL)
	{
		q = q->after;
		if (strcmp(q->chCourse_Name, chinput) == 0)
		{
			printf("\r\n�γ̣� ");
			puts(q->chCourse_Name);
			printf("�ɼ��� ");
			printf("%.2lf", q->dCourse_Score);
			break;
		}
	}
	do
	{
		printf("\r\n�޸ĳɼ�����1���޸Ŀγ�����2��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("\r\n�������޸ĺ�ĳɼ���");
			scanf("%lf", &b);
			q->dCourse_Score = b;
			printf("�ɼ��޸ĳɹ���");
			break;
		case 2:
			printf("\r\n�������޸ĺ�Ŀγ̣�");
			memset(q->chCourse_Name, 0, sizeof(q->chCourse_Name));
			scanf("%s", q->chCourse_Name);
			printf("�γ��޸ĳɹ���");
			break;
		default:
			printf("\r\n������������ԣ�");
			a = 0;
		}
	} while (a == 0);

}

void Delete_Student(Stud *&ST, list &l)
{
	Stud *pre, *s;//ǰ���ڵ�
	s = pre = ST;
	int a = 0;
	//extern int Student_Num;
Begin:
	printf("\r\n�������ѯѧ��������");
	char chinput[MaxSize];
	Course *q, *p;
	scanf("%s", chinput);
	while (s != NULL)
	{
		if ((strcmp(s->chStud_Name, chinput)) == 0)
		{
			printf("��ѯ�ɹ���\r\n");
			printf("������ "); puts(s->chStud_Name);
			printf("�Ա� "); puts(s->chStud_Sex);
			printf("ѧ�ţ� "); printf("%d", s->chStud_Number);
			q = l[s->chStud_Number];
			if(q->after != NULL)
			{
				while (q->after != NULL)
				{
					q = q->after;
					printf("\r\n�γ̣� ");
					puts(q->chCourse_Name);
					printf("�ɼ��� ");
					printf("%.2lf", q->dCourse_Score);
				}
				break;
			}
			else
			{
				printf("----------�����е��ߵ�----------");
			}
		}
		pre = s;
		s = s->next;
	}
	if (ST == NULL)
	{
		printf("\r\n��ѧ����Ϣδ��������\r\n");
		goto Begin;
	}
	printf("\r\nȷ���Ƿ�ɾ����\r\n");
	printf("1��ȷ��\t\t2������\r\n");
	scanf("%d", &a);
	if (a == 1)
	{
		pre->next = s->next;
		delete s;
		Student_Num--;
		printf("ɾ���ɹ���");
	}
	else
		printf("ȡ��ɾ����");
}

void Sort_Student(Stud* ST, list l)
{
	int a[StudentNum];//���ڴ��ѧ��ѧ��
	double b[StudentNum];//���ڴ��ѧ���ɼ�
	int i = 1, j = 0, k;//ѧ��,����ֵ,���j��ȡ��ֵ
	int temp1, temp2;//����м�ֵ
	Course *q;
	extern int Student_Num;
	char chinput[MaxSize];
	printf("������Ҫ��ѯ�����Ŀγ̣�");
	scanf("%s", chinput);
	for (i; i <= Student_Num; i++)
	{
		q = l[i];
		while (q != NULL)
		{
			if (strcmp(q->chCourse_Name, chinput) == 0)
			{
				a[j] = i;//�����гɼ���ѧ�Ŵ������У��Ժ��������
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
		printf("��%d�� ѧ�ţ�%d �ɼ���%.2lf\r\n", (i + 1), a[i], b[i]);
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

		printf("������ ");
		scanf("%s", p->chStud_Name);
		printf("\r\n�Ա� ");
		scanf("%s", p->chStud_Sex);
		printf("\r\nѧ�ţ� ");
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
