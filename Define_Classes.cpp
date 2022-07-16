#include "Lib.h"
#include "Classes.h"

extern int errno;

//定义ReadLib类中的构造函数
#ifdef StrawberryMilkChocolate
ReadLib::ReadLib()
{
	//读取默认文件的FILE流
	FILE *Default_File_Read;

	//试图加载默认文件
	Default_File_Read = fopen(".\\DefaultData", "r");
	if (NULL == Default_File_Read)
	{
		//判断错误原因
		if (2 == errno)	//为2，说明只是没有创建文件而已
		{
			//因为文件没有被创建，所以准备创建默认文件
			Default_File_Read = fopen("./DefaultData", "w");
			if (NULL == Default_File_Read)
			{
				//创建失败，输出错误
				perror("试图创建默认文件失败，错误原因");
				fclose(Default_File_Read);
			}
			else
			{
				//创建成功，让用户填写数据库的基本信息
				The_Info_Init(Default_File_Read);
				return;
			}
		}
		else
		{
			//输出错误原因
			perror("试图读取默认文件失败，错误原因");
			fclose(Default_File_Read);
			return;
		}
	}
	else
	{
		//加载默认文件成功
		Read_The_Lib_Info(Default_File_Read);
	}
}
#endif

//定义ReadLib类中的The_Info_Init()函数，用于初始化数据库
#ifdef StrawberryMilkChocolate
bool ReadLib::The_Info_Init(FILE *fp)
{
	//打开文件
	fp = fopen(".\\DefaultData", "w");
	if (NULL == fp)
	{
		perror("试图创建默认文件失败，错误原因");
		return false;
	}
	else
	{
		//成功创建默认文件，开始写入默认文件，既默认文件初始化
		printf("请输入数据库的名称：");
		scanf_s("%s", Name_Of_Lib, 101);
		int len;
		do
		{
			printf("请输入数据库的密码（位数在8到16位）：");
			scanf_s("%s", Password_Of_Lib, 17);
			len = strlen(Password_Of_Lib);
		} while (len > 9 && len < 17);

		//将数据写入到默认文件中
		char Name[101];
		char Password[17];

		sprintf(Name, "%s\n", Name_Of_Lib);
		sprintf(Password, "%s\n", Password_Of_Lib);
		
		fputs(Name, fp);
		fputs(Password, fp);
		fclose(fp);
	}
	//初始化完成
	return true;
}
#endif

//定义Read_the_Lib_Info()函数，既读取默认文件
#ifdef StrawberryMilkChocolate
bool ReadLib::Read_The_Lib_Info(FILE *fp)
{
	fp = fopen(".\\DefaultData", "r");
	if (NULL == fp)
	{
		perror("尝试读取默认文件数据失败，错误原因");
		fclose(fp);
		return false;
	}
	else
	{
		//开始读取

		fgets(Name_Of_Lib, 101, fp);
		fgets(Password_Of_Lib, 17, fp);
		fclose(fp);
		printf("加载数据库成功!\n");
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