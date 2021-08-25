/****************************************************************************** */
/*	文件名	: TimeStamp.h														*/
/*																				*/
/*	功  能	: 时间处理函数库													*/
/*																				*/
/*	版本历史：																	*/
/*	--------------------------------------------------------------------------	*/
/*	   版本号|	 日 期	  | 作者  | 修改注释									*/
/*		1.00 | 2011-04-08 | 宋 勇 |	初始版本									*/
/*																				*/
/*	--------------------------------------------------------------------------	*/
/*																				*/
/*						COPYRIGHT (C)  NERCAR of USTB							*/
/*																				*/
/****************************************************************************** */

#ifndef _TIMESTAMP_H_
#define _TIMESTAMP_H_

#include	<windows.h>
#include	<stdio.h>
#include	<time.h>
#include	<oaidl.h>

#ifndef	TIMESTAMP
#define	TIMESTAMP		__int64			
#endif

#pragma warning(push)
#pragma warning(disable: 4996)

typedef struct _S7_Time
{
	BYTE	Year;
	BYTE	Month;
	BYTE	Day;
	BYTE	Hour;
	BYTE	Minute;
	BYTE	Second;
	WORD	Milliseconds:12;
	WORD	WeekdDy:4;
}S7TIME;

class TimeStamp
{	

	TIMESTAMP m_Time;

public:

	TimeStamp(): m_Time(0)
	{

	}

	TimeStamp(TIMESTAMP Time)
	{
		m_Time = Time;
	}

	TimeStamp(const char* sTime)
	{
		*this = sTime;
	}

	TimeStamp(const VARIANT& vTime)
	{
		*this = vTime;
	}

	TimeStamp(const S7TIME& S7Time)
	{
		*this = S7Time;
	}

	TimeStamp& operator = (TIMESTAMP Time)
	{
		m_Time = Time;
		return *this;
	}

	TimeStamp& operator = (const char* sTime)
	{
		SYSTEMTIME sysTime;
		int y=0,m=0,d=0,h=0,min=0,sec=0,ms=0;

		sscanf_s(sTime, "%04u-%02u-%02u %02u:%02u:%02u.%03u", 
			&y, &m, &d, &h, &min, &sec, &ms);

		sysTime.wYear = y;
		sysTime.wMonth = m;
		sysTime.wDay = d;
		sysTime.wHour = h;
		sysTime.wMinute = min;
		sysTime.wSecond = sec;
		sysTime.wMilliseconds = ms;

		FILETIME locTime;
		SystemTimeToFileTime(&sysTime, &locTime);  
		LocalFileTimeToFileTime(&locTime, (FILETIME *)&m_Time);

		return *this;
	}

	TimeStamp& operator = (const S7TIME& S7Time)
	{
		SYSTEMTIME sysTime;

		sysTime.wYear = S7Time.Year;
		sysTime.wMonth = S7Time.Month;
		sysTime.wDay = S7Time.Day;
		sysTime.wHour = S7Time.Hour;
		sysTime.wMinute = S7Time.Minute;
		sysTime.wSecond = S7Time.Second;
		sysTime.wMilliseconds = S7Time.Milliseconds;

		FILETIME locTime;
		SystemTimeToFileTime(&sysTime, &locTime);  
		LocalFileTimeToFileTime(&locTime, (FILETIME *)&m_Time);

		return *this;
	}

	TimeStamp& operator = (const VARIANT& vTime)
	{
		if(V_VT(&vTime) == VT_DATE)
		{
			SYSTEMTIME sysTime;
			FILETIME locTime;
			VariantTimeToSystemTime(V_R8(&vTime), &sysTime);
			SystemTimeToFileTime(&sysTime, &locTime); 
			LocalFileTimeToFileTime(&locTime, (FILETIME *)&m_Time);
		}
		return *this;
	}

	TIMESTAMP Now()
	{
		GetSystemTimeAsFileTime((FILETIME *)&m_Time);
		return m_Time;
	}

	void operator += (const float sec)
	{
		m_Time += TIMESTAMP(sec * 10000000);
	}

	void operator -= (const float sec)
	{
		m_Time -= TIMESTAMP(sec * 10000000);
	}

	operator TIMESTAMP() const
	{
		return m_Time;
	}

	operator SYSTEMTIME() const
	{
		SYSTEMTIME sysTime;	
		FILETIME locTime;

		FileTimeToLocalFileTime((FILETIME *)&m_Time, &locTime);
		FileTimeToSystemTime(&locTime, &sysTime);

		return sysTime;
	}

