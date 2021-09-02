// FileOperationDemo.cpp : Defines the entry point for the console application.

#include <tchar.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	BOOL ret;
	LPCWSTR filePath1 = _T("U:\\test\\111.txt");
	LPCWSTR filePath2 = _T("U:\\test2\\222.txt");
	LPCWSTR dirPath1 = _T("U:\\test");
	LPCWSTR dirPath2 = _T("U:\\test2");

	//ok---创建文件夹
	char a[] = "C:\\TEST123";
	WCHAR wsz[64];
	swprintf(wsz, 100, L"%S", a);
	LPCWSTR m_szFilename = wsz;
	if (CreateDirectory(m_szFilename, NULL)) {
	    // If the function succeeds, the return value is nonzero.
	    printf("Create a new directory succeeds. \n");
	}
	else {
	    // If the function fails, the return value is zero. 
	    // To get extended error information, call GetLastError.
	    // Possible errors include the following.
	    switch (GetLastError())
	    {
	    case ERROR_ALREADY_EXISTS:
	        printf("The specified directory already exists!");
	        break;
	    case ERROR_PATH_NOT_FOUND:
	        printf("One or more intermediate directories do not exist!");
	        break;
		}
	}


	char file1[] = "C:\\2021-09-01\\2021-09-01-09-19-30.wav";
	char file2[] = "U:\\2021-09-01\\2021-09-01-09-19-30.wav";
	WCHAR wfile1[64], wfile2[64];
	swprintf(wfile1, 100, L"%S", file1);
	swprintf(wfile2, 100, L"%S", file2);
	LPCWSTR m_szfile1 = wfile1, m_szfile2 = wfile2;
	/*
	复制文件
	BOOL WINAPI CopyFile(
	_In_ LPCTSTR lpExistingFileName,
	_In_ LPCTSTR lpNewFileName,
	_In_ BOOL    bFailIfExists
	);
	return 失败返回0,成功返回非0。
	*/
	ret = CopyFile(m_szfile1, m_szfile2, true);
	if (ret == 0) {
		printf("CopyFile fail(%d)\n", GetLastError());
	}
	else {
		printf("CopyFile -> %d\n", ret);
	}
	/*
	创建文件
	HANDLE CreateFile(
	LPCTSTR lpFileName, //指向文件名的指针
	DWORD dwDesiredAccess, //访问模式（写/读）, 如果为 GENERIC_READ 表示允许对设备进行读访问；如果为 GENERIC_WRITE 表示允许对设备进行写访问（可组合使用）；如果为零，表示只允许获取与一个设备有关的信息
	DWORD dwShareMode, //共享模式, 0表示不共享； FILE_SHARE_READ 和/或 FILE_SHARE_WRITE 表示允许对文件进行共享访问
	LPSECURITY_ATTRIBUTES lpSecurityAttributes, //指向一个SECURITY_ATTRIBUTES安全属性结构的指针，定义了文件的安全特性（如果操作系统支持的话）,默认为0
	DWORD dwCreationDisposition, //如何创建
	DWORD dwFlagsAndAttributes, //文件属性
	HANDLE hTemplateFile //用于复制文件句柄, 如果不为零，则指定一个文件句柄。新文件将从这个文件中复制扩展属性
	);

	dwDesiredAccess Long，下述常数之一：
	#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
	FILE_READ_DATA           |\
	FILE_READ_ATTRIBUTES     |\
	FILE_READ_EA             |\
	SYNCHRONIZE)
	#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
	FILE_WRITE_DATA          |\
	FILE_WRITE_ATTRIBUTES    |\
	FILE_WRITE_EA            |\
	FILE_APPEND_DATA         |\
	SYNCHRONIZE)
	#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
	FILE_READ_ATTRIBUTES     |\
	FILE_EXECUTE             |\
	SYNCHRONIZE)

	dwCreationDisposition Long，下述常数之一：
	CREATE_NEW 创建文件；如文件存在则会出错
	CREATE_ALWAYS 创建文件，会改写前一个文件
	OPEN_EXISTING 文件必须已经存在。由设备提出要求
	OPEN_ALWAYS 如文件不存在则创建它
	TRUNCATE_EXISTING 将现有文件缩短为零长度

	dwShareMode Long，下述常数之一：
	#define FILE_SHARE_READ                 0x00000001
	#define FILE_SHARE_WRITE                0x00000002
	#define FILE_SHARE_DELETE               0x00000004

	dwFlagsAndAttributes Long， 一个或多个下述常数
	FILE_ATTRIBUTE_ARCHIVE 标记归档属性
	FILE_ATTRIBUTE_COMPRESSED 将文件标记为已压缩，或者标记为文件在目录中的默认压缩方式
	FILE_ATTRIBUTE_NORMAL 默认属性
	FILE_ATTRIBUTE_HIDDEN 隐藏文件或目录
	FILE_ATTRIBUTE_READONLY 文件为只读
	FILE_ATTRIBUTE_SYSTEM 文件为系统文件
	FILE_FLAG_WRITE_THROUGH 操作系统不得推迟对文件的写操作
	FILE_FLAG_OVERLAPPED 允许对文件进行重叠操作
	FILE_FLAG_NO_BUFFERING 禁止对文件进行缓冲处理。文件只能写入磁盘卷的扇区块
	FILE_FLAG_RANDOM_ACCESS 针对随机访问对文件缓冲进行优化
	FILE_FLAG_SEQUENTIAL_SCAN 针对连续访问对文件缓冲进行优化
	FILE_FLAG_DELETE_ON_CLOSE 关闭了上一次打开的句柄后，将文件删除。特别适合临时文件
	*/
	//////////DWORD dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
	//////////DWORD dwShareMode = 0;
	//////////LPSECURITY_ATTRIBUTES lpSecurityAttributes = 0;
	//////////DWORD dwCreationDisposition = CREATE_NEW;
	//////////DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
	//////////HANDLE hTemplateFile = 0;
	//////////HANDLE handle = CreateFile(filePath1, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	//////////printf("CreateFile -> HANDLE=0x%x\n", (unsigned int)handle);

	//////////if (handle != INVALID_HANDLE_VALUE) {

	//////////	FILETIME fCreationTime, fLastAccessTime, fLastWriteTime;
	//////////	// GetFileTime函数用来获得一个文件或目录的创建的时间、最后访问的时间以及最后修改的时间
	//////////	ret = GetFileTime(handle, &fCreationTime, &fLastAccessTime, &fLastWriteTime);
	//////////	if (ret == 0) {
	//////////		printf("GetFileTime fail(%d)\n", GetLastError());
	//////////	}
	//////////	else {
	//////////		printf("GetFileTime -> %d\n", ret);
	//////////	}

	//////////	/*
	//////////	根据一个FILETIME结构的内容，装载一个SYSTEMTIME结构。
	//////////	WINBASEAPI _Success_(return != FALSE) BOOL WINAPI FileTimeToSystemTime(
	//////////	_In_ CONST FILETIME * lpFileTime,
	//////////	_Out_ LPSYSTEMTIME lpSystemTime
	//////////	);
	//////////	*/
	//////////	SYSTEMTIME sysCreationTime, sysLastAccessTime, sysLastWriteTime;
	//////////	ret = FileTimeToSystemTime(&fCreationTime, &sysCreationTime);
	//////////	if (ret == 0) {
	//////////		printf("FileTimeToSystemTime creationTime fail(%d)\n", GetLastError());
	//////////	}
	//////////	else {
	//////////		printf("FileTimeToSystemTime creationTime -> %d\n", ret);
	//////////		printf("%4d年%2d月%2d日,%2d:%2d:%2d\n", sysCreationTime.wYear, sysCreationTime.wMonth, sysCreationTime.wDay, sysCreationTime.wHour, sysCreationTime.wMinute, sysCreationTime.wSecond);
	//////////	}
	//////////	ret = FileTimeToSystemTime(&fLastAccessTime, &sysLastAccessTime);
	//////////	if (ret == 0) {
	//////////		printf("FileTimeToSystemTime lastAccessTime fail(%d)\n", GetLastError());
	//////////	}
	//////////	else {
	//////////		printf("FileTimeToSystemTime lastAccessTime -> %d\n", ret);
	//////////		printf("%4d年%2d月%2d日,%2d:%2d:%2d\n", sysLastAccessTime.wYear, sysLastAccessTime.wMonth, sysLastAccessTime.wDay, sysLastAccessTime.wHour, sysLastAccessTime.wMinute, sysLastAccessTime.wSecond);
	//////////	}
	//////////	ret = FileTimeToSystemTime(&fLastWriteTime, &sysLastWriteTime);
	//////////	if (ret == 0) {
	//////////		printf("FileTimeToSystemTime lastWriteTime fail(%d)\n", GetLastError());
	//////////	}
	//////////	else {
	//////////		printf("FileTimeToSystemTime lastWriteTime -> %d\n", ret);
	//////////		printf("%4d年%2d月%2d日,%2d:%2d:%2d\n", sysLastWriteTime.wYear, sysLastWriteTime.wMonth, sysLastWriteTime.wDay, sysLastWriteTime.wHour, sysLastWriteTime.wMinute, sysLastWriteTime.wSecond);
	//////////	}

	//////////	//用完要记得关闭,否则其他操作会失败,GetLastError()=32 => 进程无法访问文件，因为另一个程序正在使用此文件。
	//////////	CloseHandle(handle);
	//////////}

	

	/*
	删除文件
	BOOL DeleteFile(
	LPCSTRlpFileName//要删除的文件名的指针
	);
	return 失败返回0,成功返回非0。如果程序尝试删除一个不存在的文件。GetLastError返回ERROR_FILE_NOT_FOUND。如果文件是只读 的，则GetLastError返回ERROR_ACCESS_DENIED
	*/
	ret = DeleteFile(filePath1);
	if (ret == 0) {
		printf("DeleteFile fail(%d)\n", GetLastError());
	}
	else {
		printf("DeleteFile -> %d\n", ret);
	}

	/*
	移动一个存在的文件或者目录(包括子目录)
	WINBASEAPI BOOL WINAPI MoveFileW(
	_In_ LPCWSTR lpExistingFileName,
	_In_ LPCWSTR lpNewFileName
	);
	return 失败返回0,成功返回非0。
	*/
	//////////ret = MoveFile(filePath2, filePath1);
	//////////if (ret == 0) {
	//////////	printf("MoveFile fail(%d)\n", GetLastError());
	//////////}
	//////////else {
	//////////	printf("MoveFile -> %d\n", ret);
	//////////}

	/*
	WINBASEAPI DWORD WINAPI GetFileAttributesW(
	_In_ LPCWSTR lpFileName
	);

	#define FILE_ATTRIBUTE_READONLY             0x00000001
	#define FILE_ATTRIBUTE_HIDDEN               0x00000002
	#define FILE_ATTRIBUTE_SYSTEM               0x00000004
	#define FILE_ATTRIBUTE_DIRECTORY            0x00000010
	#define FILE_ATTRIBUTE_ARCHIVE              0x00000020
	#define FILE_ATTRIBUTE_DEVICE               0x00000040
	#define FILE_ATTRIBUTE_NORMAL               0x00000080
	#define FILE_ATTRIBUTE_TEMPORARY            0x00000100
	#define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200
	#define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400
	#define FILE_ATTRIBUTE_COMPRESSED           0x00000800
	#define FILE_ATTRIBUTE_OFFLINE              0x00001000
	#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000
	#define FILE_ATTRIBUTE_ENCRYPTED            0x00004000
	#define FILE_ATTRIBUTE_INTEGRITY_STREAM     0x00008000
	#define FILE_ATTRIBUTE_VIRTUAL              0x00010000
	#define FILE_ATTRIBUTE_NO_SCRUB_DATA        0x00020000
	#define FILE_ATTRIBUTE_EA                   0x00040000
	*/
