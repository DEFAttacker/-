#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#include "Control.h"
#include "Model.h"
#include "View.h"

char UserName[10];
char UserWord[10];

Stud* ST;
list l;

/*****************************************************************************
�� �� ��  : MainMenu
��������  : ���˵�����
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
��    ��   : 2019��12��18��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���

*****************************************************************************/
void MainMenu()
{

	if (isLogin())
	{
		//��¼�ɹ�
		switch (MenuSelect())	//�˵�ѡ��
		{
		case Exit:		//�˳�����
			system("cls");
			Head();
			Quit();	//�˳��򷵻����˵�
			break;
		case Lessons:	//�γ���Ϣ
			system("cls");
			Lessons_Information();
			Quit();
			break;
		case Show:		//��ʾ����ѧ����Ϣ
			system("cls");
			Student_Display(ST);
			Quit();
			break;
		case Add:		//���ѧ�����γ���Ϣ
			system("cls");
			Student_Create(ST);
			printf("���������пγ���ӣ�\r\n");
			Course_Create(ST, l);
			Quit();
			break;
		case Change:	//�޸�ѧ����Ϣ
			system("cls");
			Update_Student(ST);
			printf("\r\n\r\n���������пγ��޸ģ�\r\n");
			Update_Course(ST, l);
			Quit();
			break;
		case Delete:	//ɾ��ѧ����Ϣ
			system("cls");
			Delete_Student(ST, l);
			Quit();
			break;
		case Search:	//��ѯѧ����Ϣ
			system("cls");
			Retrieve_Student_Display(ST, l);
			Quit();
			break;
		}
	}
}

/****************************************************************************
�� �� ��  : Init
��������  : ѧ��ѡ�ι���ϵͳ��ʼ��,��ʾ������
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2019��12��17��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���
****************************************************************************/

void Init()
{
	int i;

	Init_Student_Course(ST, l);
	char incoming[] = { "��������ѧ��ѡ�ι���ϵͳ......" };
	/****************��ʼ������****************/
	//SetConsoleTitle("ѧ��ѡ�ι���ϵͳ");
	system("mode con cols=120 lines=30");
	system("color f0");
	/****************�������*****************/
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	for (i = 0; i < strlen(incoming); i++)
	{
		printf("%c", incoming[i]);
		Sleep(100);
	}
	system("cls");
	Head();
	Login();
}

//ѧ����Ϣ����ϵͳ�ַ�ͼ��
void Head()
{
	printf("\t\t   _____                                  _____        _              _\n");
	printf("\t\t  / ____|                                / ____|      | |            | |  (_)\n");
	printf("\t\t | |       ___  _   _  _ __  ___   ___  | (___    ___ | |  ___   ___ | |_  _   ___   _ __\n");
	printf("\t\t | |      / _ \\| | | || '__|/ __| / _ \\  \\___ \\  / _ \\| | / _ \\ / __|| __|| | / _ \\ | '_ \\ \n");
	printf("\t\t | |____  |(_)|| |_| || |   \\__ \\|  __/  ____) ||  __/| ||  __/| (__ | |_ | || (_) || | | |\n");
	printf("\t\t  \\_____| \\___/ \\__,_||_|   |___/ \\___| |_____/  \\___||_| \\___| \\___| \\__||_| \\___/ |_| |_|\n");
	printf("\n\n\n");
}

/****************************************************************************
�� �� ��  : Login
��������  : ��¼ϵͳ
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2019��12��17��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���
2.��    ��   : 2019��12��18��
��    ��   : ��͢ΰ
�޸�����   : �����������

****************************************************************************/
void Login()
{
	char xing[] = { "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " };
	size_t i;
	extern char UserName[10];
	extern char UserWord[10];
	for (i = 0; i < strlen(xing); i++)
	{
		printf("%c", xing[i]);
		Sleep(5);
	}
	printf("\n\n\n\n\t\t\t\t\t\t�����������˺�����:\n\n\n\n\n\n\t\t\t\t\t\t�˺� : ");
	gets_s(UserName);
	printf("\n\n\n\t\t\t\t\t\t���� : ");
	gets_s(UserWord);
	system("cls");

	for (i = 0; i < strlen(xing); i++)
	{
		printf("%c", xing[i]);
		Sleep(4);
	}
}

