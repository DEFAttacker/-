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
函 数 名  : MainMenu
功能描述  : 主菜单界面
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
日    期   : 2019年12月18日
作    者   : 颜廷伟
修改内容   : 新生成函数

*****************************************************************************/
void MainMenu()
{

	if (isLogin())
	{
		//登录成功
		switch (MenuSelect())	//菜单选择
		{
		case Exit:		//退出程序
			system("cls");
			Head();
			Quit();	//退出或返回主菜单
			break;
		case Lessons:	//课程信息
			system("cls");
			Lessons_Information();
			Quit();
			break;
		case Show:		//显示所有学生信息
			system("cls");
			Student_Display(ST);
			Quit();
			break;
		case Add:		//添加学生及课程信息
			system("cls");
			Student_Create(ST);
			printf("接下来进行课程添加：\r\n");
			Course_Create(ST, l);
			Quit();
			break;
		case Change:	//修改学生信息
			system("cls");
			Update_Student(ST);
			printf("\r\n\r\n接下来进行课程修改：\r\n");
			Update_Course(ST, l);
			Quit();
			break;
		case Delete:	//删除学生信息
			system("cls");
			Delete_Student(ST, l);
			Quit();
			break;
		case Search:	//查询学生信息
			system("cls");
			Retrieve_Student_Display(ST, l);
			Quit();
			break;
		}
	}
}

/****************************************************************************
函 数 名  : Init
功能描述  : 学生选课管理系统初始化,提示语载入
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
1.日    期   : 2019年12月17日
作    者   : 颜廷伟
修改内容   : 新生成函数
****************************************************************************/

void Init()
{
	int i;

	Init_Student_Course(ST, l);
	char incoming[] = { "即将进入学生选课管理系统......" };
	/****************初始化数据****************/
	//SetConsoleTitle("学生选课管理系统");
	system("mode con cols=120 lines=30");
	system("color f0");
	/****************载入界面*****************/
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

//学生信息管理系统字符图标
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
函 数 名  : Login
功能描述  : 登录系统
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
1.日    期   : 2019年12月17日
作    者   : 颜廷伟
修改内容   : 新生成函数
2.日    期   : 2019年12月18日
作    者   : 颜廷伟
修改内容   : 增加载入过渡

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
	printf("\n\n\n\n\t\t\t\t\t\t请输入您的账号密码:\n\n\n\n\n\n\t\t\t\t\t\t账号 : ");
	gets_s(UserName);
	printf("\n\n\n\t\t\t\t\t\t密码 : ");
	gets_s(UserWord);
	system("cls");

	for (i = 0; i < strlen(xing); i++)
	{
		printf("%c", xing[i]);
		Sleep(4);
	}
}

/****************************************************************************
函 数 名  : isLogin
功能描述  : 判断是否登录成功
输入参数  : 无
输出参数  : 无
返 回 值  : int
调用函数  :
被调函数  :

修改历史      :
1.日    期   : 2019年12月17日
作    者   : 颜廷伟
修改内容   : 新生成函数

****************************************************************************/
int isLogin()
{

	int times = 0;//密码输入次数
	size_t i;
	char shutdown[] = { "\n\n\n\n\n\t\t\t\t\t系统将于%d秒后关闭..." };
	while (!(strcmp(UserName, USER_NAME) == 0 && strcmp(UserWord, USER_PASSWORD) == 0))
	{
		times++;//密码输入错误 times++
		if (times > 3)
		{
			printf("\n\n\n\n\n\n\t\t\t\tt账号或密码输入错误累计达到%d次，系统将于3秒后关闭", times);
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
		printf("\n\n\n\n\t\t\t\t账号或密码输入错误,你还有%d次登录机会，按任意键重新登录...", 4 - times);
		getch();
		system("cls");
		Login();
	}
	return 1;
}
/****************************************************************************
函 数 名  : MenuSelect
功能描述  : 菜单选择
输入参数  : 无
输出参数  : 无
返 回 值  : int
调用函数  :
被调函数  :

修改历史      :
1.日    期   : 2019年12月18日
作    者   : 颜廷伟
修改内容   : 新生成函数

****************************************************************************/
int MenuSelect()
{
	char c;
	do
	{
		system("cls");
		Head();
		printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
		printf("\t\t\t\t   │              学生选课管理系统              │\n");
		printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
		printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │    1. 添加数据               2. 删除数据   │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │       3. 修改数据         4. 查询数据      │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │           5. 学生信息  6. 课程信息         │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │                 0. 退出程序                │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
		printf("\n\t\t\t\t\t\t  请您选择(0-6):");
		c = getche();
	} while (c < '0' || c > '6');
	return c - '0';
}
/****************************************************************************
函 数 名  : Lessons_Information
功能描述  : 课程信息
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

1.日    期   : 2019年12月18日
作    者   : 颜廷伟
修改内容   : 新生成函数

****************************************************************************/
void Lessons_Information()
{
	Head();
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  大学英语  ║   大物实验 ║   专业英语 ║   数据结构 ║     MySQL  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t║   近代史   ║   大学物理 ║   解析几何 ║   数学分析 ║     Java   ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
}



/****************************************************************************
函 数 名  : Quit
功能描述  : 退出程序或重新进入主菜单
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
1.日    期   : 2019年12月18日
作    者   : 颜廷伟
修改内容   : 新生成函数

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
	printf("\n\n\t\t\t\t要返回登录界面按任意键\t\t退出程序请按Esc键\n");
	ch = getch();
	if (ch == 0x1b)	//esc键按下
	{
		_exit(0);
	}
	//重新进入主菜单

	MainMenu();
}

/*****************************************************************************
函 数 名  : ReadData
功能描述  : 读取文件信息
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
1.
日    期   : 2019年12月28日
修改内容   : 新生成函数

*****************************************************************************/
void ReadData()
{
	Stud *pHead = NULL;
	Stud *pNew = NULL;

	FILE* fRead = fopen("S:\\stuInformation.dat", "rb");
	if (fRead == NULL)
	{
		SaveData();	//文件不存在就创建文件
		return;
	}
	rewind(fRead);	//将文件内部指针移回文件开头
	while (1)
	{
		pNew = (Stud*)malloc(sizeof(ST));	//申请一块内存
		fread(pNew, sizeof(ST), 1, fRead);	//1 表示读取一个Stud字节大小单元
		if (feof(fRead)) break;				//文件末尾退出
		//头插法插入数据
		pNew->next = pHead->next;
		pHead->next = pNew;
		pNew = NULL;
		Student_Num++;
	}
	fclose(fRead);
}

/*****************************************************************************
函 数 名  : SaveData
功能描述  : 写入文件信息
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

修改历史      :
1.
日    期   : 2019年12月28日
修改内容   : 新生成函数

*****************************************************************************/
void SaveData()
{
	FILE* fWrite = fopen("S:\\stuInformation.dat", "wb");
	if (fWrite == NULL)
	{
		system("cls");
		printf("保存失败...\n");
		Quit();
	}
	Stud *pCurrent = ST->next;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)		//遍历所有学生信息	
	{
		fwrite(pCurrent, sizeof(ST), 1, fWrite);
		pCurrent = pCurrent->next;	//指向下一个节点
	}
	pCurrent = NULL;
	fclose(fWrite);
}