////////////	/*DWORD attr = GetFileAttributes(filePath1);
////////////	if (attr == INVALID_FILE_ATTRIBUTES) {
////////////		printf("GetFileAttributes fail(%d)", GetLastError());
////////////	}
////////////	else {
////////////		printf("GetFileAttributes -> 0x%x\n", attr);
////////////	}
////////////
////////////	DeleteFile(filePath1);
////////////*/
	/*
	创建文件夹（注意: 目录没有复制操作）
	WINBASEAPI BOOL WINAPI CreateDirectoryW(
	_In_ LPCWSTR lpPathName,
	_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes
	);
	return 失败返回0,成功返回非0。
	*/
	////////////ret = CreateDirectory(dirPath1, 0);
	////////////if (ret == 0) {
	////////////	printf("CreateDirectory fail(%d)\n", GetLastError());
	////////////}
	////////////else {
	////////////	printf("CreateDirectory -> %d\n", ret);
	////////////}

	/*
	删除目录（注意：目录必须为空，否则会报145错误）
	WINBASEAPI BOOL WINAPI RemoveDirectoryW(
	_In_ LPCWSTR lpPathName
	);
	*/
	////////////ret = RemoveDirectory(dirPath1);
	////////////if (ret == 0) {
	////////////	printf("RemoveDirectory fail(%d)\n", GetLastError());
	////////////}
	////////////else {
	////////////	printf("RemoveDirectory -> %d\n", ret);
	////////////}

	system("pause");
	return 0;
}