/*
    魔方阵，古代又称“纵横图”，是指组成元素为自然数1、2…n的平方的n×n的方阵，
    其中每个元素值都不相等，且每行、每列以及主、副对角线上各n个元素之和都相等。
    输入一个奇数，实现奇数魔方阵。

    附：奇数魔方阵的实现方法
            (1) 将1填入第一行中间；
        　　(2) 将每个数填在前一个数的右上方。
        　　(3) 若该位置超出最上行，则改填在最下行的对应位置；
        　　(4) 若该位置超出最右列，则该填在最左列的对应行位置；
        　　(5) 若某元素填在第一行最右列，下一个数填在该数同列的下一行；
　　        (6) 若某数已填好，但其右上角已填了其他数据，则下一个数填在该数同列的下一行位置。
*/

#include <stdio.h>
#include <math.h>
#include <iostream>

int main()
{
    int a[16][16],i,j,n,k;

    printf("Please input  n(1~15,it must be odd.): ");
    scanf("%d",&n);

    while( !(n>=1&&n<=15) || n%2==0 )
    {
        printf("The number is invalid.Please insert again:");
        scanf("%d",&n);
    }

    printf("\n");    //矩阵的初始化
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=0;

    j=n/2+1;
    a[1][j]=1;
    i=1;

    for(k=2;k<=n*n;k++)
    {
        i=i-1;
        j=j+1;

        if( i==0 && j==n+1 )
        {
            i=i+2;
            j=j-1;
        }
        else
        {
            if(i==0)
            {
                i=n;
            }
            if(j==n+1)
            {
                j=1;
            }
        }

        if(a[i][j]==0)
        {
            a[i][j]=k;
        }
        else
        {
            i=i+2;
            j=j-1;
            a[i][j]=k;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }

	system("pause");
    return 0;
}
