#ifndef Control_h
#define Control_h

#include "Model.h"

#define USER_NAME "CSUFT"
#define USER_PASSWORD "666666"

typedef enum Menu
{
	Exit, Add, Delete, Change, Search, Show ,  Lessons
}MENU;//�˵�


void MainMenu();//���˵�����
void Init();//ѧ��ѡ�ι���ϵͳ��ʼ��,��ʾ������
void Head();//ѧ��ѡ�ι���ϵͳ�ַ�ͼ��
void Login();//��¼ϵͳ
int isLogin();//�ж��Ƿ��¼�ɹ�
int MenuSelect();//�˵�ѡ��
void Lessons_Information();//�γ���Ϣ
void Quit();//�˳���������½������˵�
void SaveData();//��
void ReadData();//ȡ

#endif /* Control_h */