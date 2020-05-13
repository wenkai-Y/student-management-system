/*********************************/
/**学生信息管理（结构体，链表）***/
/*********************************/
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Files_Processing.h"
//#include "Data_Analysis .h"

inline void TeaIfo_1(int);						//教师输入学生信息的界面
int SHOW_TEA_ADD_STU(struct Student*, int);     //显示老师输入的学生信息界面
void Chage_TEA_ADD_STU(struct Student*, int);   //改变教师输入的学生信息
void input(struct Student*, int, int, int);     //输入学生信息
int STU_Change_number();					    //改变学生信息的序号的返回
void show_xinxi(struct Student*, int);          //显示教师修改后的信息
void save_(struct Student*, int);
bool The_user_to_repeat_(string number);
void Get_Mage_(struct Student* ptr);
int showpeoples_();

using namespace std;

/*****学生信息的结构体*****/
struct Student
{
	string name, gender, number, password;
	double math, english, computers, ave;
	//struct Student* next;
};

/*****教师建立学生信息*****/
Student* TEA_APP_STU(int people)
{
	struct Student* stu = NULL;
	stu = new Student[people];   //创建动态学生结构体
	input(stu, people, 0, -1);
	cout << "\t\t\t\t\t ***全部学生信息已经输入完成！！！" << endl;
	cout << "\t\t\t\t\t ";
	system("pause");
	a1:
	int next = SHOW_TEA_ADD_STU(stu, people);
	if (next == 1)
		return stu;
	else
		if(next == 3)
		{
			delete[]stu;
			stu = NULL;
			return stu;
		}
		else
		{
			Chage_TEA_ADD_STU(stu, people);
			goto a1;
		}
	//SHOW_TEA_ADD_STU(stu, people);
	//cout << "\t\t\t\t\t ";
	//system("pause");
	//exit(0);
}

/******教师输入学生信息的界面*****/
inline void TeaIfo_1(int peo)
{
	cout << "\t\t\t\t\t     >>  输入学生" << peo << "的信息  <<" << endl;
}

/******显示老师输入的学生信息界面并返回下一步的操作*****/
int SHOW_TEA_ADD_STU(struct Student* ptr, int people_1)
{
	int i = 0;
	stringstream ints;
	string input;
	system("cls");
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t 欢迎进入教师添加学生信息显示界面 ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t  *************************添加的学生信息************************" << endl;
	show_xinxi(ptr, people_1);
	cout << "\t\t\t\t\t >>>请问您的进一步操作：" << endl;
	cout << "\t\t\t\t\t ***1.保存数据" << endl;
	cout << "\t\t\t\t\t ***2.修改数据" << endl;
	cout << "\t\t\t\t\t ***3.删除数据" << endl;
	cout << "\t\t\t\t\t >>>请输入您的操作：";
	cin >> input;
	if (input != "1" && input != "2" && input != "3")
	{
		do
		{
			cout << "\t\t\t\t\t <<<您输入的数据有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t >>>请输入您的操作：";
			cin >> input;
			if (input == "1" || input == "2" || input == "3")
				break;
		} while (true);
	}
	ints << input;
	ints >> i;
	return i;
}

/******修改教师输入学生的信息*****/
void Chage_TEA_ADD_STU(struct Student* ptr, int people)   //people 是总人数
{
	int change;   //需要修改的人的序号！
	cout << "\t\t\t\t\t ***请输入您要修改学生的序号：";
	cin >> change;
	if (change < 1 || change > people || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t  >>>您输入的序号有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t ***请输入您要修改学生的序号：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> change;
			if (change >= 1 && change <= people && cin)
				break;
		} while (true);
	}
	system("cls");
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师修改学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t  **************************添加的学生信息***********************" << endl;
	//show_xinxi(ptr, people);
	///修改！！！
	cout << "\t\t\t  *序号   学号        姓名    性别  高数   英语   计算机  平均分*" << endl;
	cout << setiosflags(ios_base::left) << "\t\t\t  *" << setw(7) << change <<
		setw(12) << ptr[change - 1].number << setw(8) << ptr[change - 1].name << setw(6) <<
		ptr[change - 1].gender << fixed << setprecision(1) <<setw(7) << ptr[change - 1].math << setw(7) << ptr[change - 1].english <<
		setw(10) << ptr[change - 1].computers << ptr[change - 1].ave << "*\n";
	cout << "\t\t\t  ***************************************************************" << endl;
	input(ptr, 0, change, STU_Change_number());
	cout << "\t\t\t\t\t ";
	system("pause");
}

