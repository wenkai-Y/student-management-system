/*********************************/
/*************系统界面************/
/*********************************/
#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Selection_functions.h"
#include "Passwords_Management.h"
#include "Files_Processing.h"
#include "_StuIno_.h"
#include "Data_Analysis .h"

void AdmInterLogon();
int AdmInter();
void TeaInterLogon();
void TeaInter();
int In_School_Grades(struct Student*, int, int);
int bulu(int[], int);
int TeaAddStus();
void Teaprint();
int Tea_fixed();
int dele();
int dele_stu(int);
void findfind();
void SteInter();
void stu_log(string&, char[20], string&, string&);
int StuLogon(string&);
void ShowStuMage(string);
char Students_Ranking(struct Student*, int);
void StuChaPassInter();
void Display_teacher_account_information();
void Display_student_account_information(int);
void Overall_Performance_Analysis(struct Student*, int);
void Analysis_of_all_subjects(struct Student*, int);
void xianshifenshuduan_1(int[3][4]);
void zidingyi(double[2]);
void lext(int renshu[3], double*);
void Exit();
inline void Cls();

using namespace std;
/*****主页界面*****/
void StarInt()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎来到学生成绩管理系统<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t  *1.教师端登录               *");
	puts("\t\t\t\t  *\t\t  *2.学生端登录               *");
	puts("\t\t\t\t  *\t\t  *3.管理员登录               *");
	puts("\t\t\t\t  *\t\t  *4.退出该系统               *");
	puts("\t\t\t\t  *********************************************");
	cout << endl << "\t\t\t\t  >>>请选择您需要的服务：";
	switch (StarChoice())
	{
		case 4:
			Exit();
			break;
		case 3:
		{
			AdmInterLogon();
			a3:
			switch (AdmInter())
			{
				case 1:
				{
					Display_teacher_account_information();
					//cout << "\t\t\t\t\t ***将退出管理员系统" << endl;
					cout << "\t\t\t\t\t ";
					system("pause");
					//StarInt();
					goto a3;
				}
					break;
				case 2:
				{
					int people = showpeoples();
					if (people)
					{
						Display_student_account_information(people);
						//cout << "\t\t\t\t\t ***将退出管理员系统" << endl;
					}
					else
					{
						Cls();
						puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
						puts("\t\t\t      >>>暂无学生信息，请您录入学生信息或告知学生进行注册<<<");
						puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
					}
					cout << "\t\t\t\t\t ";
					system("pause");
					goto a3;
					//StarInt();
				}
				break;
				case 3:
					StarInt();
				break;
			}
		}
			break;
		case 2:
			SteInter();
			break;
		case 1:
			TeaInterLogon();
			break;
	}
	
}

/******管理员登录界面*****/
void AdmInterLogon()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>欢迎来到管理员登录界面<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t\t ***用户名：    Administrator\n");
	cout << "\t\t\t\t\t ***请输入密码：";
	string realPass;
	char pass[20];
	LLogon(pass, 20);
	Get_Ador_pass(realPass);
	int temp = 0;
	if (strcmp(realPass.c_str(), pass))
	{
		do
		{
			cout << "\n\t\t\t\t\t >>>您输入的密码错误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t ***请输入密码：";
			LLogon(pass, 20);
			if (!strcmp(realPass.c_str(), pass))
				break;
			++temp;
			if (temp == 2)
			{
				cout << "\n\t\t\t\t\t***您输入的密码错误次数过多，将强制退出系统！！！" << endl;
				cout << "\t\t\t\t\t ";
				system("pause");
				Exit();
				exit(0);
			}
		} while (true);
	}
	cout << "\n\t\t\t\t\t &&&密码正确！！！" << endl;
	cout << "\t\t\t\t\t ";
	system("pause");
}

