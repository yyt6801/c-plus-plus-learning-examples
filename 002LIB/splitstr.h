
#ifndef _SPLITSTR_H_
#define _SPLITSTR_H_

#pragma warning(push)

class CSPLITSTR
{
public:
	//
	// 去除前后非法字符
	//
	static void TrimErrStr(char *ibuf)
	{
		int nlen,i;
        /*判断字符指针是否为空及字符长度是否为0*/
        if (ibuf == NULL) 
                return;
        nlen = ( int )strlen(ibuf);
        if (nlen == 0)
                return;
        /*去前非法字符*/
        i = 0;
        while (1)
        {
                if (ibuf[i] > 0)
                        break;
                i ++;
        }
        if (i == nlen)
        {
                ibuf[0] = 0;
                return;
        }
        if (i != 0)
        {
                nlen = nlen - i + 1;
                memcpy(ibuf,&ibuf[i],nlen);
        }
        /*去后非法字符*/
        nlen = ( int )strlen(ibuf) - 1;
        while (nlen>=0)
        {
                if (ibuf[nlen] > 0 )
                {
                        ibuf[nlen + 1] = 0;
                        break;
                }
                nlen --;
        }
	}


	//
	// 去除左侧'0'字符
	//
	static void TrimLeftZeroStr(char *ibuf)
	{
			int nlen,i;
			bool bIsNeg = false;

			/*判断字符指针是否为空及字符长度是否为0*/
			if (ibuf == NULL) 
					return;
			nlen = ( int )strlen(ibuf);
			if (nlen == 0)
					return;
			/*去前0字符*/
			if ( ibuf[0] == '-' )	
			{
				i = 1;
				bIsNeg = true;
			}
			else			        i = 0;
			while (1)
			{
					if ( ibuf[i] != '0' )
							break;
					i ++;
			}
			if (i == nlen)
			{
					if ( bIsNeg )	sprintf( ibuf,"%s","-0" );
					else			ibuf[0] = 0;
					return;
			}
			if (i != 0)
			{
					nlen = nlen - i;
					char tmp[16];
					memset( tmp, 0x00, sizeof( tmp ) );
					memcpy(tmp,&ibuf[i],nlen);
					if ( bIsNeg )	sprintf( ibuf,"%s%s","-",tmp );
					else			sprintf( ibuf,"%s",tmp );
			}
	}

	//
	// 去除后侧空格
	//
	static void trim_r(char *t)
	{
		char *buf;
		
		if (!strlen(t)) return;
		
		buf = t;
		buf += strlen(t) -1;
		
		while ((*buf == ' ' || *buf == '\t') && strlen(t) )
			*buf-- = '\0';
	}

