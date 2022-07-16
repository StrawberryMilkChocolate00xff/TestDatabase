#include "lib.h"
#pragma once

class ReadLib
{
public:
	ReadLib();						//进行初始化，并且验证默认文件
	~ReadLib();						//结束类的运行

	bool The_Info_Init(FILE *fp);	//让用户填写数据库的基本信息到默认文件，在第一次使用数据库或者重置数据库时使用
	bool Read_The_Lib_Info(FILE *fp);
private:
	//数据库的基本信息
	char Name_Of_Lib[101];				//数据库的名称，不超过100字节
	char Password_Of_Lib[17];			//数据库的密码
};

/*
默认文件的文件架构：
[数据库名称]：用户填写
[数据库密码]：用户填写，填写后系统自动加密，且位数为：8~16位密码

[数据库创建时间]：系统自动填写
[数据库项目总个数]：系统自动填写
*/