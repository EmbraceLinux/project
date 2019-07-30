#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "school1.h"

void paixu(void)
{
	int i =0,j=0,k=0;
	float ave1=0,ave2=0,ave3=0;
	int Sum1=0,Sum2=0,Sum3=0;
	for(i=0;i<studentId;i++)
	{
		if(student[i].drop == true) continue;
		student[i].sum=student[i].chinese+student[i].math+student[i].english;
		Sum1+=student[i].chinese;
		Sum2+=student[i].math;
		Sum3+=student[i].english;
		ave1=Sum1/(double)studentNum;
		ave2=Sum2/(double)studentNum;
		ave3=Sum3/(double)studentNum;
	}
    for(j=0;j<studentId-1;j++)
	{
		if(student[j].drop == true) continue;
        for(k=0;k<studentId-1-j;k++)
		{
		   if(student[k].drop == true) continue;
           if(student[k].sum < student[k+1].sum)
			{
                temp=student[k];
                student[k]=student[k+1];
                student[k+1]=temp;
            }
        }
	}
	printf("姓名\t学号\t语文\t数学\t英语\t总分\t排名\n");
    for(i=0;i<studentId;i++)
	{
		if(student[i].drop == true) continue;
        printf("%s\t%d\t%hhd\t%hhd\t%hhd\t%d\t%d\n",student[i].name,student[i].id,student[i].chinese,student[i].math,student[i].english,student[i].sum,i+1);
    }
	printf("\n平均分：       %.2lf\t%.2f\t%.2f\n",ave1,ave2,ave3);
}
void change(int *p)
{
	char password[20];
	char password2[20];
				while(1)
					{
						system("clear");
						printf("输入新密码:");
						scanf("%s",password);
						stdin->_IO_read_ptr = stdin->_IO_read_end;
						printf("确认密码");
						scanf("%s",password2);
						stdin->_IO_read_ptr = stdin->_IO_read_end;
						if(strcmp(password,password2) != 0)
						{
							printf("两次输入不一致，请重新输入!");
							anony_key();
						}
						else 
						{
							strcpy(student[*p].password,password);
							break;
						}
					}
}
void Printf(int *p)
{
	printf("%s %s %d\n",student[*p].name,student[*p].sex,student[*p].id);
}
void studentInterface(int *p)
{
	while(true)
	{
		system("clear");
		puts("  ********************  ");
		puts("  1.查询成绩");
		puts("  2.修改密码");
		puts("  3.查看个人信息");
		puts("  4.返回主界面");
		puts("  ********************  ");
		switch(get_cmd('1','4'))
		{
			case '1':paixu();anony_key();break;
			case '2':change(p);anony_key();break;
			case '3':Printf(p);anony_key();break;
			case '4': return;
			default:
			break;
		}
	}
}
