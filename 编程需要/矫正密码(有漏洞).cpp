#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int main()
{
	char pass[20];
	char passconfirm[20];
	int i=0;
	cout<<"input password:";
	while((pass[i]=getch())!=13)
	{
		putch('*');
		i++;
	}
	pass[i]='\0';
	i=0;
	cout<<"\nconfirm password:";
	while((passconfirm[i]=getch())!=13)
	{
		putch('*');
		i++;
	}
	passconfirm[i]='\0';
	if(strcmp(pass,passconfirm)==0)
	{
		cout<<"\npassword confirmed!"<<endl;
		cout<<pass<<endl;
	}
	else
	{
		cout<<"wrong!";
	}
	return 0;
}