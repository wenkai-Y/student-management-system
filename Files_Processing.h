/*********************************/
/*************文件管理************/
/*********************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "_StuIno_.h"
//#include "Passwords_Management.h"
//extern struct Student* ptr_ssue = NULL;
void Get_Mage(struct Student*);
void fiexd();
void Print();
void save(struct Student*, int);
int showpeoples();   //获得学生人数
void Stu_Stu(struct Student*, int);
void Get_stu_zhanghao_mage(struct Student*, int);
void st_save_2_0(struct Student*, int);

using namespace std;

/*****教师密码查询*****/
void Tea_Pass(string& aswer)
{
	fstream fir;
	fir.open("Files\\1_pss.txt", ios::in);
	if (fir.fail())
	{
		cout << endl;
		cerr << "\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	while (!fir.eof())
	{
		getline(fir,aswer);
	}
	fir.close();
}

/*****学生账号密码查询*****/
int Stu_Pass(string number, string username, string password)
{
	int retur = 0;
	int people = showpeoples();//已保存的人数
	struct Student* stu = new struct Student[people];
	Get_stu_zhanghao_mage(stu, people);
	for (int i = 0; i < people; ++i)
	{
		if ((stu[i].number == number) && (stu[i].name == username) && 
			(stu[i].password == password))
		{
			retur = 1;
			break;
		}
	}
	delete[]stu;
	stu = NULL;
	return retur;
}

/*****教师密码的修改*****/
void Tea_Cge_Pass(string NTPass)
{
	fstream fir;
	fir.open("Files\\1_pss.txt", ios::in | ios::trunc | ios::out);
	if (fir.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	fir << NTPass;
	fir.close();
}

/*****管理员获取密码*****/
void Get_Ador_pass(string& password)
{
	fstream fil;
	fil.open("Files\\3_pass.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 管理员系统正在维修，请择其他服务。";
		exit(1);
	}
	fil >> password;
	//cout << password << endl;
	fil.close();
}

/*****获取学生所有账号信息*****/
void GEt_Stu_s(struct Student* ptr, int people)
{
	fstream fil;
	fil.open("Files\\2_pass.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 管理员系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int i = 0; i < people; ++i)
	{
		fil >> ptr[i].number;
		fil >> ptr[i].name;
		fil >> ptr[i].password;
	}
	fil.close();
}

/*****学生密码的修改*****/
void Change_stupassword(string number, string passwords)
{
	int people = showpeoples();
	struct Student* stu = new struct Student[people];
	Get_stu_zhanghao_mage(stu, people);
	for (int i = 0; i < people; ++i)
	{
		if (stu[i].number == number)
		{
			stu[i].password = passwords;
			break;
		}
	}
	st_save_2_0(stu, people);
	delete[]stu;
	stu = NULL;
}

/*****教师保存学生信息*****/
void TeachersKeepStudentInformation(int STUpeope)
{
	struct Student* ptr_ssue = TEA_APP_STU(STUpeope);
	if (ptr_ssue == NULL)
		cout << "\n\t\t\t\t\t ***学生数据已删除" << endl;
	else
	{
		fstream fir;
		fir.open("Files\\学生信息（副本）.txt", ios::in | ios::app | ios::out);
		if (fir.fail())
		{
			cout << endl;
			cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
			exit(1);
		}
		for (int i = 1; i <= STUpeope; ++i)
		{
			Stu_Stu(ptr_ssue, i - 1);   //保存学生账号密码信息到2_pass.txt
			fir << ptr_ssue[i - 1].number << " ";
			fir << ptr_ssue[i - 1].name << " ";
			fir << ptr_ssue[i - 1].gender << " ";
			fir << ptr_ssue[i - 1].math << " ";
			fir << ptr_ssue[i - 1].english << " ";
			fir << ptr_ssue[i - 1].computers << " ";
			fir << ptr_ssue[i - 1].ave << "\n";
		}
		delete[]ptr_ssue;
		ptr_ssue = NULL;
		fir.close();
		cout << "\t\t\t\t\t >>>学生信息保存完成并完成学生注册！！！" << endl;
	}
}

/*****教师保存学生信息2.0*****/
void save(struct Student* ptr, int people)
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
	cout << "\t\t\t\t\t >>>保存完成！！！" << endl;
}


/*****教师打印学生信息*****/
void Print()
{
	int people = showpeoples();
	if (people != 0)
	{
		struct Student* ptr = new Student[people];
		Get_Mage(ptr);
		cout << "\t\t\t  *************************添加的学生信息************************" << endl;
		show_xinxi(ptr, people);
		delete[]ptr;
		ptr = NULL;
		//fil.close();
	}
	else
	{
		puts("\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		puts("\t\t\t      >>>暂无学生信息，请您录入学生信息或告知学生进行注册<<<");
		puts("\t\t\t      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	}
	//system("pause");
}

/*****修改学生信息*****/
void fiexd()
{
	Print();
	int people = showpeoples();
	struct Student* ptr = new Student[people];
	Get_Mage(ptr);
	Chage_TEA_ADD_STU(ptr, people);
	save(ptr, people);
	//保存数据
	delete[]ptr;
	ptr = NULL;
}

/*****教师删除全部学生信息*****/
void delel()
{
	fstream fil;
	fil.open("Files\\学生信息（副本）.txt", ios::trunc | ios::out | ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	fil.close();
	fil.open("Files\\2_pass.txt", ios::trunc | ios::out | ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	fil.close();
}

/*****教师删除单个学生信息*****/
void del_d_stu(int peo, int all)
{
	vector<string> st;
	vector<double> st_;
	vector<string> st_pass;
	vector<string>::iterator iter_1 = st.begin();
	vector<double>::iterator iter_2 = st_.begin();
	vector<string>::iterator iter_3 = st_pass.begin();
	string number, name, passward, gender;
	double math, english, computers, ave;
	fstream fil;
	fil.open("Files\\2_pass.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int i = 0; i < all; ++i)
	{
		fil >> number;
		fil >> name;
		fil >> passward;
		st_pass.push_back(number);
		st_pass.push_back(name);
		st_pass.push_back(passward);
	}
	fil.close();
	fil.open("Files\\学生信息（副本）.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int j = 0; j < all; ++j)
	{
		fil >> number;
		fil >> name;
		fil >> gender;
		fil >> math;
		fil >> english;
		fil >> computers;
		fil >> ave;
		st.push_back(number);
		st.push_back(name);
		st.push_back(gender);
		st_.push_back(math);
		st_.push_back(english);
		st_.push_back(computers);
		st_.push_back(ave);
	}
	fil.close();
	//找到删除人并删除
	for (int q = 0; q <= (all - 1) * 3; q += 3)
	{
		if (st_pass[q] == st[(peo - 1) * 3])
		{
			for (int o = 0; o < 3; ++o)
			{
				st_pass.erase(st_pass.begin() + q);
			}
			break;
		}
	}
	fil.open("Files\\2_pass.txt", ios::out | ios::trunc | ios::in);
	{
		if (fil.fail())
		{
			cout << endl;
			cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
			exit(1);
		}
	}
	int rehsu = 0;
	for (int w = 0; w < all - 1; ++w)
	{
		fil << st_pass[rehsu++] << " " << st_pass[rehsu++] << " " << st_pass[rehsu++] << "\n";
	}
	fil.close();
	for (int T = 0; T < 3; ++T)
	{
		int temp = ((peo - 1) * 3);
		st.erase(st.begin() + temp);
	}
	for (int t = 0; t < 4; ++t)
	{
		int temp = ((peo - 1) * 4);
		st_.erase(st_.begin()+ temp);
	}
	fil.open("Files\\学生信息（副本）.txt", ios::out | ios::trunc | ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 教师系统正在维修，请择其他服务。";
		exit(1);
	}
	int s = 0, d = 0;
	for (int p = 0; p < all - 1; ++p)
	{
		fil << st[s++]  << " ";
		fil << st[s++]  << " ";
		fil << st[s++]  << " ";
		fil << st_[d++] << " ";
		fil << st_[d++] << " ";
		fil << st_[d++] << " ";
		fil << st_[d++] << "\n";
	}
	fil.close();
	st.clear();
	vector<string>().swap(st);
	st_.clear();
	vector<double>().swap(st_);
	st_pass.clear();
	vector<string>().swap(st_pass);
}

/*****教师搜索学生信息*****/
int find(string name, int leixing, string number)
{
	int what;
	int people = showpeoples();   //获得已经保存学生的人数
	struct Student* ptr_stu = new struct Student[people];
	Get_Mage(ptr_stu);   //获得学生数据
	int temp = 0;
	do
	{
		if (temp < people && leixing == 0)
		{
			if (ptr_stu[temp].name == name)
			{
				what = 0;
				showone(ptr_stu, temp, 0);
				break;
			}
			else
			{
				++temp;
			}
		}
		else
			if (temp < people && leixing == 1)
			{
				if (ptr_stu[temp].number == number)
				{
					what = 0;
					showone(ptr_stu, temp, 0);
					break;
				}
				else
				{
					++temp;
				}
			}
		else
		{
			what = 1;
			cout << "\n\t\t\t\t\t $$$很抱歉，未找到该学生信息，请查明以后再进行查询。" << endl;
			cout << "\t\t\t\t\t ";
			system("pause");
			break;
		}
	} while (true);
	delete[]ptr_stu;
	ptr_stu = NULL;
	return what;
}

/*****学生用户密码账号保存*****/
void Stu_Stu(struct Student* ptr, int peo)
{
	fstream fil;
	fil.open("Files\\2_pass.txt", ios::in | ios::out | ios::app);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 学生系统正在维修，请择其他服务。";
		exit(1);
	}
	fil << ptr[peo].number << " " << ptr[peo].name << " " << ptr[peo].password << " \n";
	fil.close();
}

/*****学生信息账号保存*****/
void st_save(struct Student* ptr)
{
	fstream fil;
	fil.open("Files\\学生信息（副本）.txt", ios::in | ios::out | ios::app);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 学生系统正在维修，请择其他服务。";
		exit(1);
	}
	fil << ptr->number << " " << ptr->name << " " << ptr->gender << " " << ptr->math << " " <<
		ptr->english << " " << ptr->computers << " " << ptr->ave << "\n";
	fil.close();
}

/*****学生信息账号保存2.0*****/
void st_save_2_0(struct Student* ptr, int all)
{
	fstream fil;
	fil.open("Files\\2_pass.txt", ios::in | ios::trunc | ios::out);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 学生系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int g = 0; g < all; ++g)
	{
		fil << ptr[g].number << " ";
		fil << ptr[g].name << " ";
		fil << ptr[g].password;
		fil << "\n";
	}
	fil.close();
}

/*****学生账号信息的获取*****/
void Get_stu_zhanghao_mage(struct Student* ptr, int people)
{
	fstream fil;
	fil.open("Files\\2_pass.txt", ios::in);
	if (fil.fail())
	{
		cout << endl;
		cerr << "\n\t\t\t\t\t 学生系统正在维修，请择其他服务。";
		exit(1);
	}
	for (int k = 0; k < people; ++k)
	{
		fil >> ptr[k].number;
		fil >> ptr[k].name;
		fil >> ptr[k].password;
	}
	fil.close();
}

/*****获得学生信息*****/
void Get_Mage(struct Student* ptr)
{
	int people = showpeoples();
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

/*****获得已保存的学生人数*****/
int showpeoples()
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
