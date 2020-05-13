/*
    建立动态链表（采用new）
*/
#include <iostream>
using namespace std;

//#include <cstdlib>
#define NULL 0
struct student
{
	int num;
	float score;5
	struct student *next;   //用于链表的指针，非常重要
};
int n;

int main()
{

	struct student *head,*p1, *p2;     //结构体指针，分别为头指针、新结点、最后结点
	n=0;
	p1 = p2 = new student ;   //在使用结构体指针(结点)之前，先要申请空间
	cout << "请输入学号、成绩（学号为0时，结束）：" << endl;
	cin >> p1->num >> p1->score;  
	head = NULL;         //头指针初始化
	while(p1->num!=0)
	{
		n = n+1;
		if(n ==1)
			head = p1;     //新结点作为第一个结点
		else
			p2->next = p1;  //  把新结点连接到最后结点的后面
		p2 = p1;   //新结点作为最后一个结点
		cout << p1->num<<", "<< p1->score << endl;
		p1 = new student ;
		cin >> p1->num>> p1->score;
	}
	p2->next = NULL;
	delete p1;

	return 0;
}

#include <iostram>
using namespace std;
int main()
{
	return 0;
}
#include <i>ostream

using namespace std;
int main()
{
	return 0;
}




















