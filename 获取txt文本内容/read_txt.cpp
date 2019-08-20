// // //-------------------------------------------------------------------------------------
// //�?1 ok! �?fopen fgets 获取1.txt文本内�?�并打印出来,暂不能识�?�?�?
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX_LINE 1024
// int main()
// {
//  char buf[MAX_LINE];  /*缓冲�?*/
//  FILE *fp;            /*文件指针*/
//  int len;             /*行字符个�?*/
//  if((fp = fopen("1.txt","r")) == NULL)
//  {
//     perror("fail to read");
//     exit (1) ;
//  }
//  while(fgets(buf,MAX_LINE,fp) != NULL)
//  {
//     len = strlen(buf);
//     buf[len] = '\0';  /*去掉换�?��??*/
//     printf("%s",buf);
//  }
//   return 0;
// }


// //-------------------------------------------------------------------------------------
// //�?2 ok! �?fopen fseek fgets读取1.txt文本内�?�并打印
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// //函数返回fname指定文件的全部内容，如果打不开文件，则返回NULL，并显示打开文件错�?? 
// char *getfileall(char *fname)
// {
// 	FILE *fp;
// 	char *str;
// 	char txt[1000];
// 	int filesize;
// 	if ((fp=fopen(fname,"r"))==NULL){
// 		printf("打开文件%s错�?�\n",fname);
// 		return NULL;
// 	}
 
// 	fseek(fp,0,SEEK_END); 
 
// 	filesize = ftell(fp);
// 	str=(char *)malloc(filesize);
// 	str[0]=0;
 
// 	rewind(fp);
// 	while((fgets(txt,1000,fp))!=NULL){
// 		strcat(str,txt);
// 	}
// 	fclose(fp);
// 	return str;
// }
// int main(int argc, char *argv[])
// {
// 	char *p;
// 	char *fname="1.txt";
// 	p=getfileall(fname);
// 	if (p!=NULL) puts(p);
// 	return 0;
// }

//-----------------------------------------------------------------------------
//�?3 ok! �?ifstream   getline读取1.txt
#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    string a[100];              //采用 string 类型，存100行的文本，不要用数组 
    int i=0; 
    ifstream infile;
 
    infile.open("1.txt",ios::in);
 
    while(!infile.eof())            // 若未到文件结束一直循�? 
    {  
        getline(infile, a[i], '\n');//读取一行，以换行�?�结束，存入 a[] �?
        i++;                    //下一�?
    }
    for(int ii=0;ii<i;ii++)        // 显示读取的txt内�?? 
    {  
        cout<< a[ii] << endl;       
    }
 infile.close();
}