	//
	// 左侧补'0'字符
	//
    static void AddLeftZeroStr( int isrc, const char *ssrc, int len, char *sDes )
	{
			int nlen,nAdd,i,j;
			bool bIsNeg = false;
			char tmp[64];
			char ibuf[128];

			memset( ibuf, 0x00, sizeof( ibuf ) );
			if ( ssrc == NULL )				sprintf_s( ibuf, sizeof( ibuf ), "%d", isrc );
			else if( strlen(ssrc) == 0 )    sprintf_s( ibuf, sizeof( ibuf ), "%d", isrc );
			else                            sprintf_s( ibuf, sizeof( ibuf ), "%s", ssrc );

			//目标字符串初值
			sprintf( sDes,"%s",ibuf );
			//判断字符指针是否为空及字符长度是否为0
			if (ibuf == NULL)	return;
			nlen = ( int )strlen(ibuf);
			if (nlen == 0)		return;
			//判断字符长度是否小于总长度
			if ( nlen >= len )	return;
			
			//清空目标字符串
			sDes[0] = 0;

			//判断是否是负数
			if ( ibuf[0] == '-' )	
			{
				j = 1;
				bIsNeg = true;
			}
			else j = 0;

			//补零个数
			nAdd = len - nlen;
			memset( tmp, 0x00, sizeof( tmp ) );			
			for( i = 0; i < nAdd; i++ )
			{
				sprintf( tmp + i,"%s","0" );
			}
			if ( bIsNeg )	sprintf( sDes,"%s%s%s","-", tmp, ibuf + j );
			else            sprintf( sDes,"%s%s", tmp, ibuf + j );
	}
	// 左侧补固定字符
	static void PadLeft( int totalWidth, char paddingChar, char *sDes )
	{
		char  *ptmp;
		int   i;

		ptmp = new char[totalWidth+1];
		for( i = 0; i < totalWidth; i++ )
		{
			sprintf(&ptmp[i],"%c",paddingChar);
		}
		sprintf( sDes, "%s", ptmp );

		delete []ptmp;
	}
	// 右补空格
	static void PadRightBlank( int totalWidth, char *sDes )
	{
		char *ptmp;
		int  i;

		ptmp = new char[totalWidth+1];
		//sprintf(ptmp,"%s",sDes);   2016-3-19 by hq
		memset(ptmp, 0x00, totalWidth+1);
		strncpy(ptmp, sDes, totalWidth);
		for( i = strlen(sDes); i < totalWidth; i++)
		{
			sprintf(&ptmp[i],"%s"," ");
		}
		sprintf( sDes, "%s", ptmp);

		delete []ptmp;
	}
	static int runnian(const char *y)
	{
		int n=0;
		if((y[0]*1000+y[1]*100+y[2]*100+y[3]*10+y[4])%4==0)
		{
			n=1;
		}
		return n; 
	}
	//判断字符串是否为时间（考虑闰年）
	static int IsTime(const char *t)
	{
		int i=0,n=0;
		if(t[0]>47&&t[0]<58)i++;//年第一位
		if(t[1]>47&&t[1]<58)i++;//年第二位
		if(t[2]>47&&t[2]<58)i++;//年第三位
		if(t[3]>47&&t[3]<58)i++;//年第四位
		if(t[4]>47&&t[4]<50)i++;//月份第一位只能为1或0
		if((t[4]==48)&&(t[5]>48&&t[5]<58))i++;//月份第一位若0 
		if((t[4]==49)&&(t[5]>47&&t[5]<51))i++;//月份第一位若1 
		if(t[4]==48&&t[5]==49)//1
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;//日第一位为0，日第二位为1~9
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;//日第一位为1~2，日第二位为0~9
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;//日第一位为3，日第二位为0~1
		}
		if(t[4]==48&&t[5]==50)//2
		{
			if((runnian(t)==1)&&t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((runnian(t)==1)&&t[6]==49&&(t[7]>47&&t[7]<58))i++;
			if((runnian(t)==1)&&t[6]==50&&(t[7]>47&&t[7]<58))i++;
			if((runnian(t)==0)&&t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((runnian(t)==0)&&t[6]==49&&(t[7]>47&&t[7]<58))i++;
			if((runnian(t)==0)&&t[6]==50&&(t[7]>47&&t[7]<57))i++;
		}
		if(t[4]==48&&t[5]==51)//3
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}
		if(t[4]==48&&t[5]==52)//4
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&t[7]==48)i++;
		}
		if(t[4]==48&&t[5]==53)//5
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}                                  
		if(t[4]==48&&t[5]==54)//6
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&t[7]==48)i++;
		}
		if(t[4]==48&&t[5]==55)//7
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}
		if(t[4]==48&&t[5]==56)//8
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}
		if(t[4]==48&&t[5]==57)//9
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&t[7]==48)i++;
		}
		if(t[4]==49&&t[5]==48)//10    
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}
		if(t[4]==49&&t[5]==49)//11     
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&t[7]==48)i++;
		}
		if(t[4]==49&&t[5]==50)//12     
		{
			if(t[6]==48&&(t[7]>48&&t[7]<58))i++;
			if((t[6]>48&&t[6]<51)&&(t[7]>47&&t[7]<58))i++;
			if(t[6]==51&&(t[7]>47&&t[7]<50))i++;
		}

		if(i==7)
		{
			n=1;
		}
		return n;

	}
};

#pragma warning(pop)

#endif 