/*****管理员界面*****/
int AdmInter()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>欢迎来到管理员界面<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t*1.查看教师账号信息           *");
	puts("\t\t\t\t  *\t\t*2.查看学生账号信息           *");
	puts("\t\t\t\t  *\t\t*3.返回上一级                 *");
	puts("\t\t\t\t  *********************************************");
	cout << endl << "\t\t\t\t  >>>请选择您需要的服务：";
	int next;
	string next_;
	stringstream ints;
	cin >> next_;
	if (next_ != "1" && next_ != "2" && next_ != "3")
	{
		do
		{
			cout << "\t\t\t\t  ***您输入的格式有误，请您重新输入！！！" << endl;
			cout << endl << "\t\t\t\t  >>>请选择您需要的服务：";
			cin >> next_;
			if (next_ == "1" || next_ == "2" || next_ == "3")
				break;
		} while (true);
	}
	ints << next_;
	ints >> next;
	return next;
}

/*****显示教师账号信息*****/
void Display_teacher_account_information()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入显示教师账号信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	string password;
	Tea_Pass(password);
	puts("\t\t\t\t    ******************************************");
	puts("\t\t\t\t    *\t\t*教师账号:  2019-2023        *");
	cout << "\t\t\t\t    *\t\t*教师密码:  ";
	cout << setiosflags(ios_base::left) << setw(17) << password << "*" << endl;
	puts("\t\t\t\t    ******************************************");
}

/*****显示学生账号信息*****/
void Display_student_account_information(int people)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入显示学生账号信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	struct Student* stu = new struct Student[people];
	GEt_Stu_s(stu, people);
	puts("\t\t\t\t    ******************************************");
	for (int i = 0; i < people; ++i)
	{
		cout << "\t\t\t\t    *\t\t*学生学号:  ";
		cout << setiosflags(ios_base::left) << setw(17) << stu[i].number << "*" << endl;
		cout << "\t\t\t\t    *\t\t*学生姓名:  ";
		cout << setiosflags(ios_base::left) << setw(17) << stu[i].name << "*" << endl;
		cout << "\t\t\t\t    *\t\t*学生密码:  ";
		cout << setiosflags(ios_base::left) << setw(17) << stu[i].password << "*" << endl;
		puts("\t\t\t\t    ******************************************");
	}
	delete[]stu;
	stu = NULL;
}
/*****教师登录界面*****/
void TeaInterLogon()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎进入教师系统<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t\t ***用户名：    2019-2023\n");
	cout << "\t\t\t\t\t ***请输入密码：";
	if (TeaLogon())
		TeaInter();
	else
	{
		cout << "\n\t\t\t\t\t ";
		system("pause");
		Exit();
	}
}