/****************************************************************************
�� �� ��  : isLogin
��������  : �ж��Ƿ��¼�ɹ�
�������  : ��
�������  : ��
�� �� ֵ  : int
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2019��12��17��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���

****************************************************************************/
int isLogin()
{

	int times = 0;//�����������
	size_t i;
	char shutdown[] = { "\n\n\n\n\n\t\t\t\t\tϵͳ����%d���ر�..." };
	while (!(strcmp(UserName, USER_NAME) == 0 && strcmp(UserWord, USER_PASSWORD) == 0))
	{
		times++;//����������� times++
		if (times > 3)
		{
			printf("\n\n\n\n\n\n\t\t\t\tt�˺Ż�������������ۼƴﵽ%d�Σ�ϵͳ����3���ر�", times);
			Sleep(1000);
			system("cls");
			for (i = 0; i < 3; i++)
			{
				printf(shutdown, 3 - i);
				Sleep(1000
					);
				system("cls");
			}
			exit(0);
		}
		printf("\n\n\n\n\t\t\t\t�˺Ż������������,�㻹��%d�ε�¼���ᣬ����������µ�¼...", 4 - times);
		getch();
		system("cls");
		Login();
	}
	return 1;
}
/****************************************************************************
�� �� ��  : MenuSelect
��������  : �˵�ѡ��
�������  : ��
�������  : ��
�� �� ֵ  : int
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2019��12��18��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���

****************************************************************************/
int MenuSelect()
{
	char c;
	do
	{
		system("cls");
		Head();
		printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
		printf("\t\t\t\t   ��              ѧ��ѡ�ι���ϵͳ              ��\n");
		printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
		printf("\t\t\t\t   ��                                            ��\n");
		printf("\t\t\t\t   ��    1. �������               2. ɾ������   ��\n");
		printf("\t\t\t\t   ��                                            ��\n");
		printf("\t\t\t\t   ��       3. �޸�����         4. ��ѯ����      ��\n");
		printf("\t\t\t\t   ��                                            ��\n");
		printf("\t\t\t\t   ��           5. ѧ����Ϣ  6. �γ���Ϣ         ��\n");
		printf("\t\t\t\t   ��                                            ��\n");
		printf("\t\t\t\t   ��                 0. �˳�����                ��\n");
		printf("\t\t\t\t   ��                                            ��\n");
		printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");
		printf("\n\t\t\t\t\t\t  ����ѡ��(0-6):");
		c = getche();
	} while (c < '0' || c > '6');
	return c - '0';
}
/****************************************************************************
�� �� ��  : Lessons_Information
��������  : �γ���Ϣ
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

1.��    ��   : 2019��12��18��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���

****************************************************************************/
void Lessons_Information()
{
	Head();
	printf("\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t�U  ��ѧӢ��  �U   ����ʵ�� �U   רҵӢ�� �U   ���ݽṹ �U     MySQL  �U\n");
	printf("\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t�U   ����ʷ   �U   ��ѧ���� �U   �������� �U   ��ѧ���� �U     Java   �U\n");
	printf("\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}



/****************************************************************************
�� �� ��  : Quit
��������  : �˳���������½������˵�
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2019��12��18��
��    ��   : ��͢ΰ
�޸�����   : �����ɺ���

****************************************************************************/
void Quit()
{
	char ch;
	int i;
	printf("\n\t ");
	for (i = 0; i < 50; i++)
	{
		printf("* ");
		Sleep(10);
	}
	printf("\n\n\t\t\t\tҪ���ص�¼���水�����\t\t�˳������밴Esc��\n");
	ch = getch();
	if (ch == 0x1b)	//esc������
	{
		_exit(0);
	}
	//���½������˵�

	MainMenu();
}

/*****************************************************************************
�� �� ��  : ReadData
��������  : ��ȡ�ļ���Ϣ
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
1.
��    ��   : 2019��12��28��
�޸�����   : �����ɺ���

*****************************************************************************/
void ReadData()
{
	Stud *pHead = NULL;
	Stud *pNew = NULL;

	FILE* fRead = fopen("S:\\stuInformation.dat", "rb");
	if (fRead == NULL)
	{
		SaveData();	//�ļ������ھʹ����ļ�
		return;
	}
	rewind(fRead);	//���ļ��ڲ�ָ���ƻ��ļ���ͷ
	while (1)
	{
		pNew = (Stud*)malloc(sizeof(ST));	//����һ���ڴ�
		fread(pNew, sizeof(ST), 1, fRead);	//1 ��ʾ��ȡһ��Stud�ֽڴ�С��Ԫ
		if (feof(fRead)) break;				//�ļ�ĩβ�˳�
		//ͷ�巨��������
		pNew->next = pHead->next;
		pHead->next = pNew;
		pNew = NULL;
		Student_Num++;
	}
	fclose(fRead);
}

/*****************************************************************************
�� �� ��  : SaveData
��������  : д���ļ���Ϣ
�������  : ��
�������  : ��
�� �� ֵ  : void
���ú���  :
��������  :

�޸���ʷ      :
1.
��    ��   : 2019��12��28��
�޸�����   : �����ɺ���

*****************************************************************************/
void SaveData()
{
	FILE* fWrite = fopen("S:\\stuInformation.dat", "wb");
	if (fWrite == NULL)
	{
		system("cls");
		printf("����ʧ��...\n");
		Quit();
	}
	Stud *pCurrent = ST->next;	//ָ���һ���ڵ� �������Ϊ NULL pCurrentΪ NULL
	while (pCurrent != NULL)		//��������ѧ����Ϣ	
	{
		fwrite(pCurrent, sizeof(ST), 1, fWrite);
		pCurrent = pCurrent->next;	//ָ����һ���ڵ�
	}
	pCurrent = NULL;
	fclose(fWrite);
}