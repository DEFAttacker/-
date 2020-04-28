#ifndef Control_h
#define Control_h

#include "Model.h"

#define USER_NAME "CSUFT"
#define USER_PASSWORD "666666"

typedef enum Menu
{
	Exit, Add, Delete, Change, Search, Show ,  Lessons
}MENU;//菜单


void MainMenu();//主菜单界面
void Init();//学生选课管理系统初始化,提示语载入
void Head();//学生选课管理系统字符图标
void Login();//登录系统
int isLogin();//判断是否登录成功
int MenuSelect();//菜单选择
void Lessons_Information();//课程信息
void Quit();//退出程序或重新进入主菜单
void SaveData();//存
void ReadData();//取

#endif /* Control_h */