/******教师界面*****/
void TeaInter()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎进入教师系统<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t  *1.录入学生信息             *");   //2019-12-11
	puts("\t\t\t\t  *\t\t  *2.录入学生成绩             *");
	puts("\t\t\t\t  *\t\t  *3.查找学生信息             *");   //2019-12-16
	puts("\t\t\t\t  *\t\t  *4.打印学生信息             *");   //2019-12-14
	puts("\t\t\t\t  *\t\t  *5.修改学生信息             *");   //2019-12-14
	puts("\t\t\t\t  *\t\t  *6.分析学生信息             *");
	puts("\t\t\t\t  *\t\t  *7.修改教师密码             *");   //2019-12-11
	puts("\t\t\t\t  *\t\t  *8.退出并返回上一级         *");   //已完成
	puts("\t\t\t\t  *********************************************");
	cout << endl << "\t\t\t\t  >>>请选择您需要的服务：";
	switch (TeaInerChoice())
	{
		case 1:
		{
			TeachersKeepStudentInformation(TeaAddStus());
			cout << "\t\t\t\t\t ";
			system("pause");
			TeaInter();
		}
		break;
		case 2:
		{
			a9:
			int peoples = showpeoples();
			struct Student* stu = new struct Student[peoples];
			int people = In_School_Grades(stu, peoples, 0);
			//cout << people << endl;
			if (people)
			{
				cout << "\t\t\t\t\t ***您共有" << people << "个学生成绩空缺， 请及时录入！！！\n" << endl;
				int* ptr_peo = new int[people];
				int temp = 0;
				for (int f = 0; f < peoples; ++f)
				{
					if (stu[f].ave == -1)
						ptr_peo[temp++] = f;
					if (temp == people)
						break;
				}
				for (int i = 0; i < people; ++i)
				{
					if(i == 0)
					cout << "\t\t\t  *************************需录入的学生信息**********************" << endl;
					showone(stu, ptr_peo[i], 1);
				}
				int peo_peo = bulu(ptr_peo, people);
				if (peo_peo == 0)
				{
					delete[]ptr_peo;
					delete[]stu;
					ptr_peo = NULL;
					stu = NULL;
					TeaInter();
				}
				else
				{
					xiugaibulu(stu, peoples, peo_peo - 1);
					delete[]ptr_peo;
					delete[]stu;
					ptr_peo = NULL;
					stu = NULL;
					goto a9;
				}
				
			}
			else
			{
				delete[]stu;
				stu = NULL;
				puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
				puts("\t\t\t      >>>>>>>暂无缺少成绩的学生，或请告知学生进行注册<<<<<<<");
				puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
				cout << "\t\t\t\t\t ";
				system("pause");
				TeaInter();
			}
		}
		break;
		case 3:
		{
			a2:
			findfind();
			int people_3 = showpeoples();
			if (people_3)
			{
				switch (find_stus())
				{
					case 1:
					{
						string names = name();
						int next = find(names, 0, names);
						if (next == 0)
						{
							cout << "\t\t\t\t\t ";
							system("pause");
							goto a2;
						}
						else
						{
							goto a2;
						}
					}
					break;
					case 2:
					{
						string numbers = number();
						int next = find(numbers, 1, numbers);
						if (next == 0)
						{
							cout << "\t\t\t\t\t ";
							system("pause");
							goto a2;
						}
						else
						{
							goto a2;
						}
					}
					break;
					case 3:
						TeaInter();
						break;
				}
			}
			else
			{
				puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
				puts("\t\t\t      >>>暂无学生信息，请您录入学生信息或告知学生进行注册<<<");
				puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
				cout << "\t\t\t\t\t ";
				system("pause");
				TeaInter();
			}
		}
		break;
		case 4:
		{
			Teaprint();
			Print();
			cout << "\t\t\t\t\t ";
			system("pause");
			TeaInter();
		}
		break;
		case 5:
		{
			int people = showpeoples();
			if (people)
			{
				int temp = Tea_fixed();
				if (temp == 1)
				{
					fiexd();
					cout << "\t\t\t\t\t ";
					system("pause");
					Cls();
					Print();
					cout << "\t\t\t\t\t ";
					system("pause");
					TeaInter();
				}
				else
					if (temp == 2)
					{
						int retu = dele();
						if (retu == 1)
						{
							cout << "\t\t\t\t\t ***为确保学生信息安全，请输入您的教师密码(仅一次机会)：";
							string aswer;
							char mima[20];
							LLogon(mima, 20);
							Tea_Pass(aswer);
							if (!strcmp(mima, aswer.c_str()))
							{
								delel();
								cout << "\n\t\t\t\t\t ***信息已经全部删除！！！\n";
								cout << "\t\t\t\t\t ";
								system("pause");
								TeaInter();
							}
							else
							{
								cout << "\n\t\t\t\t\t !!!您输入的密码错误，无权限删除全部学生信息\n";
								cout << "\t\t\t\t ";
								system("pause");
								TeaInter();
							}
						}
						else
						{
							//先显示学生信息！！！
							Print();
							int dele_peo = dele_stu(people);
							cout << "\n\t\t\t\t\t ***为确保学生信息安全，请输入您的教师密码(仅一次机会)：";
							string aswer;
							char mima[20];
							LLogon(mima, 20);
							Tea_Pass(aswer);
							if (!strcmp(mima, aswer.c_str()))
							{
								del_d_stu(dele_peo, people);
								//int people = showpeoples();
								Cls();
								Print();
								cout << "\t\t\t\t\t >>>已经修改完信息并保存！！！" << endl;
								cout << "\t\t\t\t\t ";
								system("pause");
								TeaInter();
							}
							else
							{
								cout << "\n\t\t\t\t\t !!!您输入的密码错误，无权限删除该学生信息\n";
								cout << "\t\t\t\t\t ";
								system("pause");
								TeaInter();
							}
						}
					}
					else
						TeaInter();
			}
			else
			{
				Cls();
				puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
				puts("\t\t\t      >>>暂无学生信息，请您录入学生信息或告知学生进行注册<<<");
				puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
				cout << "\t\t\t\t\t ";
				system("pause");
				TeaInter();
			}
		}
		break;
		case 6:
		{
			a11:
			int peoples = showpeoples();
			struct Student* stu = new struct Student[peoples];
			int people = In_School_Grades(stu, peoples, 1);   //信息未补漏的学生数量
			if (!people && peoples != 0)
			{
				switch (AnalYourChoiOfGrades())
				{
					case 1:
					{
						char next = Students_Ranking(stu, peoples);
						if (next == 'Y' || next == 'y')
							save(stu, peoples);
						delete[]stu;
						stu = NULL;
						cout << "\t\t\t\t\t ";
						system("pause");
						goto a11;
					}
					break;
					case 2:
					{
						//总体成绩的分析
						Overall_Performance_Analysis(stu, peoples);
						delete[]stu;
						stu = NULL;
						cout << "\t\t\t\t\t ";
						system("pause");
						goto a11;
					}
					break;
					case 3:
					{
						Analysis_of_all_subjects(stu, peoples);
						delete[]stu;
						stu = NULL;
						cout << "\t\t\t\t\t ";
						system("pause");
						goto a11;
					}
					break;
					case 4:
					{
						a12:
						switch (stuFEN())
						{
							case 1:
							{
								int fenshu[3][4] = { 0 };
								fenshuduan_1(stu, peoples, fenshu);
								xianshifenshuduan_1(fenshu);
								cout << "\t\t\t\t\t ";
								system("pause");
								goto a12;
							}
							break;
							case 2:
							{
								double fenshuxian[2] = { 0 };
								int renshu[3] = { 0 };
								zidingyi(fenshuxian);
								zidingyifenshu(stu, peoples, fenshuxian, renshu);
								lext(renshu, fenshuxian);
								cout << "\t\t\t\t\t ";
								system("pause");
								goto a12;
							}
							break;
							case 3:
							{
								delete[]stu;
								stu = NULL;
								goto a11;
							}
							break;
						}
					}
					break;
					case 5:
					{
						delete[]stu;
						stu = NULL;
						TeaInter();
					}
					break;
				}
			}
			else
			{
				if (peoples == 0)
				{
					Cls();
					puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					puts("\t\t\t      >>>暂无学生信息，请您录入学生信息或告知学生进行注册<<<");
					puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
					delete[]stu;
					stu = NULL;
					cout << "\t\t\t\t\t ";
					system("pause");
					TeaInter();
				}
				else
				{
					Cls();
					puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					puts("\t\t\t      >>有缺少成绩的学生，请先进行录入成绩，再进行成绩分析<<");
					puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
					delete[]stu;
					stu = NULL;
					cout << "\t\t\t\t\t ";
					system("pause");
					TeaInter();
				}
			}
		}
		break;
		case 7:
		{
			Cls();
			TeaChangePass();
			Cls();
			TeaInterLogon();
		}
		break;
		case 8:
		{
			Cls();
			StarInt();
		}
		break;
	}
}

