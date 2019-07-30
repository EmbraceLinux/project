#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "master.h"
#include "school1.h"

void changePass(void)
{
	char password[20];
	char password2[20];
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
			strcpy(masterPass,password);
			puts("修改密码成功！");
			anony_key();
			break;
		}
	}
	return;
}

void teacherPass(void)
{
	int tID=-1;
	char password[20];
	char password2[20];
	printf("输入教师工号：");
	scanf("%d",&tID);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(tID >=0 && tID <= teacherId) //说明教师存在
	{
		while(1)
		{
			system("clear");
			printf("输入教师新密码：");
			scanf("%s",password);
			stdin->_IO_read_ptr = stdin->_IO_read_end;
			printf("确认教师密码：");
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
				strcpy(teacher[tID].password,password);
				puts("修改密码成功！");
				anony_key();
				break;
			}
		}
		return;
	}
	else
	{
		puts("不存在该教师！");
		anony_key();
		return;
	}
}

void teacherStatus(void)
{
	int tID=-1;
	printf("输入教师工号：");
	scanf("%d",&tID);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	char cmd;
	if(tID >=0 && tID <= teacherId) //说明教师存在
	{
		if(false == teacher[tID].status)
		{
			puts("该账号已被冻结！");
			printf("是否为其解锁(输入y为其解锁)：");
			scanf("%c",&cmd);
			stdin->_IO_read_ptr = stdin->_IO_read_end;
			if('y' == cmd)
			{
				teacher[tID].status = true;
				puts("解冻成功！");
				anony_key();
				return;
			}
			else 
			{
				puts("仍未解冻！");
				anony_key();
				return;
			}
		}
		puts("该教师账户未被冻结！");
		anony_key();
		return;
	}
	else
	{
		puts("不存在该教师！");
		anony_key();
		return;
	}
}

void addTeacher(void)
{
	char tName[20];
	char tSex[20];
	printf("自动生成教师工号：%d\n",++teacherId);
	teacher[teacherId].id = teacherId;
	teacher[teacherId].status = true;
	teacher[teacherId].drop = false;
	teacher[teacherId].firstLoad = true;
	strcpy(teacher[teacherId].password,"0");

	printf("输入教师姓名：");
	scanf("%s",tName);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	strcpy(teacher[teacherId].name,tName);
	
	printf("输入教师性别：");
	scanf("%s",tSex);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	strcpy(teacher[teacherId].sex,tSex);

	puts("录入成功！");
	anony_key();

	return;
}

void delTeacher(void)
{
	int tID;
	printf("输入教师工号：");
	scanf("%d",&tID);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	char cmd;
	if(tID >=0 && tID <= teacherId) //说明教师存在
	{
		if(false == teacher[tID].drop)
		{
			puts("该教师正在奋斗！");
			printf("是否辞去该教师(输入y辞去)：");
			scanf("%c",&cmd);
			stdin->_IO_read_ptr = stdin->_IO_read_end;
			if('y' == cmd)
			{
				teacher[tID].drop = true;
				puts("辞去成功！");
				anony_key();
				return;
			}
			else 
			{
				puts("该教师继续奋斗！");
				anony_key();
				return;
			}
		}
		puts("该教师已离职！");
		anony_key();
		return;
	}
	else
	{
		puts("不存在该教师！");
		anony_key();
		return;
	}
}

void showTeacher(void)
{
	int i;
	for(i = 0; i<=teacherId; ++i)
	{
		if(!teacher[i].drop) //未离职是false
		printf("%d %s %s\n",teacher[i].id,teacher[i].name,teacher[i].sex);
	}
	puts("显示结束！");
	anony_key();
	return;
}

void showLeave(void)
{	
	int i;
	for(i = 0; i<=teacherId; ++i)
	{
		if(teacher[i].drop) //离职是true
		printf("%d %s %s\n",teacher[i].id,teacher[i].name,teacher[i].sex);
	}
	puts("显示结束！");
	anony_key();
	return;
}

void masterInterface(void)
{
	while(1)
	{
		system("clear");
		puts("*****************************");
		puts("1、修改自己的密码");
		puts("2、重置教师的密码");
		puts("3、解锁教师账号");
		puts("4、添加教师");
		puts("5、删除教师");
		puts("6、显示所有在职教师");
		puts("7、显示所有离职教师");
		puts("8、退出");
		puts("*****************************");

		switch(get_cmd('1','8'))
		{
			case '1':changePass();break;
			case '2':teacherPass();break;
			case '3':teacherStatus();break;
			case '4':addTeacher();break;
			case '5':delTeacher();break;
			case '6':showTeacher();break;
			case '7':showLeave();break;
			case '8':return;
			default : break;
		}
	}
	return ;
}
