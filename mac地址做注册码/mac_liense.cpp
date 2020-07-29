#include <stdio.h>

#include<iostream>

using namespace std;

/*///////////////////////////////////

// MAC: 45:b5:64:d3:53:7a

//        \ \      / /

//              x

//        / /      \ \

//p[i]: 7a 53 d3 64 b5 45 00 00

//  i:  0  1  2  3  4  5  6  7

printf("0x%016I64x\n",macnum);

//        ||||||^---按十六进制小写abcdef输出

//        |||^^^----__int64类型的数

//        |^^-------宽度16

//        ^---------左边补0

printf("%I64u\n",macnum);

//          ^--------按unsigned类型输出

//      ^^^---------__int64类型的数

*///////////////////////////////////////

__int64 getMacNum(string strMAC)

{

     __int64 macnum;  
     unsigned char *p;    
     p=(unsigned char *)&macnum;    
     p[6]=0;    
     p[7]=0;int i,v;    
     char MAC[17];  
     for(i=0;i<17;i++)  
     {  
         MAC[i] = strMAC[i];    
     }  
     for (i=0;i<6;i++)  
     {

        sscanf(MAC+i*3,"%2x",&v);   
        p[5-i]=(unsigned char)v;    
    }   
    return macnum;

}

int main()

{

string strMAC = "44-8A-5B-BF-81-23";

__int64 intMac = getMacNum(strMAC);
cout<<intMac<<endl;

return 0;

}