/******教师添加学生信息界面*****/
int TeaAddStus()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师添加学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	int next;   //定义要输入的人数
	stringstream ints;
	string input;
	cout << "\t\t\t\t\t *请输入您要添加学生的人数：";
	cin >> input;
	ints << input;
	ints >> next;
	if (next <= 0)
	{
		do
		{
			stringstream temp;
			cout << "\t\t\t\t\t *您输入的人数不符合实际，请重新输入！\n" << endl;
			cout << "\t\t\t\t\t *请输入您要添加学生的人数：";
			cin >> input;
			temp << input;
			temp >> next;
			//cout << next << endl;
			if (next > 0)
				break;
		} while (true);
	}
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师添加学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	return next;
}

/*****教师录入学生成绩界面*****/
int In_School_Grades(struct Student* ptr, int people, int cha)
{
	int next = 0;
	if (cha == 0)
	{
		Cls();
		puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		puts("\t\t\t\t\t >>欢迎进入教师录入学生成绩界面<< ");
		puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	}
	Get_Mage(ptr);
	for (int i = 0; i < people; ++i)
	{
		if (ptr[i].ave == -1)
		{
			++next;
		}
	}
	return next;//未录入的人数
}
/*****补录成绩*****/
int bulu(int shuzu[], int peo)
{
	int first, flage = 0;
	cout << "\t\t\t\t\t 请输入您要补录的学生的序号(0为返回上一级)：";
	cin >> first;
	if (first == 0)
		return first;
	for (int i = 0; i < peo; ++i)
	{
		if (shuzu[i] == first - 1)
		{
			++flage;
			break;
		}
	}
	if(flage == 0 || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t ***您输入的格式有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t 请输入您要补录的学生的序号(0为返回上一级)：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> first;
			if (first == 0 && cin)
				break;
			for (int i = 0; i < peo; ++i)
			{
				if (shuzu[i] == first - 1)
				{
					++flage;
					break;
				}
			}
			if (flage != 0)
				break;
		} while (true);
	}
	return first;
}

