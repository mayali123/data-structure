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

// �ļ�ָ��
FILE* fp;
// ����γ̵�ָ��
course* course_point;
// ����ѧ����Ϣ��ָ��
stu* student_point;
// �γ̵�����
int course_num;
// ѧ��������
int StudentNum;
// ȫ�ֱ��� �γ�
int index;


void Welcome();		// �˵�
void over();		// ��ѡ�� ����ִ����֮��
void Course();		// ����γ����ֵĺ���
void Student();		// ����ѧ������Ϣ �ĺ���
void ReadFile();	// ��� ���е���Ϣ
void Search();		// ͨ�� ѧ�� or ���� ���в���
void DataAnalysis();// �Գɼ� ���з��� 
void Average();		// ƽ���ɼ� ����

// ��ӭ����
void Welcome()
{
	printf("**********************************************\n");
	printf("            ��ӭ�����ɼ�����ϵͳ              \n");
	printf("**********************************************\n");
	printf("             ����γ������밴1                \n");
	printf("             ����ѧ����Ϣ�밴2                \n");
	printf("             ���ɳɼ������밴3                \n");
	printf("            ��ʾ���ɵ������밴4               \n");
	printf("                ��ѯ�밴5                     \n");
	printf("                �˳��밴6                     \n");
	printf("**********************************************\n");
	printf("��������Ҫѡ��Ĺ��ܣ�");
	// �û�����key
	char InputKey;

	std::cin>>InputKey;
	// �������Է�ֹ�û������� ���� ��������
	char ch; while ((ch = getchar()) != '\n' && ch != EOF);
	
	switch (InputKey)
	{
	case   '1':
		Course();	// ����γ����ֵĺ���
		break;
	case  '2' :
		Student();	// ���� ѧ������Ϣ
		break;
	case '3':
		DataAnalysis(); // �Գɼ� ���� ���� ����
		break;
	case '4':
		ReadFile();		// ��ȡ �ɼ� ������
		break;
	case '5':
		Search();		// ����
		break;
	case '6':
		printf("�����˳�ϵͳ����ӭ�ٴ�ʹ��^.^\n");
		return;
		break;
	default:
		printf("�����ʽ��������������\n");
		Sleep(500);
		system("cls");
		Welcome();
		return;
	}
	over();
		
}


// ��ѡ�� ����ִ����֮��
void over()
{
	char InputKey;
	// ���� 
	printf("\n\n�Ƿ�ص��˵���������˳�����(y/q):");
	

	std::cin >> InputKey;

	if (InputKey == 'y' || InputKey == 'Y')
	{
		printf("����ˢ�£�����\n");
		Sleep(500);		// �ӳ� 500ms
		system("cls");  // ����
		Welcome();
	}
	else if (InputKey != 'q' && InputKey != 'Q')
	{
		printf("�����ʽ�������������룡");
		over();		
	}
}


// ����γ����ֵĺ���
void Course()
{
	int  i; 
	
	fopen_s(&fp, "input.dat", "w");  // ���ļ� ��д�ķ�ʽ��
	
	printf("������γ̵ĸ�����");
	scanf("%d", &course_num);		

	// ͨ����̬ ���� ���� �γ̵���Ϣ��  ����
	course_point = (course*)malloc(sizeof(course) * (course_num+1));
	
	//���һ������ ƽ���ɼ�
	strcpy(course_point[course_num].data ,"ƽ���ɼ�\0");
	
	fprintf(fp, "%-10s %-6s","����","ѧ��");	// д�� ���� �� ѧ��
	for (i = 0; i < course_num; i++)
	{
		printf("������γ̵����֣�");
		getchar();
		scanf("%s", &course_point[i].data);			// ����
		
		fprintf(fp, "%-7s ", course_point[i].data); // д�� �γ̵�����
	}
	fprintf(fp, "\n");
	fclose(fp);		// �ر� 
	printf("�γ���Ϣ������ϣ�����");
	
}


