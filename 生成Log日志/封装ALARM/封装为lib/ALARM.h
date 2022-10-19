#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h> // linux下头文件
#endif
#define FILE_MAX_SIZE (1024*1024)

/* define the alarm level */
#define AL_DEBUG	1
#define AL_INFO		2
#define AL_WARNING	3
#define AL_ERROR	4

void get_local_time(char* buffer);
void get_local_date(char* buffer);
long get_file_size(char* filename);

void write_log_file(char* filename,long max_size, char* buffer, unsigned buf_size);
void ALARM(int alarm_class, int alarm_num,char* buffer);