/*****教师打印学生信息界面*****/
void Teaprint()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师打印学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

/*****教师修改学生信息界面*****/
int Tea_fixed()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师修改学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t\t\t >>>1.修改信息\n";
	cout << "\t\t\t\t\t >>>2.删除信息\n";
	cout << "\t\t\t\t\t >>>3.返回上一级\n";
	cout << "\t\t\t\t\t *请输入您要进行的操作：";
	int i;
	string next;
	cin >> next;
	stringstream ints;
	if (next != "1" && next != "2" && next != "3")
	{
		do
		{
			cout << "\t\t\t\t\t >>>您输入的数据有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t *请输入您要进行的操作：";
			cin >> next;
			if (next == "1" || next == "2" || next == "3")
				break;
		} while (true);
	}
	ints << next;
	ints >> i;
	return i;
}

/******教师删除学生信息界面*****/
int dele()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师删除学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t\t\t >>>1.删除全部学生信息" << endl;
	cout << "\t\t\t\t\t >>>2.删除单个学生信息" << endl;
	cout << "\t\t\t\t\t *请输入您的选择：";
	int choive;
	cin >> choive;
	if (choive != 1 && choive != 2 || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t >>>您输入的数据有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t *请输入您要进行的操作：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> choive;
			if (choive == 1 || choive == 2 && cin)
				break;
		} while (true);
	}
	return choive;
}

/******教师删除单个学生信息界面*****/
int dele_stu(int people)
{
	cout << "\t\t\t\t\t >>>请输入您要删除学生的序号：";
	int index;
	cin >> index;
	if (index < 1 || index > people || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t ***您输入的数据有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t >>>请输入您要删除学生的序号：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> index;
			if (index >= 1 && index <= people && cin)
				break;
		} while (true);
	}
	return index;
}

/*****学生成绩排名界面*****/
char Students_Ranking(struct Student* ptr, int people)
{
	char next;
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入学生成绩排名界面<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	stu_ranking(ptr, people);
	cout << "\t\t\t\t  $$$请问是否保存到副本(无法恢复之前排序)！！！?(Y/N)：";
	cin >> next;
	if (next != 'Y' && next != 'y' && next != 'N' && next != 'n')
	{
		do
		{
			cout << "\t\t\t\t  ***您输入的格式有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t  $$$请问是否保存到副本(无法恢复之前排序)！！！?(Y/N)：";
			cin >> next;
			if (next == 'Y' || next == 'y' || next == 'N' || next == 'n')
				break;
		} while (true);
	}
	return next;
}

/*****教师查找学生界面*****/
void findfind()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入查找学生信息系统<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

/*****学生界面*****/
void SteInter()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎进入学生系统<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t  *1.学生注册                 *");
	puts("\t\t\t\t  *\t\t  *2.学生登录                 *");
	puts("\t\t\t\t  *\t\t  *3.学生账号密码修改         *");
	puts("\t\t\t\t  *\t\t  *4.返回上一级               *");
	puts("\t\t\t\t  *********************************************");
	cout << endl << "\t\t\t\t  >>>请选择您需要的服务：";
	switch (StuInerChoice())
	{
		case 1:
		{
			string username, passwords, gender, number;
			char password[20];
			stu_log(username, password, number, gender);
			passwords = password;
			Stu_Reg(username, password, number, gender);
			cout << "\n\t\t\t\t\t ###您的信息已经注册完成！！！" << endl;
			cout << "\t\t\t\t\t ";
			system("pause");
			SteInter();
		}
			break;
		case 2:
		{
			string number;
			if (StuLogon(number) == 0)
			{
				cout << "\n\n\t\t\t\t\t &&&您的账户信息不正确，无法登录！！！" << endl;
				cout << "\t\t\t\t\t ";
				system("pause");
				SteInter();
			}
			else
			{
				cout << "\n\n\t\t\t\t\t &&&登录成功！！！" << endl;
				cout << "\t\t\t\t\t ";
				system("pause");
				ShowStuMage(number);
				SteInter();
			}
		}
			break;
		case 3:
		{
			StuChaPassInter();
		}
			break;
		case 4:
		{
			Cls();
			StarInt();
		}
			break;
	}
}