	operator S7TIME() const
	{
		S7TIME S7Time;

		FILETIME locTime;
		SYSTEMTIME sysTime;	

		FileTimeToLocalFileTime((FILETIME *)&m_Time, &locTime);
		FileTimeToSystemTime(&locTime, &sysTime);

		S7Time.Year = BYTE(sysTime.wYear%100);
		S7Time.Month = BYTE(sysTime.wMonth);
		S7Time.Day = BYTE(sysTime.wDay);
		S7Time.Hour = BYTE(sysTime.wHour);
		S7Time.Minute = BYTE(sysTime.wMinute);
		S7Time.Second = BYTE(sysTime.wSecond);
		S7Time.Milliseconds = sysTime.wMilliseconds;

		time_t _tt = time_t((m_Time - 116444736000000000)/10000000);
		S7Time.WeekdDy = localtime(&_tt)->tm_wday;

		return S7Time;
	}

	operator VARIANT() const
	{
		VARIANT vTime;

		VariantClear(&vTime);
		
		V_VT(&vTime) = VT_NULL;
		
		if (m_Time != 0)
		{
			V_VT(&vTime) = VT_DATE;
			SystemTimeToVariantTime(&(SYSTEMTIME(*this)), &V_R8(&vTime));
		}		

		return vTime;
	}

	//return time diefference as second
	friend 
	float operator - (const TimeStamp& lhs, const TimeStamp& rhs)
	{
		return ((lhs.m_Time - rhs.m_Time) / 10000000.f);
	}

	friend
	float operator - (const TimeStamp& lhs, TIMESTAMP rhs)
	{
		return ((lhs.m_Time - rhs) / 10000000.f);
	}

	friend
	float operator - ( TIMESTAMP rhs, const TimeStamp& lhs)
	{
		return ((rhs - lhs.m_Time) / 10000000.f);
	}

	int Year() const { return(SYSTEMTIME(*this).wYear); }
	int Month()const { return(SYSTEMTIME(*this).wMonth); }
	int Day()  const { return(SYSTEMTIME(*this).wDay); }
	int Hour() const { return(SYSTEMTIME(*this).wHour); }
	int Minute()const{ return(SYSTEMTIME(*this).wMinute); }
	int Second()const{ return(SYSTEMTIME(*this).wSecond); }
	int Milliseconds()const { return(SYSTEMTIME(*this).wMilliseconds); }


	const char* ToString(bool bIncMs = true) const
	{
		__declspec(thread) static char szBuff[24];

		SYSTEMTIME sysTime = *this;	

		if( bIncMs )
		{
			sprintf_s(szBuff, 24, "%04d-%02d-%02d %02d:%02d:%02d.%03d", 
				sysTime.wYear, sysTime.wMonth, sysTime.wDay, 
				sysTime.wHour, sysTime.wMinute, sysTime.wSecond, 
				sysTime.wMilliseconds);
		}
		else
		{
			sprintf_s(szBuff, 24, "%04d-%02d-%02d %02d:%02d:%02d", 
				sysTime.wYear, sysTime.wMonth, sysTime.wDay, 
				sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
		}
	
		return szBuff;
	}

	const char* ToDateString() const
	{
		__declspec(thread) static char szBuff[16];

		SYSTEMTIME sysTime = *this;	

		sprintf_s(szBuff, 16, "%04d-%02d-%02d", 
			sysTime.wYear, sysTime.wMonth, sysTime.wDay);
	
		return szBuff;
	}

	const char* ToTimeString(bool bIncMs = true) const
	{
		__declspec(thread) static char szBuff[16];

		SYSTEMTIME sysTime = *this;	

		if( bIncMs )	//修正sprintf_s()参数错误, 2013-5-27
		{
			sprintf_s(szBuff, 16, "%02d:%02d:%02d.%03d", 
				sysTime.wHour, sysTime.wMinute, sysTime.wSecond, 
				sysTime.wMilliseconds);
		}
		else
		{
			sprintf_s(szBuff, 16, "%02d:%02d:%02d", 
				sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
		}
	
		return szBuff;
	}

	const char* ToFileName() const
	{
		__declspec(thread) static char szBuff[24];

		SYSTEMTIME sysTime = *this;	

		sprintf_s(szBuff, 24, "%04d%02d%02d#%02d%02d%02d", 
			sysTime.wYear, sysTime.wMonth, sysTime.wDay, 
			sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	
		return szBuff;
	}

};

#pragma warning(pop)

#endif //_TIMESTAMP_H_