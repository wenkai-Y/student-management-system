/*********************************/
/*************密码界面************/
/*********************************/
#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include "Files_Processing.h"
#pragma warning(disable : 4996)

void LLogon(char[], int);

using namespace std;

/*****教师登录*****/
bool TeaLogon()
{
	int time = 2, flage = 0;
	string aswer;
	char pass[20], aswer_c[20];
	Tea_Pass(aswer);               //从文件中获得准确密码
	strcpy(aswer_c, aswer.c_str());//将string转换为char[]
	while (time >= 0)
	{
		LLogon(pass, 20);
		if (!strcmp(pass, aswer_c))
		{
			++flage;
			break;
		}
		else
		{
			pass[0] = '\0';   //初始话密码字符串数组
			if (time != 0)
			{
				cout << "\n\t\t\t\t\t >>>密码错误，您还有" << time-- << "次机会\n\n";
				cout << "\t\t\t\t\t ***请输入密码：";
			}
			else
				break;
		}
	}
	if (flage)
	{
		cout << "\n\t\t\t\t\t >>>密码正确！！！\n";
		cout << "\n\t\t\t\t\t ";
		system("pause");
		return true;
	}
	else
	{
		cout << "\n\t\t\t\t\t >>>密码输入机会已用完，将退出系统。\n";
		return false;
	}
		
}

/*****教师修改密码*****/
void TeaChangePass()
{
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>>>>>>>欢迎进入教师系统<<<<<<<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	cout << "\t\t\t\t\t *请输入旧密码(仅一次机会)：";
	string aswer;
	Tea_Pass(aswer);   //获取教师密码
	char opass[20], npass[20], nnpass[20];
	LLogon(opass, 20);  //获得您输入的旧密码
	if (!strcmp(opass, aswer.c_str()))
	{
		cout << "\n\n\t\t\t\t\t *请输入新密码：";
		LLogon(npass,20);
		int flage = 0;
		do
		{
			cout << "\n\t\t\t\t\t *请确认新密码：";
			LLogon(nnpass, 20);
			if (!strcmp(npass, nnpass))
			{
				Tea_Cge_Pass(nnpass);
				cout << "\n\t\t\t\t\t >>>密码修改成功！！！\n";
				cout << "\t\t\t\t\t <<<将重新登录教师端系统！！！";
				cout << "\n\n\t\t\t\t\t ";
				system("pause");
				break;
			}
				
			++flage;
			if (flage == 3)
			{
				cout << "\n\t\t\t\t\t >>>输入新密码多次有误，强制退出系统！！！";
				cout << "\n\t\t\t\t\t ";
				system("pause");
				exit(0);
			}
			cout << "\n\t\t\t\t\t *确认新密码错误!" << endl;
		} while (true);

	}
	else
	{
		cout << "\n\t\t\t\t\t >>>输入旧密码错误，强制退出系统！！！" << endl << endl;
		cout << "\t\t\t\t\t ";
		system("pause");
		exit(0);
	}
}

/*****学生用户的注册*****/
void Stu_Reg(string username, string password, string number, string gender)
{
	struct Student* st = new struct Student;
	st[0].name = username;
	st[0].password = password;
	st[0].name = username;
	st[0].number = number;
	st[0].gender = gender;
	st[0].ave = -1;
	st[0].computers = -1;
	st[0].math = -1;
	st[0].english = -1;
	Stu_Stu(st, 0);
	st_save(st);
	delete st;
	st = NULL;
}

/*****学生账号密码修改*****/
void Change_stu_pass(string number)
{
	char password_1[20], password_2[20];
	string password;
	cout << "\t\t\t\t\t >>>请输入您的新密码：";
	LLogon(password_1, 20);
	cout << "\n\t\t\t\t\t >>>请您确认您的密码：";
	LLogon(password_2, 20);
	if (strcmp(password_1, password_2))
	{
		int temp = 0;
		do
		{
			cout << "\n\t\t\t\t\t ***您输入两次密码不一致，请重新输入！！！" << endl;
			cout << "\n\t\t\t\t\t >>>请您确认您的密码：";
			LLogon(password_2, 20);
			if (!strcmp(password_1, password_2))
			{
				password = password_1;
				break;
			}
			++temp;
			if (temp == 2)
			{
				cout << "\n\t\t\t\t\t &&&您输入错误次数过多，将强制退出系统！！！" << endl;
				cout << "\t\t\t\t\t ";
				system("pause");
				exit(0);
			}
		} while (true);
	}
	else
	{
		password = password_1;
	}
	Change_stupassword(number, password);
	cout << "\n\t\t\t\t\t ***密码修改成功！！！" << endl;
	cout << "\t\t\t\t\t ";
	system("pause");
}

/*****通用密码输入和返回*****/
void LLogon(char pass[], int n)
{
	int i = 0;
	char ch;
	while (i < n)
	{
		ch = _getch();		//ch = getch();
		if (ch == '\n' || ch == '\r')
		{
			pass[i] = '\0';
			break;
		}
		else
			if (ch == '\b')
			{
				if (i > 0)
				{
					printf("\b \b");
					pass[--i] = '\0';
				}
			}
			else
			{
				pass[i++] = ch;
				putchar('*');
			}
	}
}
