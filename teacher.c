#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "teacher.h"
#include "school1.h"


void add_stu(void)
{
	int choose=0;
	printf("请选择添加方法1.批量导入2.单个添加\n");
	scanf("%d",&choose);
	if(choose == 1)
	{
	int num=0;
	FILE *fp;
	fp=fopen("score.txt","r+");
    	fseek(fp,0L,SEEK_SET);
        
	while(!feof(fp))
	{
		++studentId;
        fscanf(fp,"%s %s\n",student[studentId].name,student[studentId].sex);
		student[studentId].firstLoad=true;
		student[studentId].status=true;
		student[studentId].drop=false;
		student[studentId].id=studentId;
		studentNum++;
		num++;
    	}
	printf("成功录入%d个学生",num);
    fclose(fp);
	anony_key();
	}
	if(choose == 2)
	{
	studentId++;
	student[studentId].id=studentId;
	printf("请输入学生信息 格式：姓名 性别 密码\n");//姓名 性别 学号 密码
	scanf("%s %s %s",student[studentId].name,student[studentId].sex,student[studentId].password);
	
	student[studentId].firstLoad=true;
	student[studentId].status=true;
	student[studentId].drop=false;
	studentNum++;
	printf("添加成功！");
	anony_key();
	}
}

void addcj_stu(void)
{	
	int choose=0;
	int idx=0;
	printf("请选择添加方法1.批量导入2.单个添加\n");
	scanf("%d",&choose);
	if(choose == 1)//导入？
	{
	int num=0;
	FILE *fp;
	fp=fopen("chengji.txt","r+");
    	fseek(fp,0L,SEEK_SET);
        
	while(!feof(fp))
	{
        fscanf(fp,"%hhd %hhd %hhd\n",&student[num].chinese,&student[num].math,&student[num].english);
	num++;
    	}
	printf("成功录入%d个学生成绩",num);
    	fclose(fp);
	anony_key();		
	}
	if(choose == 2)
	{
	printf("请输入学生学号:");
	scanf("%d",&idx);
	printf("请输入成绩：语文 数学 英语：\n");
	scanf("%hhd %hhd %hhd",&student[idx].chinese,&student[idx].math,&student[idx].english);
	printf("添加成功！");
	anony_key();
	}
}

void delete_stu(void)
{
	
	int pass1=-1;
	int pass2=-1;
	printf("请输入删除学生的学号！\n");
	scanf("%d",&pass1);
	if(pass1<-0||pass1>studentId||student[pass1].drop==true)
	{
		printf("该学号不存在或已处于退学状态!\n");
		anony_key();
	}
	else
	{
	printf("请再次输入该学号！\n");
	scanf("%d",&pass2);
	if(pass2 == pass1)
	{
	char name1[20];
	char sex1[20];
	int id1;
	strcpy(name1,student[pass1].name);
	strcpy(sex1,student[pass1].sex);
	id1=student[pass1].id;
	printf("%s %s %d",name1,sex1,id1);
	FILE* frp = fopen("退学名单.c","a");
	setbuf(frp,NULL);
	int ret = fprintf(frp,"%s %s %d ",name1,sex1,id1);
	fflush(frp);
	printf("写入的字节数：%d\n",ret);
	printf("删除成功！\n");
	studentNum--;
	student[pass1].drop=true;
	anony_key();
	}
	else
	{
		printf("两次学号输入不一致\n");
		anony_key();
	}
	}
}

void seek_stu(void)
{
	printf("请输入你所需要的查找的学生\n");
	printf("请选择查找的方式：1.姓名查找 2.学号查找\n");
	int  choose=0;
	int  i = 0; 
	scanf("%d",&choose);
	if(choose == 1)
	{
	printf("请输入你所需要的查找的学生的姓名或姓\n");
	char need[20]="";
	scanf("%s",need);
	for(i=0;i<studentNum;i++)
	{
		if(strstr(student[i].name,need) && student[i].drop==false)
		{
			printf("姓名:%s 性别:%s 学号:%d\n",student[i].name,student[i].sex,student[i].id);	
		}
	}
	anony_key();
	}
	if(choose == 2)
	{
		printf("请输入你所需要的查找的学生的学号\n");
		int id1;
		scanf("%d",&id1);
		printf("姓名:%s 性别:%s 学号:%d\n",student[id1].name,student[id1].sex,student[id1].id);
		anony_key();
	}			
}

