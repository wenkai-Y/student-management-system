/*****************************************/
/*************主函数的选择函数************/
/*****************************************/
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

/*****主页的选择*****/
int StarChoice()
{
	string input;
	stringstream ints;
	int next;
	cin >> input;
	do
	{
		if (input == "1" || input == "2" || input == "3" || input == "4")
			break;
		cout << "\n\t\t\t\t  >>>序号输入错误，请重新输入：";
		cin >> input;
	} while (true);
	ints << input;
	ints >> next;
	return next;
}

/*****教师端系统选择*****/
int TeaInerChoice()
{
	string input;
	stringstream ints;
	int next;
	cin >> input;
	do
	{
		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" ||
			input == "6" || input == "7" || input == "8")
			break;
		cout << "\n\t\t\t\t  >>>序号输入错误，请重新输入：";
		cin >> input;
	} while (true);
	ints << input;
	ints >> next;
	return next;
}

/*****教师查找界面*****/
int find_stus()
{
	puts("\t\t\t\t\t >>>1.以学生姓名查找");
	puts("\t\t\t\t\t >>>2.以学生学号查找");
	puts("\t\t\t\t\t >>>3.返回上一级");
	int index;
	cout << "\t\t\t\t\t *请输入您的进一步的选择：";
	cin >> index;
	if (index != 1 && index != 2 && index != 3 || !cin)
	{
		do
		{
			cout << "\t\t\t\t\t >>>您输入的格式有误，请重新输入！！！\n";
			cout << "\n\t\t\t\t\t *请输入您的进一步操作：";
			cin.clear();
			cin.sync();
			getchar();
			cin >> index;
			if (index == 1 || index == 2 || index == 3 && cin)
				break;
		} while (true);
	}
	return index;
}

/*****教师以姓名查找学生****/
string name()
{
	cout << "\t\t\t\t\t ###请输入您要查询学生的姓名：";
	string name;
	cin >> name;
	return name;
}

/*****教师以学号查找学生****/
string number()
{
	cout << "\t\t\t\t\t ###请输入您要查询学生的学号：";
	string number;
	cin >> number;
	return number;
}

/*****学生端系统的选择*****/
int StuInerChoice()
{
	int i;
	string next;
	stringstream ints;
	cin >> next;
	if (next != "1" && next != "2" && next != "3" && next != "4")
	{
		do
		{
			cout << "\t\t\t\t  >>>您输入的格式有误，请重新输入!!!" << endl;
			cout << endl << "\n\t\t\t\t  >>>请选择您需要的服务：";
			cin >> next;
			if (next == "1" || next == "2" || next == "3" || next == "4")
				break;
		} while (true);
	}
	ints << next;
	ints >> i;
	return i;
}

int AnalYourChoiOfGrades()
{
	system("cls");
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >>欢迎进入教师添加学生信息界面<< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t  *1.学生成绩排序             *");
	puts("\t\t\t\t  *\t\t  *2.分析总体成绩             *");
	puts("\t\t\t\t  *\t\t  *3.分析各科成绩             *");
	puts("\t\t\t\t  *\t\t  *4.分析分数分段             *");
	puts("\t\t\t\t  *\t\t  *5.返回上一级               *");
	puts("\t\t\t\t  *********************************************");
	cout << "\t\t\t\t  ###请输入您的选择：";
	int next;
	string next_;
	stringstream ints;
	cin >> next_;
	
	if (next_ != "1" && next_ != "2" && next_ != "3" && next_ != "4" && next_ != "5")
	{
		do
		{
			cout << "\t\t\t\t  ***您输入的序号有误，请您重新输入！！！" << endl;
			cout << "\n\t\t\t\t  ###请输入您的选择：";
			cin >> next_;
			if (next_ == "1" || next_ == "2" || next_ == "3" || next_ == "4" || next_ == "5")
				break;
		} while (true);
	}
	ints << next_;
	ints >> next;
	return next;
}

/*****学生成绩分数段的界面选择*****/
int stuFEN()
{
	system("cls");
	puts("\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	puts("\t\t\t\t\t >欢迎进入选择分析分数段方式界面< ");
	puts("\t\t\t\t\t <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	puts("\t\t\t\t  *********************************************");
	puts("\t\t\t\t  *\t\t  *1.系统默认分数段           *");
	puts("\t\t\t\t  *\t\t  *2.教师指定分数段           *");
	puts("\t\t\t\t  *\t\t  *3.返回上一级               *");
	puts("\t\t\t\t  *********************************************");
	cout << "\t\t\t\t  ###请输入您的选择：";
	int next;
	string next_;
	stringstream ints;
	cin >> next_;
	if (next_ != "1" && next_ != "2" && next_ != "3")
	{
		do
		{
			cout << "\t\t\t\t  ***您输入的序号有误，请您重新输入！！！" << endl;
			cout << "\n\t\t\t\t  ###请输入您的选择：";
			cin >> next_;
			if (next_ == "1" || next_ == "2" || next_ == "3")
				break;
		} while (true);
	}
	ints << next_;
	ints >> next;
	return next;
}
