#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
char *FormateString(const char *fmt, ...) 
{
    /* 初始时假设我们只需要不超过100字节大小的空间 */
    int n, size = 100;
    char *p;
    va_list ap;
    if ( (p = (char *) malloc(size*sizeof(char))) == NULL)
    return NULL;
    while (1) 
    {
        /* 尝试在申请的空间中进行打印操作 */
        va_start(ap, fmt);
        n = vsnprintf (p, size, fmt, ap);
        va_end(ap);
        /* 如果vsnprintf调用成功，返回该字符串 */
        if (n > -1 && n < size)
        return p;
        /* vsnprintf调用失败(n<0)，或者p的空间不足够容纳size大小的字符串(n>=size)，尝试申请更大的空间*/
        size *= 2; /* 两倍原来大小的空间 */
        if ((p = (char *)realloc(p, size*sizeof(char))) == NULL)
        return NULL;
    }
}
int main() 
{
    /* 调用上面的函数 */
    char* str = FormateString("%d,%d,%d,%d",5,6,7,8);
    printf("%s\n",str);
    free(str);
    /* we allocate the memory in the make_message function, so we should release it by caller(main function). */
    return 0;
}