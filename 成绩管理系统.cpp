#include<bits/stdc++.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>
#include<time.h> 

typedef struct {
	char data[50];
}course;
typedef struct student{
	char name[20];
	int Id;
	int* score;
}stu;

// 文件指针
FILE* fp;
// 保存课程的指针
course* course_point;
// 保存学生信息的指针
stu* student_point;
// 课程的数量
int course_num;
// 学生的数量
int StudentNum;
// 全局变量 课程
int index;


void Welcome();		// 菜单
void over();		// 当选项 程序执行完之后
void Course();		// 输入课程名字的函数
void Student();		// 输入学生的信息 的函数
void ReadFile();	// 输出 所有的信息
void Search();		// 通过 学号 or 名字 进行查找
void DataAnalysis();// 对成绩 进行分析 
void Average();		// 平均成绩 数据

// 欢迎界面
void Welcome()
{
	printf("**********************************************\n");
	printf("            欢迎来到成绩管理系统              \n");
	printf("**********************************************\n");
	printf("             输入课程名字请按1                \n");
	printf("             输入学生信息请按2                \n");
	printf("             生成成绩数据请按3                \n");
	printf("            显示生成的数据请按4               \n");
	printf("                查询请按5                     \n");
	printf("                退出请按6                     \n");
	printf("**********************************************\n");
	printf("请输入你要选择的功能：");
	// 用户输入key
	char InputKey;

	std::cin>>InputKey;
	// 这样可以防止用户乱输入 导致 程序不正常
	char ch; while ((ch = getchar()) != '\n' && ch != EOF);
	
	switch (InputKey)
	{
	case   '1':
		Course();	// 输入课程名字的函数
		break;
	case  '2' :
		Student();	// 输入 学生的信息
		break;
	case '3':
		DataAnalysis(); // 对成绩 数据 进行 分析
		break;
	case '4':
		ReadFile();		// 读取 成绩 的数据
		break;
	case '5':
		Search();		// 查找
		break;
	case '6':
		printf("即将退出系统，欢迎再次使用^.^\n");
		return;
		break;
	default:
		printf("输入格式错误，请重新输入\n");
		Sleep(500);
		system("cls");
		Welcome();
		return;
	}
	over();
		
}


// 当选项 程序执行完之后
void over()
{
	char InputKey;
	// 最后的 
	printf("\n\n是否回到菜单界面或者退出程序(y/q):");
	

	std::cin >> InputKey;

	if (InputKey == 'y' || InputKey == 'Y')
	{
		printf("即将刷新！！！\n");
		Sleep(500);		// 延迟 500ms
		system("cls");  // 清屏
		Welcome();
	}
	else if (InputKey != 'q' && InputKey != 'Q')
	{
		printf("输入格式错误请重新输入！");
		over();		
	}
}


// 输入课程名字的函数
void Course()
{
	int  i; 
	
	fopen_s(&fp, "input.dat", "w");  // 打开文件 以写的方式打开
	
	printf("请输入课程的个数：");
	scanf("%d", &course_num);		

	// 通过动态 生成 保存 课程的信息的  数组
	course_point = (course*)malloc(sizeof(course) * (course_num+1));
	
	//最后一个保存 平均成绩
	strcpy(course_point[course_num].data ,"平均成绩\0");
	
	fprintf(fp, "%-10s %-6s","姓名","学号");	// 写入 姓名 和 学号
	for (i = 0; i < course_num; i++)
	{
		printf("请输入课程的名字：");
		getchar();
		scanf("%s", &course_point[i].data);			// 读入
		
		fprintf(fp, "%-7s ", course_point[i].data); // 写入 课程的名字
	}
	fprintf(fp, "\n");
	fclose(fp);		// 关闭 
	printf("课程信息输入完毕！！！");
	
}


