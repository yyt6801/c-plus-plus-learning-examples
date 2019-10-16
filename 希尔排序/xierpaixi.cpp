#include <stdio.h>
int main()
{
    int Length = 10;                                  //需要排序的序列arr的长度
    int arr[Length] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0}; //这是需要排序的序列
    //gap为一个增量，增量的求法为：数组的长度除以2，得到一个gap值，然后再用gap除以2，直到为1，这几个结果
    //称为增量（如果结果为小数，则向下取整，增量也是步长）
    for (int gap = Length / 2; gap >= 1; gap = gap / 2)
    {
        //每个增加都把相应的数放在一个组里，进行直接插入排序。
        for (int i = gap; i < Length; i++)
        {
            int temp = arr[i];
            for (int j = i; j >= gap && arr[j] < arr[j - gap]; j = j - gap)
            {
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
    for (int x = 0; x < Length; x++)
    {
        printf("%d\n", arr[x]);
    }
}