/*****学生注册界面*****/
void stu_log(string& username, char password[20], string& number, string& gender)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入学生注册信息界面<<<<");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t\t\t ***请输入您学号：";
	cin >> number;
	if (The_user_to_repeat(number))
	{
		do
		{
			cout << "\t\t\t\t\t &&&您输入的学号已存在，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t ***请输入您学号：";
			cin >> number;
			if (!The_user_to_repeat(number))
				break;
		} while (true);
	}
	cout << "\t\t\t\t\t ***请输入您的用户名(自己的名字)：";
	cin >> username;
	cout << "\t\t\t\t\t ***请输入您的性别(男&女)：";
	cin >> gender;
	if ((gender != "男") && (gender != "女"))
	{
		do
		{
			cout << "\t\t\t\t\t ***您输入的格式有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t ***请输入您的性别(男&女)：";
			cin >> gender;
				//cout << stu[i - 1].gender << endl;
			if (gender == "男" || gender == "女")
				break;
		} while (true);
	}
	cout << "\t\t\t\t\t ***请输入您的密码：";
	LLogon(password, 20);
	char again[20];
	cout << "\n\t\t\t\t\t ***请您确认您的密码：";
	LLogon(again, 20);
	if (strcmp(again, password))
	{
		int temp = 0;
		do
		{
			cout << "\n\t\t\t\t\t >>>您输入的两次密码不正确，请您重新输入!!!" << endl;
			cout << "\n\t\t\t\t\t ***请您确认您的密码：";
			LLogon(again, 20);
			if (!strcmp(again, password))
				break;
			++temp;
			if (temp == 2)
			{
				cout << "\n\n\t\t\t\t\t $$$注册密码时密码不一致次数过多，将强制退出系统！！！" << endl;
				cout << "\t\t\t\t\t ";
				system("pause");
				Exit();
				exit(0);
			}
		} while (true);
	}
}

/*****学生登录界面*****/
int StuLogon(string& numbers)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>欢迎进入学生登录界面<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	string number, username, password;
	char passwords[20];
	cout << "\t\t\t\t\t ***请输入您的学号：";
	cin >> number;
	cout << "\t\t\t\t\t ***请输入您的用户名：";
	cin >> username;
	cout << "\t\t\t\t\t ***请输入您的密码(初始密码为您的学号)：";
	LLogon(passwords, 20);
	password = passwords;
	numbers = number;
	return Stu_Pass(number, username, password);//会返回return 值
}

/*****学生登陆成功后显示界面*****/
void ShowStuMage(string number)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎进入学生主页<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	cout << "\t\t\t  **************************您的学生信息*************************" << endl;
	int people = showpeoples();
	struct Student* stu = new struct Student[people];
	Get_Mage(stu);
	int i = 0;
	for (; i < people; ++i)
	{
		if (stu[i].number == number)
			break;
	}
	showone(stu, i, 1);
	int unpeople = In_School_Grades(stu, people, 1);
	if (unpeople != 0)
	{
		cout << "\n\t\t\t   ***** 因有部分同学信息未录入完成，故无您的成绩排名信息。*****" << endl;
	}
	else
	{
		int all      = allrank(stu, people, number);
		int math     = mathrank(stu, people, number);
		int english  = englishrank(stu, people, number);
		int computer = computerrank(stu, people, number);
		cout << "\t\t\t\t\t       >>>>>您的成绩分析<<<<" << endl;
		cout << "\t\t\t\t\t       *********************" << endl;
		cout << "\t\t\t\t\t       *总分排名:     " << setw(2) << all <<
			"/" << setw(2) << people << "*" << endl;
		cout << "\t\t\t\t\t       *高数排名:     " << setw(2) << math <<
			"/" << setw(2) << people << "*" << endl;
		cout << "\t\t\t\t\t       *英语排名:     " << setw(2) << english <<
			"/" << setw(2) << people << "*" << endl;
		cout << "\t\t\t\t\t       *电脑排名:     " << setw(2) << computer <<
			"/" << setw(2) << people << "*" << endl;
		cout << "\t\t\t\t\t       *********************" << endl;
	}
	delete[]stu;
	stu = NULL;
	cout << "\t\t\t\t\t ";
	system("pause");

}

