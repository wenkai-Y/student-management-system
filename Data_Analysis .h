#pragma once
#include <iostream>
#include <stdio.h>
#include "_StuIno_.h"
#include "Files_Processing.h"
using namespace std;

/*****全班平均分并输出*****/
double Class_Average(struct Student* ptr, int people)
{
	double ave = 0;
	for (int i = 0; i < people; ++i)
	{
		ave += ptr[i].ave;
	}
	return (ave / people);
}

/*****各科平均分*****/
void Subject_Average(struct Student* ptr, int people, double grade[3][3])
{
	for (int i = 0; i < people; ++i)
	{
		grade[0][2] += ptr[i].math;
		grade[1][2] += ptr[i].english;
		grade[2][2] += ptr[i].computers;
	}
	grade[0][2] /= people;
	grade[1][2] /= people;
	grade[2][2] /= people;
}

/*****各科最大最小分数*****/
void find_max_min(struct Student* ptr, int people, double grade[3][3])
{
	for (int i = 1; i < people; ++i)
	{
		grade[0][0] = ptr[0].math;
		grade[0][1] = ptr[0].math;
		grade[1][0] = ptr[0].english;
		grade[1][1] = ptr[0].english;
		grade[2][0] = ptr[0].computers;
		grade[2][1] = ptr[0].computers;
		if (grade[0][0] < ptr[i].math)
			grade[0][0] = ptr[i].math;
		if (grade[0][1] > ptr[i].math)
			grade[0][1] = ptr[i].math;
		if (grade[1][0] < ptr[i].english)
			grade[1][0] = ptr[i].english;
		if (grade[1][1] > ptr[i].english)
			grade[1][1] = ptr[i].english;
		if (grade[2][0] < ptr[i].computers)
			grade[2][0] = ptr[i].computers;
		if (grade[2][1] > ptr[i].computers)
			grade[2][1] = ptr[i].computers;
	}
}

/*****默认分析分数段人数*****/
void fenshuduan_1(struct Student* ptr, int people, int shufen[3][4])
{
	for (int i = 0; i < people; ++i)
	{
		if (ptr[i].math >= 85)
			++shufen[0][0];
		else
			if (ptr[i].math >= 60)
				++shufen[0][1];
			else
				if (ptr[i].math >= 45)
					++shufen[0][2];
				else
					if (ptr[i].math < 45)
						++shufen[0][3];
		if (ptr[i].english >= 85)
			++shufen[1][0];
		else
			if (ptr[i].english >= 60)
				++shufen[1][1];
			else
				if (ptr[i].english >= 45)
					++shufen[1][2];
				else
					if (ptr[i].english < 45)
						++shufen[1][3];
		if (ptr[i].computers >= 85)
			++shufen[2][0];
		else
			if (ptr[i].computers >= 60)
				++shufen[2][1];
			else
				if (ptr[i].computers >= 45)
					++shufen[2][2];
				else
					if (ptr[i].computers < 45)
						++shufen[2][3];
	}
}

/*****自义定分析分数段人数*****/
void zidingyifenshu(struct Student* ptr, int people, double ptr_[2], int renshu[3])
{
	for (int i = 0; i < people; ++i)
	{
		if (ptr[i].math <= ptr_[0] && ptr[i].math >= ptr_[1])
			++renshu[0];
		if (ptr[i].english <= ptr_[0] && ptr[i].english >= ptr_[1])
			++renshu[1];
		if (ptr[i].computers <= ptr_[0] && ptr[i].computers >= ptr_[1])
			++renshu[2];
	}
}
/*****高数排名*****/
int mathrank(struct Student* ptr, int peoples, string number)
{
	struct Student temp;
	//冒泡排序
	for (int i = 0; i < peoples - 1; ++i)
	{
		int flage = 0;
		for (int j = 0; j < peoples - 1; ++j)
		{
			if (ptr[j].math < ptr[j + 1].math)
			{
				++flage;
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
		if (flage == 0)
			break;
	}
	int j = 0;
	for (; j < peoples; ++j)
	{
		if (ptr[j].number == number)
			break;
	}
	return j + 1;
}

/*****英语排名*****/
int englishrank(struct Student* ptr, int peoples, string number)
{
	struct Student temp;
	//冒泡排序
	for (int i = 0; i < peoples - 1; ++i)
	{
		int flage = 0;
		for (int j = 0; j < peoples - 1; ++j)
		{
			if (ptr[j].english < ptr[j + 1].english)
			{
				++flage;
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
		if (flage == 0)
			break;
	}
	int j = 0;
	for (; j < peoples; ++j)
	{
		if (ptr[j].number == number)
			break;
	}
	return j + 1;
}

/*****计算机排名*****/
int computerrank(struct Student* ptr, int peoples, string number)
{
	struct Student temp;
	//冒泡排序
	for (int i = 0; i < peoples - 1; ++i)
	{
		int flage = 0;
		for (int j = 0; j < peoples - 1; ++j)
		{
			if (ptr[j].computers < ptr[j + 1].computers)
			{
				++flage;
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
		if (flage == 0)
			break;
	}
	int j = 0;
	for (; j < peoples; ++j)
	{
		if (ptr[j].number == number)
			break;
	}
	return j + 1;
}

/*****总分排名*****/
int allrank(struct Student* ptr, int peoples, string number)
{
	struct Student temp;
	//冒泡排序
	for (int i = 0; i < peoples - 1; ++i)
	{
		int flage = 0;
		for (int j = 0; j < peoples - 1; ++j)
		{
			if (ptr[j].ave < ptr[j + 1].ave)
			{
				++flage;
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
		if (flage == 0)
			break;
	}
	int j = 0;
	for (; j < peoples; ++j)
	{
		if (ptr[j].number == number)
			break;
	}
	return j + 1;
}

/*****判断用户是否重复*****/
bool The_user_to_repeat(string number)
{
	int peoples = showpeoples();
	struct Student* stu = new struct Student[peoples];
	Get_Mage(stu);
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
