/*****************************************************************
*   Copyright (C) 2019 ZhiZhen Ltd. All rights reserved.
*   FileName：school1.h
*   Author：shang
*   Date：2019年06月29日
*   Description：
*****************************************************************/

#ifndef SCHOOL1_H
#define SCHOOL1_H

#include <stdbool.h>
#include <stdio.h>

extern int studentNum;
extern int studentId;

extern int teacherNum;
extern int teacherId;

extern char masterPass[20];
extern bool masterFirst;

struct Student
{
	char name[20];
	char sex[20];
	int id;
	char password[20];
	char chinese;
	char math;
	char english;
	int sum;
	bool firstLoad;   //firstLoad和status在教师添加的时候赋值，先判断是不是第一次登陆，在判断账号有没有被锁
	bool status;	  //账户状态
	bool drop;	  //drop为true的时候表示退学
}student[100],temp;

struct Teacher
{
	char name[20];
	char sex[20];
	int id;
	char password[20];
	bool firstLoad;   //firstLoad和status在教师添加的时候赋值，先判断是不是第一次登陆，在判断账号有没有被锁
	bool status;
	bool drop;
}teacher[100];

void anony_key(void);

char get_cmd(char start,char end);

#endif//SCHOOL1_H