/*****学生修改密码界面*****/
void StuChaPassInter()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入学生修改密码界面<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t\t\t &&&接下来将验证您的真实身份！！！" << endl;
	cout << "\t\t\t\t\t ";
	system("pause");
	string number;
	if (StuLogon(number) == 0)
	{
		cout << "\n\n\t\t\t\t\t &&&您的账户信息不正确，无法登录！！！" << endl;
		cout << "\t\t\t\t\t ";
		system("pause");
		SteInter();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t &&&登录成功！！！" << endl;
		cout << "\t\t\t\t\t ";
		system("pause");
		Cls();
		puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		puts("\t\t\t\t\t >>>>欢迎进入学生修改密码界面<<<< ");
		puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		cout << "\t\t\t\t\t >>>用户账号：" << number << endl;
		Change_stu_pass(number);
		SteInter();
	}
	
}

/*****分析总体成绩界面*****/
void Overall_Performance_Analysis(struct Student* ptr, int people)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入分析总体成绩界面<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	double ave = Class_Average(ptr, people);
	puts("\t\t\t\t  *********************************************");
	cout << "\t\t\t\t  *\t\t*全班共有： ";
	cout << setiosflags(ios_base::left) << setw(2) << people << setw(16) <<
		"人" << "*" << endl;
	cout << "\t\t\t\t  *\t\t*总分为： ";
	cout << setiosflags(ios_base::left) << fixed << setprecision(1) << setw(6) << ave * people * 3 <<
		setw(14) << "分" << "*" << endl;
	cout << "\t\t\t\t  *\t\t*总平均分为： ";
	cout << setiosflags(ios_base::left) << fixed << setprecision(1) << ave << setw(12) <<
		"分" << "*" << endl;
	cout << "\t\t\t\t  *\t\t*总得分率为： ";
	cout << setiosflags(ios_base::left) << fixed << setprecision(1) << ave << setw(12) <<
		" %" << "*" << endl;
	puts("\t\t\t\t  *********************************************");
}