// ����ѧ������Ϣ �ĺ���
void Student()
{
		
	int  i,j, StudentId, StudentMark;	// ѧ��������      ѧ����ѧ��   ����
	
	fopen_s(&fp, "input.dat", "a");		// �� �ɼ������� ��׷�ӵķ�ʽ ��

	printf("������ѧ����������");
	scanf("%d", &StudentNum);			

	//ͨ����̬ ���� ����ѧ�� ��Ϣ������
	student_point =(stu*) malloc(sizeof(stu) * StudentNum);

	for (i = 0; i < StudentNum; i++)
	{
		// ����ѧ�������ֺ�ѧ��
		printf("������ѧ����������");
		scanf("%s", student_point[i].name);
		printf("������%s��ѧ�ţ�", student_point[i].name);
		scanf("%d", &student_point[i].Id);

		// ���ļ���д�� ������ ѧ��
		fprintf(fp,"%-10s %-6d", student_point[i].name, student_point[i].Id);

		// ͨ����̬ ���� ����ѧ�� �ɼ� ������
		student_point[i].score =(int*) malloc(sizeof(int) * (course_num+1));

		int num = 0;	// ���� ���γ̵� ���гɼ�

		// ������Ƶĳɼ�
		for(j=0;j<course_num ;j++)
		{ 
			printf("������%s %s�γ̵ĳɼ���", student_point[i].name,course_point[j].data);
			scanf("%d",&student_point[i].score[j]);
			// ���ļ���д�� �ɼ�
			fprintf(fp, "%-7d ", student_point[i].score[j]);
			num += student_point[i].score[j];
		}
		// ���� ƽ���ɼ� 
		student_point[i].score[course_num] = num / course_num;
		fprintf(fp, "\n");
	}
	//�ر��ļ�
	fclose(fp);
	printf("ѧ����Ϣ������ϣ�����");
	
}

// ��ȡ�ļ�
void ReadFile()
{
	int i, num;
	char path[100],ch[1000];				// path �����ļ���·��
	printf("�Ѿ����ɵ��ļ���\n");
	// ���� ��ȡ�ѱ��� ����Ϣ
	for (i = 0; i <= course_num; i++)
	{
		printf("\t%d.%s������.dat\n",i,course_point[i].data);
	}
	printf("������Ҫ�鿴���ļ���");
	scanf("%d",&num);
	if (0 <= num && num <= course_num)
	{
		strcpy(path, course_point[num].data);// ���� path
		strcat(path,"������.dat\0");

		fopen_s(&fp, path, "r");			//�� path�ļ� ��ֻ���ķ�ʽ��
		printf("\n\n�� %s\n",path);
		
		while (!feof(fp))					// ���ļ�ָ�� ������ �ļ�ĩβʱ
		{
			if (fgets(ch, 1000, fp)!=NULL)
				printf("%s",ch);
		}
		fclose(fp);							// �ر��ļ�
	}
}

// ����
//void Search()
//{
//	int i = 0, StudentId,SearchId,Select,IsFind=0, IsFirst=1;
//	char ch[1000],StudentName[20],SearchName[20],info[1000]; // ���� ���� �������Ϣ
//
//	fopen_s(&fp, "input.dat", "r");			// ���ļ� ��ֻ���ķ�ʽ ��
//
//	printf("��ѡ����������(��1) ����ѧ��(��2) ����");
//	scanf("%d",&Select);
//	if (Select == 1)
//	{
//		printf("\n������ Ҫ������֣�");
//		scanf("%s",SearchName);
//	}
//	else if (Select == 2)
//	{
//		printf("\n������ Ҫ���ѧ�ţ�");
//		scanf("%d", &SearchId);
//	}
//	else
//	{
//		printf("�����ʽ���󣡣�������������\n");
//		Search();
//		return;
//	}
//	fgets(info, 1000, fp);					// ���� �γ� ��Ϣ 
//	
//
//	while (!feof(fp))						// ���ļ�ָ�� ������ �ļ�ĩβʱ
//	{
//		fscanf(fp,"%s %d",StudentName,&StudentId);
//		if (fgets(ch, 1000, fp) != NULL)	// ��ȡ����� �γ� ��Ϣ
//		{
//			// ͨ�����������ҵ���
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
//			printf("δ�ҵ�����Ϊ%s��ѧ��\n", SearchName);
//		else
//			printf("δ�ҵ�ѧ��Ϊ%d��ѧ��\n", SearchId);
//	}
//	// �ر��ļ�
//	fclose(fp);
//}

