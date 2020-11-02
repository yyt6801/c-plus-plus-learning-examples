#include <stdio.h>
int main()
{
    int Length = 10;                                  //需要排序的序列arr的长度
    int arr[Length] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0}; //这是需要排序的序列
    int temp;
    //第一个数为有序，其他数为无序
    for (int i = 1; i < Length; i++)
    {
        temp= arr[i];
        //依次和有序数做比较
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (int x = 0; x < Length; x++)
    {
        printf("%d\n", arr[x]);
    }
}