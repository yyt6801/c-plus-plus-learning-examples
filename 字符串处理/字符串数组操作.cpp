//字符串数组初始化：
//错误：memset(s, 0, sizeof(s));如果是指针，动态申请的空间，就不要使用sizeof(s)了。因为sizeof(s)的结果是4.不是想要的值，你的需求是对数组或结构体都可以这样初始化或重新赋值。
// char s[200]={0};
//正确： memset(s,0,200);


//ok!字符串数组定义： 每个字符串长度为1024，数组共有100个元素
// char a[100][1024];
// strcpy( a[0], "sample_1" );
// strcpy( a[2], "sample_2" );
// 100  = number of elements (strings) in the array;
// 1024 = the size of each string element


// char *a[10];
// a=(char*)malloc(sizeof(strlen(string)*char));
// a=string;

//ok!  
// char *str1="nihao";
// char *str2="hello";
// char *array[5];
// array[0]=str1;//注意：这里不能用：strcpy(array[0],*str1);哦！！
// array[1]=str2;