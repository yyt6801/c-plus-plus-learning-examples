#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
int main(){
	LPTSTR lpPath = new char[MAX_PATH];
	LPTSTR LiMingSex = new char[6];
	int LiMingAge;
	LPTSTR FangfangSex = new char[6];
	int FangfangAge;


	strcpy(lpPath, ".//111.ini");

	GetPrivateProfileString("LiMing", "Sex", "", LiMingSex, 6, lpPath);
	LiMingAge = GetPrivateProfileInt("LiMing", "Age", 0, lpPath);

	GetPrivateProfileString("Fangfang", "Sex", "", FangfangSex, 6, lpPath);
	FangfangAge = GetPrivateProfileInt("Fangfang", "Age", 0, lpPath);


	delete [] lpPath;


	cout<<"获取INI文件LiMingSex的值为："<<LiMingSex<<endl;
	cout<<"获取INI文件LiMingAge的值为："<<LiMingAge<<endl;
	cout<<"获取INI文件FangfangSex的值为："<<FangfangSex<<endl;
	cout<<"获取INI文件FangfangAge的值为："<<FangfangAge<<endl;

	system("pause");

}