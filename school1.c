#include "school1.h"
#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <stdbool.h>

int studentNum=0;
int studentId=-1;

int teacherNum=0;
int teacherId=-1;

char masterPass[20] = "admin";
bool masterFirst = true;


void anony_key(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	printf("按任意键继续...");
	getch();
}

char get_cmd(char start,char end)
{
	while(true)
	{
		printf("\r请输入指令(%c,%c)：",start,end);
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