// 输入学生的信息 的函数
void Student()
{
		
	int  i,j, StudentId, StudentMark;	// 学生的数量      学生的学号   分数
	
	fopen_s(&fp, "input.dat", "a");		// 打开 成绩的数据 以追加的方式 打开

	printf("请输入学生的数量：");
	scanf("%d", &StudentNum);			

	//通过动态 生成 保存学生 信息的数组
	student_point =(stu*) malloc(sizeof(stu) * StudentNum);

	for (i = 0; i < StudentNum; i++)
	{
		// 读入学生的名字和学号
		printf("请输入学生的姓名：");
		scanf("%s", student_point[i].name);
		printf("请输入%s的学号：", student_point[i].name);
		scanf("%d", &student_point[i].Id);

		// 向文件中写入 姓名和 学号
		fprintf(fp,"%-10s %-6d", student_point[i].name, student_point[i].Id);

		// 通过动态 生成 保存学生 成绩 的数组
		student_point[i].score =(int*) malloc(sizeof(int) * (course_num+1));

		int num = 0;	// 保存 本课程的 所有成绩

		// 读入各科的成绩
		for(j=0;j<course_num ;j++)
		{ 
			printf("请输入%s %s课程的成绩：", student_point[i].name,course_point[j].data);
			scanf("%d",&student_point[i].score[j]);
			// 向文件中写入 成绩
			fprintf(fp, "%-7d ", student_point[i].score[j]);
			num += student_point[i].score[j];
		}
		// 保存 平均成绩 
		student_point[i].score[course_num] = num / course_num;
		fprintf(fp, "\n");
	}
	//关闭文件
	fclose(fp);
	printf("学生信息输入完毕！！！");
	
}

// 读取文件
void ReadFile()
{
	int i, num;
	char path[100],ch[1000];				// path 保存文件的路径
	printf("已经生成的文件：\n");
	// 用来 读取已保存 的信息
	for (i = 0; i <= course_num; i++)
	{
		printf("\t%d.%s的排名.dat\n",i,course_point[i].data);
	}
	printf("其输入要查看的文件：");
	scanf("%d",&num);
	if (0 <= num && num <= course_num)
	{
		strcpy(path, course_point[num].data);// 生成 path
		strcat(path,"的排名.dat\0");

		fopen_s(&fp, path, "r");			//打开 path文件 以只读的方式打开
		printf("\n\n打开 %s\n",path);
		
		while (!feof(fp))					// 当文件指针 不是在 文件末尾时
		{
			if (fgets(ch, 1000, fp)!=NULL)
				printf("%s",ch);
		}
		fclose(fp);							// 关闭文件
	}
}

// 查找
//void Search()
//{
//	int i = 0, StudentId,SearchId,Select,IsFind=0, IsFirst=1;
//	char ch[1000],StudentName[20],SearchName[20],info[1000]; // 用来 保存 读入的信息
//
//	fopen_s(&fp, "input.dat", "r");			// 打开文件 以只读的方式 打开
//
//	printf("请选择是以名字(按1) 还是学号(按2) 查序：");
//	scanf("%d",&Select);
//	if (Select == 1)
//	{
//		printf("\n请输入 要查的名字：");
//		scanf("%s",SearchName);
//	}
//	else if (Select == 2)
//	{
//		printf("\n请输入 要查的学号：");
//		scanf("%d", &SearchId);
//	}
//	else
//	{
//		printf("输入格式错误！！！请重新输入\n");
//		Search();
//		return;
//	}
//	fgets(info, 1000, fp);					// 读入 课程 信息 
//	
//
//	while (!feof(fp))						// 当文件指针 不是在 文件末尾时
//	{
//		fscanf(fp,"%s %d",StudentName,&StudentId);
//		if (fgets(ch, 1000, fp) != NULL)	// 读取后面的 课程 信息
//		{
//			// 通过查找姓名找到的
//			if ((Select == 1 && strcmp(SearchName, StudentName) == 0)|| (Select == 2 && StudentId == SearchId))
//			{
//				IsFind = 1;
//				if(IsFirst)
//					printf("%s",info);
//				IsFirst = 0;
//				printf("%-10s %d%s", StudentName,  StudentId,ch);
//			}
//		}
//				
//	}
//	if (IsFind == 0)
//	{ 
//		if (Select == 1)
//			printf("未找到姓名为%s的学生\n", SearchName);
//		else
//			printf("未找到学号为%d的学生\n", SearchId);
//	}
//	// 关闭文件
//	fclose(fp);
//}

