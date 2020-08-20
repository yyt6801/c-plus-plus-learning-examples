// // //-------------------------------------------------------------------------------------
// // ok! fopen fgets  1.txt
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX_LINE 1024
// int main()
// {
//  char buf[MAX_LINE];  /*»º³å*/
//  FILE *fp;            /*ÎÄ¼þÖ¸Õë*/
//  int len;             
//  if((fp = fopen("1.txt","r")) == NULL)
//  {
//     perror("fail to read");
//     exit (1) ;
//  }
//  while(fgets(buf,MAX_LINE,fp) != NULL)
//  {
//     len = strlen(buf);
//     buf[len] = '\0';  
//     printf("%s",buf);
//  }
//   return 0;
// }


// //-------------------------------------------------------------------------------------
// //Àý2 ok!  fopen fseek fgets 1.txt 
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// char *getfileall(char *fname)
// {
// 	FILE *fp;
// 	char *str;
// 	char txt[1000];
// 	int filesize;
// 	if ((fp=fopen(fname,"r"))==NULL){
// 		printf("Î´ÕÒµ½%s\n",fname);
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
//Àý3 ok!  ifstream   getline  1.txt
#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    string a[100];               
    int i=0; 
    ifstream infile;
 
    infile.open("1.txt",ios::in);
 
    while(!infile.eof())           
    {  
        getline(infile, a[i], '\n');
        i++;                   
    }
    
    cout<< *a << endl;   
    infile.close();
}