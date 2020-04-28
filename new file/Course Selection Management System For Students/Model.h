#ifndef Model_h
#define Model_h

#define NameSize 20
#define CourseSize 50
#define CourseNum 100
#define StudentNum 1000
#define MaxSize 100

extern int Student_Num;

typedef struct Stud
{
	char chStud_Name[NameSize];//姓名
	char chStud_Sex[3];//性别
	int chStud_Number;//学号
	struct Stud* next;
}Stud;

typedef struct Course
{
	char chCourse_Name[CourseSize];
	double dCourse_Score;
	struct Course* after;
}*list[StudentNum + 1];

void Init_Student_Course(Stud*& ST, list& l);
void Student_Create(Stud*& ST);
void Course_Create(Stud* ST, list& l);
void Update_Student(Stud*& ST);
void Update_Course(Stud* ST, list& l);
void Delete_Student(Stud*& ST, list& l);
void Sort_Student(Stud* ST, list l);



#endif /* Model_h */