/*****各科成绩分析*****/
void Analysis_of_all_subjects(struct Student* ptr, int people)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>欢迎进入分析各科成绩界面<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	if (people != 1)
	{
		double grade[3][3] = { 0 };
		Subject_Average(ptr, people, grade);
		find_max_min(ptr, people, grade);
		puts("\t\t\t\t  *********************************************");
		cout << "\t\t\t\t  *  科目      *最高分     *最低分     *平均分*" << endl;
		puts("\t\t\t\t  ---------------------------------------------");
		cout << setiosflags(ios_base::left) << fixed << setprecision(1) << "\t\t\t\t  " <<
			"*  高数       " << setw(12) << grade[0][0] << setw(13) <<
			grade[0][1] << setw(5) << grade[0][2] << "*" << endl;
		cout << setiosflags(ios_base::left) << fixed << setprecision(1) << "\t\t\t\t  " <<
			"*  英语       " << setw(12) << grade[1][0] << setw(13) <<
			grade[1][1] << setw(5) << grade[1][2] << "*" << endl;
		cout << setiosflags(ios_base::left) << fixed << setprecision(1) << "\t\t\t\t  " <<
			"*  计算机     " << setw(12) << grade[2][0] << setw(13) <<
			grade[2][1] << setw(5) << grade[2][2] << "*" << endl;
		puts("\t\t\t\t  *********************************************");
	}
	else
	{
		puts("\t\t\t     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		puts("\t\t\t     仅有一个学生成绩，无法进行分析各科成绩,请先录入学生成绩。");
		puts("\t\t\t     <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	}
	

}

/*****显示分数段默认人数*****/
void xianshifenshuduan_1(int fenshu[3][4])
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>欢迎进入分析各科分数段界面<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t        *****************************************************************" << endl;
	cout << "\t\t\t*科目    优秀(100-85)   良好(85-60)   合格(60-45)   不合格(45-0)*" << endl;
	puts("\t\t        -----------------------------------------------------------------");
	cout << setiosflags(ios_base::left) << "\t\t\t*高数        " << setw(3) << fenshu[0][0] << setw(11) <<
		"人" << setw(3) << fenshu[0][1] << setw(11) << "人" << setw(3) << fenshu[0][2] << setw(12) <<
		"人" << setw(3) << fenshu[0][3] << setw(5) << "人" << "*" << endl;
	cout << setiosflags(ios_base::left) << "\t\t\t*英语        " << setw(3) << fenshu[1][0] << setw(11) <<
		"人" << setw(3) << fenshu[1][1] << setw(11) << "人" << setw(3) << fenshu[1][2] << setw(12) <<
		"人" << setw(3) << fenshu[1][3] << setw(5) << "人" << "*" << endl;
	cout << setiosflags(ios_base::left) << "\t\t\t*计算机      " << setw(3) << fenshu[2][0] << setw(11) <<
		"人" << setw(3) << fenshu[2][1] << setw(11) << "人" << setw(3) << fenshu[2][2] << setw(12) <<
		"人" << setw(3) << fenshu[2][3] << setw(5) << "人" << "*" << endl;
	cout << "\t\t        *****************************************************************" << endl;
}

/*****自定义分数段的显示*****/
void zidingyi(double ptr[2])
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎自定义分析各科分数段界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	a1:
	cout << "\t\t\t\t\t ***请输入较高的分数线：";
	cin >> ptr[0];
	if (ptr[0] < 0 || ptr[0] >100 || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t &&&你输入的格式有误，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t ***请输入较高的分数线：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> ptr[0];
			//cout << "\t\t\t\t\t ***请输入较低的分数线：";
			//cin >> ptr[1];
			if (ptr[0] >= 0 && ptr[0] <= 100 && cin)
				break;
		} while (true);
	}
	cout << "\t\t\t\t\t ***请输入较低的分数线：";
	cin >> ptr[1];
	if (ptr[1] < 0 || ptr[1] >100 || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t &&&你输入的格式有误，请重新输入！！！" << endl;
			//cout << "\n\t\t\t\t\t ***请输入较高的分数线：";
			//cin >> ptr[0];
			cout << "\t\t\t\t\t ***请输入较低的分数线：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> ptr[1];
			if (ptr[0] >= 0 && ptr[0] <= 100 && cin)
				break;
		} while (true);
	}
	if (ptr[0] <= ptr[1])
	{
		cout << "\t\t\t\t\t &&&你输入的格式有误，请重新输入！！！" << endl;
		goto a1;
	}
}

/*****显示自定义人数*****/
void lext(int renshu[3], double* ptr_)
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎自定义分析各科分数段界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t\t ********************************");
	cout << setiosflags(ios_base::left) << fixed << setprecision(1) << "\t\t\t\t\t *科目    在分数线内(" <<
		setw(3) << ptr_[0] << "-" << setw(3) << ptr_[1] << ") *" << endl;
	puts("\t\t\t\t\t --------------------------------");
	cout << setiosflags(ios_base::left) << "\t\t\t\t\t *高数           " << setw(2) << renshu[0] << setw(13) <<
		"人" << "*" << endl;
	cout << setiosflags(ios_base::left) << "\t\t\t\t\t *英语           " << setw(2) << renshu[1] << setw(13) <<
		"人" << "*" << endl;
	cout << setiosflags(ios_base::left) << "\t\t\t\t\t *计算机         " << setw(2) << renshu[2] << setw(13) <<
		"人" << "*" << endl;
	puts("\t\t\t\t\t ********************************");
}

/*****退出界面*****/
void Exit()
{
	Cls();
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎您的再次使用<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
}

/*****系统清屏*****/
inline void Cls()
{
	system("cls");
}
