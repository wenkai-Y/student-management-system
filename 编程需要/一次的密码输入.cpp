#include <iostream>
#incldue <stdio.h>
#incldue <conio.h>
using namespace std;
int main()
{
	char p[20];
	int i = 0;
	while (i<19)
	{
        char ch ;
        ch = getch() ;
        if (ch == '\n' || ch == '\r') {
            p[i] = '\0' ;
            break ;
        }
        else if (ch == '\b'){
            if (i>0) {
                printf("\b \b") ;
                p[--i] = '\0' ;
            }
        }
        else {
            p[i++] = ch ;
            putchar('*') ;
        }
    }
	return 0;
}