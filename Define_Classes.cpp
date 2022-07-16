#include "Lib.h"
#include "Classes.h"

extern int errno;

//����ReadLib���еĹ��캯��
#ifdef StrawberryMilkChocolate
ReadLib::ReadLib()
{
	//��ȡĬ���ļ���FILE��
	FILE *Default_File_Read;

	//��ͼ����Ĭ���ļ�
	Default_File_Read = fopen(".\\DefaultData", "r");
	if (NULL == Default_File_Read)
	{
		//�жϴ���ԭ��
		if (2 == errno)	//Ϊ2��˵��ֻ��û�д����ļ�����
		{
			//��Ϊ�ļ�û�б�����������׼������Ĭ���ļ�
			Default_File_Read = fopen("./DefaultData", "w");
			if (NULL == Default_File_Read)
			{
				//����ʧ�ܣ��������
				perror("��ͼ����Ĭ���ļ�ʧ�ܣ�����ԭ��");
				fclose(Default_File_Read);
			}
			else
			{
				//�����ɹ������û���д���ݿ�Ļ�����Ϣ
				The_Info_Init(Default_File_Read);
				return;
			}
		}
		else
		{
			//�������ԭ��
			perror("��ͼ��ȡĬ���ļ�ʧ�ܣ�����ԭ��");
			fclose(Default_File_Read);
			return;
		}
	}
	else
	{
		//����Ĭ���ļ��ɹ�
		Read_The_Lib_Info(Default_File_Read);
	}
}
#endif

//����ReadLib���е�The_Info_Init()���������ڳ�ʼ�����ݿ�
#ifdef StrawberryMilkChocolate
bool ReadLib::The_Info_Init(FILE *fp)
{
	//���ļ�
	fp = fopen(".\\DefaultData", "w");
	if (NULL == fp)
	{
		perror("��ͼ����Ĭ���ļ�ʧ�ܣ�����ԭ��");
		return false;
	}
	else
	{
		//�ɹ�����Ĭ���ļ�����ʼд��Ĭ���ļ�����Ĭ���ļ���ʼ��
		printf("���������ݿ�����ƣ�");
		scanf_s("%s", Name_Of_Lib, 101);
		int len;
		do
		{
			printf("���������ݿ�����루λ����8��16λ����");
			scanf_s("%s", Password_Of_Lib, 17);
			len = strlen(Password_Of_Lib);
		} while (len > 9 && len < 17);

		//������д�뵽Ĭ���ļ���
		char Name[101];
		char Password[17];

		sprintf(Name, "%s\n", Name_Of_Lib);
		sprintf(Password, "%s\n", Password_Of_Lib);
		
		fputs(Name, fp);
		fputs(Password, fp);
		fclose(fp);
	}
	//��ʼ�����
	return true;
}
#endif

//����Read_the_Lib_Info()�������ȶ�ȡĬ���ļ�
#ifdef StrawberryMilkChocolate
bool ReadLib::Read_The_Lib_Info(FILE *fp)
{
	fp = fopen(".\\DefaultData", "r");
	if (NULL == fp)
	{
		perror("���Զ�ȡĬ���ļ�����ʧ�ܣ�����ԭ��");
		fclose(fp);
		return false;
	}
	else
	{
		//��ʼ��ȡ

		fgets(Name_Of_Lib, 101, fp);
		fgets(Password_Of_Lib, 17, fp);
		fclose(fp);
		printf("�������ݿ�ɹ�!\n");
		return true;
	}
}
#endif

#ifdef StrawberryMilkChocolate
ReadLib::~ReadLib()
{
	return;
}
#endif