void Search()
{
	int i = 0, StudentId, SearchId, Select, IsFind = 0, IsFirst = 1;
	char ch[1000], StudentName[20], SearchName[20], info[1000]; // ���� ���� �������Ϣ

	fopen_s(&fp, "input.dat", "r");			// ���ļ� ��ֻ���ķ�ʽ ��

	printf("��ѡ����������(��1) ����ѧ��(��2) ����");
	scanf("%d", &Select);
	if (Select == 1)
	{
		printf("\n������ Ҫ������֣�");
		scanf("%s", SearchName);
	}
	else if (Select == 2)
	{
		printf("\n������ Ҫ���ѧ�ţ�");
		scanf("%d", &SearchId);
	}
	else
	{
		printf("�����ʽ���󣡣�������������\n");
		Search();
		return;
	}
	//fgets(info, 1000, fp);					// ���� �γ� ��Ϣ 

	for (int i = 0; i < StudentNum; i++)
	{
		if ((Select == 1 && strcmp(SearchName, student_point[i].name) == 0) || (Select == 2 && student_point[i].Id == SearchId))
		{
			IsFind = 1;
			if (IsFirst)
			{
				printf(" % -10s %-6s","����","ѧ��");
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
	// δ�ҵ�ʱ
	if (IsFind == 0)
	{
		if (Select == 1)
			printf("δ�ҵ�����Ϊ%s��ѧ��\n", SearchName);
		else
			printf("δ�ҵ�ѧ��Ϊ%d��ѧ��\n", SearchId);
	}
	// �ر��ļ�
	fclose(fp);
}

// ���sort ʹ�õıȽϺ���
int cmp(stu a, stu b)
{
	return a.score[index]>b.score[index];
}

// ���ݷ���
void DataAnalysis()
{
	for (index = 0; index < course_num; index++)
	{
		std::sort(student_point, student_point + StudentNum,cmp);
		char ch[20] = "������.dat\0";
		char path[50];		// path �����ļ���·��
		//�� path�ļ� ��ֻ���ķ�ʽ��
		strcpy(path, course_point[index].data);
		strcat(path,ch);
		
		fopen_s(&fp, path,"w");
		// д��  ���� ѧ�� �γ̵�����
		fprintf(fp,"%-10s %-6s%-7s\n","����","ѧ��", course_point[index].data);
		// num ��ȫ���ĳɼ� num1 �ǲ���������  num2��60-69������
		// num3��70-79������ num4 �� 80-89������ num5 �� 90������
		int min = student_point[StudentNum-1].score[index],\
			max= student_point[0].score[index],num=0,num1=0,num2=0,num3=0,num4=0,num5=0;
		// ѧ�� �ɼ�
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
		printf("%s�����ɣ�����\n",path);

		fprintf(fp,"\n\n�ɼ������ݷ�����\nƽ���ɼ�=%.2f\t��߷�=%d\t��ͷ�=%d\n\
����������=%d\t60-69������=%d\t70-79������=%d\n\
80-89������=%d\t90����������=%d\n",1.0*num/ StudentNum,max,min,num1,num2,num3,num4,num5);
		
		
		fclose(fp);
	}
	// ����ƽ���ɼ�
	Average();
}


// ƽ���ɼ� ����
void Average()
{
	// ���ļ�
	fopen_s(&fp, "ƽ���ɼ�������.dat", "w");

	std::sort(student_point, student_point + StudentNum, cmp); //�ṹ�������

	fprintf(fp, "%-10s %-6s", "����", "ѧ��");
	// д�� �γ̵�����
	for (int i = 0; i <= course_num; i++)
		fprintf(fp, "%-7s ", course_point[i].data);
	fprintf(fp, "\n");
	// д��ѧ���� ��Ϣ
	for (int i = 0; i < StudentNum; i++)
	{
		fprintf(fp, "%-10s %-6d", student_point[i].name, \
			student_point[i].Id);
		// ���ѧ���ĳɼ�
		for (int z = 0; z <= course_num; z++)
			fprintf(fp, "%-7d ", student_point[i].score[z]);
		fprintf(fp, "\n");
	}
	printf("ƽ���ɼ������ɣ�����");
	fclose(fp);
}

int main()
{
	//���ý���
	Welcome();
	return 0;
}