void revise_stu(void)
{
	printf("请输入你所要修改学生的学号：\n");
	int idx=0;	
	scanf("%d",&idx);
	if(idx<0||idx>studentId||student[idx].drop==true)
	{
		printf("该学号不存在或已处于退学状态!\n");
		anony_key();
	}
	printf("请输入需要修改的内容:1.修改学生的基本信息2.修改学生的成绩\n");
	int option=0;
	scanf("%d",&option);
	if(option==1)
	{
		printf("原数据：姓名:%s 性别:%s",student[idx].name,student[idx].sex);
		printf("请输入修改后的学生基本信息；\n");
		scanf("%s %s",student[idx+1].name,student[idx].sex);
		printf("修改成功！\n");
		printf("修改数据：姓名:%s 性别:%s",student[idx].name,student[idx].sex);
		anony_key();
	}
	if(option==2)
	{
		printf("原数据：语文:%hhd 数学:%hhd 英语:%hhd",student[idx].chinese,student[idx].math,student[idx].english);
		printf("请输入修改后的学生基本信息；\n");
		scanf("%hhd %hhd %hhd",&student[idx].chinese,&student[idx].math,&student[idx].english);
		printf("修改成功！\n");
		printf("修改数据：语文:%hhd 数学:%hhd 英语:%hhd",student[idx].chinese,student[idx].math,student[idx].english);
		anony_key();
	}
}

void reset_stu(void)
{
	printf("请输入学生学号：\n");
	int idx=0;
	scanf("%d",&idx);
	if(idx<0||idx>studentId||student[idx].drop==true)
	{
		printf("该学号不存在或已处于退学状态!\n");
		anony_key();
	}
	printf("请选择你所需要的重置服务：1.解锁 2.重置密码");
	int choose=0;
	scanf("%d",&choose);
	if(choose==1)
	{
		student[idx].status=true;	
		printf("解锁成功！");
		anony_key();
	}
	if(choose==2)
	{
		printf("请输入你新密码:\n");
		scanf("%s",student[idx].password);
		printf("新密码为:%s \n",student[idx].password);
		anony_key();
	}	
}

void show_stu(void)
{
	int choose=0;
	int i=0;
	printf("请选择你所要显示学生信息类型：1.在校生 2.退学生");
	scanf("%d",&choose);
	if(choose==1)
	{
	for(i=0;i<=studentId;i++)
	{
		if(student[i].drop==false)
		{
			printf("姓名:%s\t性别:%s\t学号:%d\t语文成绩:%hhd\t数学成绩:%hhd\t英语成绩:%hhd \n",student[i].name,student[i].sex,student[i].id,student[i].chinese,student[i].math,student[i].english);
		}		
	}
	anony_key();
	}
	if(choose==2)
	{
	for(i=0;i<=studentId;i++)
	{
		if(student[i].drop==true)
		{
			printf("姓名:%s\t性别:%s\t学号:%d\t语文成绩:%hhd\t数学成绩:%hhd\t英语成绩:%hhd \n",student[i].name,student[i].sex,student[i].id,student[i].chinese,student[i].math,student[i].english);
		}		
	}
	anony_key();
	}
}

void teacherInterface(void)
{
	int ch=0;
	while(1)
	{	system("clear");
		printf("--------------------------\n");
		printf("1.添加学生\n");
		printf("2.删除学生\n");
		printf("3.查找学生\n");
		printf("4.修改学生信息\n");
		printf("5.录入学生成绩\n");
		printf("6.重置或解锁学生密码\n");
		printf("7.显示所有在校或退学学生信息\n");
		printf("8.退出\n");
		printf("--------------------------\n");
		printf("请输入你需要操作的序号：\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add_stu();break;
			case 2:delete_stu();break;
			case 3:seek_stu();break;
			case 4:revise_stu();break;
			case 5:addcj_stu();break;
			case 6:reset_stu();break;
			case 7:show_stu();break;
			case 8:return; break;
			default : break;
		}
	}
}


