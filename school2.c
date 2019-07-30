#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <stdbool.h>
#include <string.h>
#include "school1.h"
#include "school2.h"
#include "master.h"
#include "teacher.h"
#include "student.h"

void loadStudent(void)
{
	int ID;
	char password[20];
	char password2[20];
	int flag = 1;  //判断账号是否封锁
	printf("学号：");
	scanf("%d",&ID);
	stdin->_IO_read_ptr = stdin->_IO_read_end; //清楚缓冲区
	if(ID >= 0 && ID <= studentId) //学生存在
	{
		if(student[ID].status == false)
		{
			printf("账号已锁定！");
			anony_key();
			return ;
		} 
		do{
			if( 1==flag )    printf("请输入密码：");
			else    printf("密码错误请重新输入(还有%d次机会):",4-flag);
			scanf("%s",password);
			stdin->_IO_read_ptr = stdin->_IO_read_end;
		}while(++flag < 4 && strcmp(password,student[ID].password));
		if(!strcmp(student[ID].password,password))
		{
			if(student[ID].drop == true) //有没有退学
			{
				printf("已退学！");
				anony_key();
				return ;
			} 
			if(student[ID].firstLoad == true) //第一次登陆
			{
				while(1)
				{
					system("clear");
					printf("输入新密码:");
					scanf("%s",password);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					printf("确认密码");
					scanf("%s",password2);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					if(strcmp(password,password2))
					{
						printf("两次输入不一致，请重新输入!");
						anony_key();
					}
					else 
					{
						student[ID].firstLoad = false;
						strcpy(student[ID].password,password);
						puts("重置密码成功！");
						anony_key();
						break;
					}
				}
			}
				studentInterface(&ID);
				return;
			}
		else
		{
			student[ID].status = false; 
			printf("账号已锁定!请联系教师解锁\n");
			anony_key();
			return ;
		}
		}
	else
	{
		puts("学号不存在！");
		anony_key();
		return ;
	}

return ;
}

void loadTeacher(void)
{
	int ID;
	char password[20];
	char password2[20];
	int flag = 1;  //判断账号是否封锁
	printf("工号：");
	scanf("%d",&ID);
	stdin->_IO_read_ptr = stdin->_IO_read_end; //清除缓冲区
	if(ID >= 0 && ID <= teacherId) //教师存在
	{
		if(teacher[ID].status == false) 
		{
			printf("账号已锁定！");
			anony_key();
			return ;
		} 
		do{
			if(1 == flag)    printf("请输入密码：");
			else    printf("密码错误请重新输入(还有%d次机会):",4-flag);
			scanf("%s",password);
			stdin->_IO_read_ptr = stdin->_IO_read_end;
		}while(++flag < 4 && strcmp(password,teacher[ID].password));

		if(!strcmp(teacher[ID].password,password))
		{
			if(teacher[ID].drop == true) 
			{
				printf("已离职！");
				anony_key();
				return ;
			} 
			if(teacher[ID].firstLoad == true) //第一次登陆
			{
				while(1)
				{
					system("clear");
					printf("输入新密码：");
					scanf("%s",password);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					printf("确认密码：");
					scanf("%s",password2);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					if(strcmp(password,password2))
					{
						printf("两次输入不一致，请重新输入!");
						anony_key();
					}
					else 
					{
						teacher[ID].firstLoad = false;
						strcpy(teacher[ID].password,password);
						puts("重置密码成功！");
						anony_key();
						break;
					}
				}
			}
			teacherInterface();
			return ;
		}
		else
		{
			teacher[ID].status = false; 
			printf("账号已锁定!请联系校长解锁\n");
			anony_key();
			return ;
		}
	}
	else
	{
		puts("工号不存在！");
		anony_key();
		return ;
	}
return ;
}

void loadMaster(void)
{
	char ID[20];
	char password[20];
	char password2[20];
	printf("校长账号：");
	scanf("%s",ID);
	stdin->_IO_read_ptr = stdin->_IO_read_end; //清除缓冲区
	if(!strcmp(ID,"admin")) 
	{
		printf("输入密码：");
		scanf("%s",password);
		//stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(!strcmp(masterPass,password))
		{
			if(masterFirst == true) //第一次登陆
			{
				while(1)
				{
					system("clear");
					printf("输入新密码：");
					scanf("%s",password);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					printf("确认密码：");
					scanf("%s",password2);
					stdin->_IO_read_ptr = stdin->_IO_read_end;
					if(strcmp(password,password2))
					{
						printf("两次输入不一致，请重新输入!");
						anony_key();
						continue;
					}
					else 
					{
						masterFirst = false;
						strcpy(masterPass,password);
						puts("重置密码成功！");
						anony_key();
						break;
					}
				}
			}
			masterInterface();
			return ;
		}
		else return ;
	}
	else
	{
		puts("账号输入错误！");
		anony_key();
		return ;
	}
return ;
}

void MainInterface(void)
{
	while(1)
	{
		system("clear");
		puts("*****************************");
		puts("1、学生界面");
		puts("2、教师界面");
		puts("3、校长界面");
		puts("4、退出界面");
		puts("*****************************");

		switch(get_cmd('1','4'))
		{
			case '1':loadStudent();break;
			case '2':loadTeacher();break;
			case '3':loadMaster();break;
			case '4':return;
			default : break;
		}
	}
	return ;
}