/******补录学生成绩*****/
//void;
/******输入学生信息的函数*****/
void input(struct Student* stu, int people, int one, int one_one)
{
	if (one == 0)
	{
		string numbers[50];
		for (int i = 1; i <= people; ++i)
		{
			TeaIfo_1(i);
			cout << "\t\t\t\t\t     >>  输入学生学号：";
			cin >> stu[i - 1].number;
			numbers[i - 1] = stu[i - 1].number;
			int flage = 0;
			for (int j = 0; j < i - 1; ++j)
			{
				if (numbers[j] == stu[i - 1].number)
				{
					++flage;
					break;
				}
			}
			if (The_user_to_repeat_(stu[i - 1].number) || flage)
			{
				do
				{
					cout << "\t\t\t\t\t     **  您输入的学号已存在！！！" << endl;
					cout << "\n\t\t\t\t\t     >>  输入学生学号：";
					cin >> stu[i - 1].number;
					numbers[i - 1] = stu[i - 1].number;
					flage = 0;
					for (int j = 0; j < i - 1; ++j)
					{
						if (numbers[j] == stu[i - 1].number)
						{
							++flage;
							break;
						}
					}
					if (!The_user_to_repeat_(stu[i - 1].number) && !flage)
						break;
				} while (true);
			}
			//cout << numbers[0] << endl;
			stu[i - 1].password = stu[i - 1].number;
			cout << "\t\t\t\t\t     >>  输入学生姓名：";
			cin >> stu[i - 1].name;
			cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
			cin >> stu[i - 1].gender;
			//cout << stu[i - 1].gender << endl;
			if ((stu[i - 1].gender != "男") && (stu[i - 1].gender != "女"))
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
					cin >> stu[i - 1].gender;
					//cout << stu[i - 1].gender << endl;
					if (stu[i - 1].gender == "男" || stu[i - 1].gender == "女")
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
			cin >> stu[i - 1].math;
			if (stu[i - 1].math < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
					cin >> stu[i - 1].math;
					if (stu[i - 1].math >= 0)
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
			cin >> stu[i - 1].english;
			if (stu[i - 1].english < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
					cin >> stu[i - 1].english;
					if (stu[i - 1].english >= 0)
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
			cin >> stu[i - 1].computers;
			if (stu[i - 1].computers < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
					cin >> stu[i - 1].computers;
					if (stu[i - 1].computers >= 0)
						break;
				} while (true);
			}
			stu[i - 1].ave = (stu[i - 1].math + stu[i - 1].english + stu[i - 1].computers) / 3.0;
			cout << "\t\t\t\t\t >>>>>>>>学生" << i << "信息输入完成<<<<<<<<" << endl << endl;
		}
	}
	else
		if (one != 0 && one_one == 7)
		{
			cout << "\n\t\t\t\t\t  >>  请重新输入学生" << one << "的信息  <<" << endl;
			TeaIfo_1(one);
			cout << "\t\t\t\t\t     >>  输入学生学号：";
			cin >> stu[one - 1].number;
			stu[one - 1].password = stu[one - 1].number;
			cout << "\t\t\t\t\t     >>  输入学生姓名：";
			cin >> stu[one - 1].name;
			cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
			cin >> stu[one - 1].gender;
			//cout << stu[i - 1].gender << endl;
			if ((stu[one - 1].gender != "男") && (stu[one - 1].gender != "女"))
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
					cin >> stu[one - 1].gender;
					//cout << stu[i - 1].gender << endl;
					if (stu[one - 1].gender == "男" || stu[one - 1].gender == "女")
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
			cin >> stu[one - 1].math;
			if (stu[one - 1].math < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
					cin >> stu[one - 1].math;
					if (stu[one - 1].math >= 0)
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
			cin >> stu[one - 1].english;
			if (stu[one - 1].english < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
					cin >> stu[one - 1].english;
					if (stu[one - 1].english >= 0)
						break;
				} while (true);
			}
			cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
			cin >> stu[one - 1].computers;
			if (stu[one - 1].computers < 0)
			{
				do
				{
					cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
					cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
					cin >> stu[one - 1].computers;
					if (stu[one - 1].computers >= 0)
						break;
				} while (true);
			}
			stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
			cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息更改完成<<<<<<<<" << endl << endl;
		}
		else
		{
			//string xuanze[6] = { "学号","姓名","性别","高数","英语","计算机" };
			cout << "\n\t\t\t\t\t  >>  请重新输入学生" << one << "的信息  <<" << endl;
			TeaIfo_1(one);
			switch (one_one)
			{
				case 1:
				{
					cout << "\t\t\t\t\t     >>  输入学生学号：";
					cin >> stu[one - 1].number;
					stu[one - 1].password = stu[one - 1].number;
					//stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
				}
				break;
				case 2:
				{
					cout << "\t\t\t\t\t     >>  输入学生姓名：";
					cin >> stu[one - 1].name;
					//stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
					//cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息输入完成<<<<<<<<" << endl << endl;
				}
				break;
				case 3:
				{
					cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
					cin >> stu[one - 1].gender;
					//cout << stu[i - 1].gender << endl;
					if ((stu[one - 1].gender != "男") && (stu[one - 1].gender != "女"))
					{
						do
						{
							cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
							cout << "\t\t\t\t\t     >>  输入学生性别(男&女)：";
							cin >> stu[one - 1].gender;
							//cout << stu[i - 1].gender << endl;
							if (stu[one - 1].gender == "男" || stu[one - 1].gender == "女")
								break;
						} while (true);
					}
					//stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
					//cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息输入完成<<<<<<<<" << endl << endl;
				}
				break;
				case 4:
				{
					cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
					cin >> stu[one - 1].math;
					if (stu[one - 1].math < 0)
					{
						do
						{
							cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
							cout << "\t\t\t\t\t     >>  输入学生的高数成绩：";
							cin >> stu[one - 1].math;
							if (stu[one - 1].math >= 0)
								break;
						} while (true);
					}
					stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
					//cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息输入完成<<<<<<<<" << endl << endl;
				}
				break;
				case 5:
				{
					cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
					cin >> stu[one - 1].english;
					if (stu[one - 1].english < 0)
					{
						do
						{
							cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
							cout << "\t\t\t\t\t     >>  输入学生的英语成绩：";
							cin >> stu[one - 1].english;
							if (stu[one - 1].english >= 0)
								break;
						} while (true);
					}
					stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
					//cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息输入完成<<<<<<<<" << endl << endl;
				}
				break;
				case 6:
				{
					cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
					cin >> stu[one - 1].computers;
					if (stu[one - 1].computers < 0)
					{
						do
						{
							cout << "\t\t\t\t\t     **您输入的格式有误，请重新输入！！！" << endl;
							cout << "\t\t\t\t\t     >>  输入学生的电脑成绩：";
							cin >> stu[one - 1].computers;
							if (stu[one - 1].computers >= 0)
								break;
						} while (true);
					}
					stu[one - 1].ave = (stu[one - 1].math + stu[one - 1].english + stu[one - 1].computers) / 3.0;
					//cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息输入完成<<<<<<<<" << endl << endl;
				}
				break;
			}
			cout << "\t\t\t\t\t >>>>>>>>学生" << one << "信息更改完成<<<<<<<<" << endl << endl;
		}
}

/******改变学生信息的序号的返回*****/
int STU_Change_number()
{
	cout << "\t\t\t\t\t *1.修改学生学号" << endl;
	cout << "\t\t\t\t\t *2.修改学生姓名" << endl;
	cout << "\t\t\t\t\t *3.修改学生性别" << endl;
	cout << "\t\t\t\t\t *4.修改学生高数成绩" << endl;
	cout << "\t\t\t\t\t *5.修改学生英语成绩" << endl;
	cout << "\t\t\t\t\t *6.修改学生电脑成绩" << endl;
	cout << "\t\t\t\t\t *7.修改学生全部信息" << endl;
	cout << "\t\t\t\t\t >请输入您要进行操作的序号：";
	int indx;
	cin >> indx;
	if (indx != 1 && indx != 2 && indx != 3 && indx != 4 && indx != 5 && indx != 6 && indx != 7)
	{
		do
		{
			cout << "\t\t\t\t >>>您输入的序号错误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t >请输入您要进行操作的序号：";
			cin >> indx;
			if (indx == 1 || indx == 2 || indx == 3 || indx == 4 || indx == 5 || indx == 6 || indx == 7)
				break;
		} while (true);
	}
	return indx;
}

/*****仅显示信息*****/
void show_xinxi(struct Student* ptr, int all_people)
{
	cout << "\t\t\t  *序号   学号        姓名    性别  高数   英语   计算机  平均分*" << endl;
	for (int i = 1; i <= all_people; ++i)
	{
		if (ptr[i - 1].ave != -1)
		{
			cout << setiosflags(ios_base::left) << "\t\t\t  *" << setw(7) << i <<
				setw(12) << ptr[i - 1].number << setw(8) << ptr[i - 1].name << setw(6) <<
				ptr[i - 1].gender << setw(7) << fixed << setprecision(1) << ptr[i - 1].math <<
				setw(7) << ptr[i - 1].english << setw(9) << ptr[i - 1].computers << setw(5) << ptr[i - 1].ave <<
				"*\n";
		}
		else
		{
			cout << setiosflags(ios_base::left) << "\t\t\t  *" << setw(7) << i <<
				setw(12) << ptr[i - 1].number << setw(8) << ptr[i - 1].name << setw(6) <<
				ptr[i - 1].gender << setw(7) << fixed << setprecision(1) << "未登记" <<
				setw(7) << "未登记" << setw(8) << "未登记" << "未登记" <<
				"*\n";
		}
	}
	cout << "\t\t\t  ***************************************************************" << endl;
}

/*****仅显示查询的信息******/
void showone(struct Student* ptr, int one, int change)
{
	if (change == 0)
	{
		system("cls");
		puts("\t\t\t\t\t  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		puts("\t\t\t\t\t  >>>>欢迎进入查找学生信息系统<<<< ");
		puts("\t\t\t\t\t  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		cout << "\t\t\t  **************************查询的学生信息***********************" << endl;
	}
	cout << "\t\t\t  *序号   学号        姓名    性别  高数   英语   计算机  平均分*" << endl;
	if (ptr[one].ave == -1)
	{
		cout << setiosflags(ios_base::left) << "\t\t\t  *" << setw(7) << one + 1 <<
			setw(12) << ptr[one].number << setw(8) << ptr[one].name << setw(6) <<
			ptr[one].gender << setw(7) << fixed << setprecision(1) << "未登记" <<
			setw(7) << "未登记" << setw(8) << "未登记" << "未登记" <<
			"*\n";
	}
	else
	{
		cout << setiosflags(ios_base::left) << "\t\t\t  *" << setw(7) << one + 1 <<
			setw(12) << ptr[one].number << setw(8) << ptr[one].name << setw(6) <<
			ptr[one].gender << setw(7) << fixed << setprecision(1) << ptr[one].math <<
			setw(7) << ptr[one].english << setw(9) << ptr[one].computers << setw(5) << ptr[one].ave <<
			"*\n";
	}
	cout << "\t\t\t  ***************************************************************" << endl;
}

/*****学生成绩排序******/
void stu_ranking(struct Student* ptr, int people)
{
	struct Student temp;
	//冒泡排序
	for (int i = 0; i < people - 1; ++i)
	{
		int flage = 0;
		for (int j = 0; j < people - 1; ++j)
		{
			if (ptr[j].ave < ptr[j + 1].ave)
			{
				++flage;
				temp       = ptr[j];
				ptr[j]     = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
		if (flage == 0)
			break;
	}
	//显示函数
	cout << "\t\t\t  *************************排序后的学生成绩**********************" << endl;
	show_xinxi(ptr, people);
}

/*****单独修改补录的信息******/
void xiugaibulu(struct Student* ptr, int peoples, int one)
{
	system("cls");
	puts("\t\t\t\t\t  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t  >>>>欢迎进入补录学生信息系统<<<< ");
	puts("\t\t\t\t\t  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t  **************************补录的学生信息***********************" << endl;
	showone(ptr, one, 1);
	cout << "\t\t\t\t\t >>>请输入该学生的高数成绩：";
	cin >> ptr[one].math;
	cout << "\t\t\t\t\t >>>请输入该学生的英语成绩：";
	cin >> ptr[one].english;
	cout << "\t\t\t\t\t >>>请输入该学生的计算机成绩：";
	cin >> ptr[one].computers;
	ptr[one].ave = (ptr[one].math + ptr[one].english + ptr[one].computers) / 3.0;
	save_(ptr, peoples);
	cout << "\t\t\t\t\t &&&补录完成！！！" << endl;
	cout << "\t\t\t\t\t ";
	system("pause");
}

void save_(struct Student* ptr, int people)
{
	fstream fir;
	fir.open("Files\\学生信息（副本）.txt", ios::in | ios::trunc | ios::out);
	if (fir.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int i = 1; i <= people; ++i)
	{
		fir << ptr[i - 1].number << " ";
		fir << ptr[i - 1].name << " ";
		fir << ptr[i - 1].gender << " ";
		fir << ptr[i - 1].math << " ";
		fir << ptr[i - 1].english << " ";
		fir << ptr[i - 1].computers << " ";
		fir << ptr[i - 1].ave << "\n";
	}
	//delete[]ptr;
	//ptr = NULL;
	fir.close();
	//cout << "\t\t\t\t\t >>>保存完成！！！" << endl;
}

bool The_user_to_repeat_(string number)
{
	int peoples = showpeoples_();
	struct Student* stu = new struct Student[peoples];
	Get_Mage_(stu);
	//cout << stu[0].number << endl;
	int flage = 0;
	for (int i = 0; i < peoples; ++i)
	{
		if (stu[i].number == number)
		{
			++flage;
			break;
		}
	}
	delete[]stu;
	stu = NULL;
	if (flage)
		return true;
	else
		return false;
}

void Get_Mage_(struct Student* ptr)
{
	int people = showpeoples_();
	fstream fil;
	fil.open("Files\\学生信息（副本）.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int b = 0; b < people; ++b)
	{
		fil >> ptr[b].number >> ptr[b].name >> ptr[b].gender >> ptr[b].math >> ptr[b].english
			>> ptr[b].computers >> ptr[b].ave;
	}
	fil.close();
}

int showpeoples_()
{
	fstream fil;
	fil.open("Files\\学生信息（副本）.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	int h = 0;
	string temp;
	while (!fil.eof())
	{
		fil >> temp;
		++h;
	}
	fil.close();
	int people = (h - 1) / 7;   //人数
	return people;
}