void Search()
{
	int i = 0, StudentId, SearchId, Select, IsFind = 0, IsFirst = 1;
	char ch[1000], StudentName[20], SearchName[20], info[1000]; // 用来 保存 读入的信息

	fopen_s(&fp, "input.dat", "r");			// 打开文件 以只读的方式 打开

	printf("请选择是以名字(按1) 还是学号(按2) 查序：");
	scanf("%d", &Select);
	if (Select == 1)
	{
		printf("\n请输入 要查的名字：");
		scanf("%s", SearchName);
	}
	else if (Select == 2)
	{
		printf("\n请输入 要查的学号：");
		scanf("%d", &SearchId);
	}
	else
	{
		printf("输入格式错误！！！请重新输入\n");
		Search();
		return;
	}
	//fgets(info, 1000, fp);					// 读入 课程 信息 

	for (int i = 0; i < StudentNum; i++)
	{
		if ((Select == 1 && strcmp(SearchName, student_point[i].name) == 0) || (Select == 2 && student_point[i].Id == SearchId))
		{
			IsFind = 1;
			if (IsFirst)
			{
				printf(" % -10s %-6s","姓名","学号");
				for (int j = 0; j <course_num;j++)
					printf("%-7s ", course_point[j].data);
				printf("\n");
			}
			IsFirst = 0;
			printf("%-10s %-6d", student_point[i].name, student_point[i].Id);
			for (int j = 0; j < course_num; j++)
				printf("%-7d ", student_point[i].score[j]);
		}
	}
	// 未找到时
	if (IsFind == 0)
	{
		if (Select == 1)
			printf("未找到姓名为%s的学生\n", SearchName);
		else
			printf("未找到学号为%d的学生\n", SearchId);
	}
	// 关闭文件
	fclose(fp);
}

// 配合sort 使用的比较函数
int cmp(stu a, stu b)
{
	return a.score[index]>b.score[index];
}

// 数据分析
void DataAnalysis()
{
	for (index = 0; index < course_num; index++)
	{
		std::sort(student_point, student_point + StudentNum,cmp);
		char ch[20] = "的排名.dat\0";
		char path[50];		// path 保存文件的路径
		//打开 path文件 以只读的方式打开
		strcpy(path, course_point[index].data);
		strcat(path,ch);
		
		fopen_s(&fp, path,"w");
		// 写入  名字 学号 课程的名字
		fprintf(fp,"%-10s %-6s%-7s\n","名字","学号", course_point[index].data);
		// num 是全部的成绩 num1 是不及格人数  num2是60-69分人数
		// num3是70-79分人数 num4 是 80-89分人数 num5 是 90分以上
		int min = student_point[StudentNum-1].score[index],\
			max= student_point[0].score[index],num=0,num1=0,num2=0,num3=0,num4=0,num5=0;
		// 学生 成绩
		for (int z = 0; z < StudentNum; z++)
		{
			num += student_point[z].score[index];
			switch (student_point[z].score[index]/10)
			{
			case 10:
			case 9:
				num5++;
				break;
			case 8:
				num4++;
				break;
			case 7:
				num3++;
				break;
			case 6:
				num2++;
				break;
			default:
				num1++;
				break;
			}

			fprintf(fp, "%-10s %-6d%-7d\n", student_point[z].name, \
						student_point[z].Id, student_point[z].score[index]);

		}
		printf("%s已生成！！！\n",path);

		fprintf(fp,"\n\n成绩的数据分析：\n平均成绩=%.2f\t最高分=%d\t最低分=%d\n\
不及格人数=%d\t60-69分人数=%d\t70-79分人数=%d\n\
80-89分人数=%d\t90分以上人数=%d\n",1.0*num/ StudentNum,max,min,num1,num2,num3,num4,num5);
		
		
		fclose(fp);
	}
	// 生成平均成绩
	Average();
}


// 平均成绩 数据
void Average()
{
	// 打开文件
	fopen_s(&fp, "平均成绩的排名.dat", "w");

	std::sort(student_point, student_point + StudentNum, cmp); //结构体的排序

	fprintf(fp, "%-10s %-6s", "姓名", "学号");
	// 写入 课程的名字
	for (int i = 0; i <= course_num; i++)
		fprintf(fp, "%-7s ", course_point[i].data);
	fprintf(fp, "\n");
	// 写入学生的 信息
	for (int i = 0; i < StudentNum; i++)
	{
		fprintf(fp, "%-10s %-6d", student_point[i].name, \
			student_point[i].Id);
		// 这个学生的成绩
		for (int z = 0; z <= course_num; z++)
			fprintf(fp, "%-7d ", student_point[i].score[z]);
		fprintf(fp, "\n");
	}
	printf("平均成绩已生成！！！");
	fclose(fp);
}

int main()
{
	//设置界面
	Welcome();
	return 0;
}