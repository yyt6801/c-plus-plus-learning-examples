# include <string.h>
# include <stdio.h>
 
void split(char *src,const char *separator,char **dest,int *num) {
	/*
		src 源字符串的首地址(buf的地址) 
		separator 指定的分割字符
		dest 接收子字符串的数组
		num 分割后子字符串的个数
	*/
     char *pNext;
     int count = 0;
     if (src == NULL || strlen(src) == 0) //如果传入的地址为空或长度为0，直接终止 
        return;
     if (separator == NULL || strlen(separator) == 0) //如未指定分割的字符串，直接终止 
        return;
     pNext = (char *)strtok(src,separator); //必须使用(char *)进行强制类型转换(虽然不写有的编译器中不会出现指针错误)
     while(pNext != NULL) {
          *dest++ = pNext;
          ++count;
         pNext = (char *)strtok(NULL,separator);  //必须使用(char *)进行强制类型转换
    }  
    *num = count;
} 	
 
int main(){
	int i;
	char buf[]="Tag1=34&Tag2=556";
	//用来接收返回数据的数组。这里的数组元素只要设置的比分割后的子字符串个数大就好了。
	char *revbuf[8] = {0}; //存放分割后的子字符串 
	
	//分割后子字符串的个数
	int num = 0;
	
	split(buf,"&",revbuf,&num); //调用函数进行分割 
	
	
	//输出返回的每个内容 
	for(i = 0;i < num; i ++) {
		//lr_output_message("%s\n",revbuf[i]);
		printf("%s\n",revbuf[i]);
	}
 
 
	return 0;
}
