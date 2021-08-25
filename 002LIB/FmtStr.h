/****************************************************************************** */
/*	FILE NAME	: FmtStr.H														*/
/*	VERSION		: 1.0															*/
/*	FUNCTION	: 字符串格式化													*/
/*																				*/
/*	COPYRIGHT (C)  NERCAR of USTB												*/
/*																				*/
/****************************************************************************** */

#ifndef _FORMAT_STRING_H_
#define _FORMAT_STRING_H_

#include "XException.h"			//异常处理

#pragma warning(push)
#pragma warning(disable: 4996)

class FormatString
{
	char* pStr;

public:

	FormatString()
	{
		pStr = NULL;
	}

	FormatString(const char* _pStr)
	{
		pStr = NULL;

//		if(_pStr && strlen(_pStr) > 0)	//2015-6-6 changed by sy
		if(_pStr )
		{
			pStr = new char[strlen(_pStr)+1];

			strcpy(pStr, _pStr);
		}
	}

	FormatString(const FormatString& _Right)
	{
		pStr = NULL;

		*this = _Right;

	}

	~FormatString()
	{
		if(pStr) delete [] pStr;
	}

	FormatString& operator =(const FormatString& _Right)
	{
		if(pStr) delete [] pStr;

//		if(_Right.Length() > 0 )	//2015-6-6 changed by sy
		if(_Right.pStr )
		{
			pStr = new char[_Right.Length()+1];

			strcpy(pStr, _Right.pStr);
		}
		else
		{
			pStr = NULL;
		}

		return (*this);
	}


	FormatString& operator =(const char* _pStr)
	{
		return (*this = FormatString(_pStr));
	}

	long Length() const
	{
		return (pStr==NULL?0:(long)strlen(pStr));
	}

	FormatString& operator +=(const FormatString& _Right)
	{
		if(_Right.Length() > 0)
		{
			char* tmp = pStr;

			pStr = new char[Length() + _Right.Length() + 1];

			if(tmp)
			{
				strcpy(pStr, tmp);
				strcat(pStr, _Right.pStr);
				delete [] tmp;
			}
			else
			{
				strcpy(pStr, _Right.pStr);
			}
		}

		return (*this);
	}


	FormatString& operator +=(const char* _pStr)
	{
		return (*this += FormatString(_pStr));
	}

	const char* Create(const char* fmt, ...)
	{
		if(pStr) delete [] pStr;

		pStr = new char [1024];

		va_list args;
		va_start(args, fmt);
		_vsnprintf_s(pStr, 1024, _TRUNCATE, fmt, args);
		va_end(args);

		return pStr;
	}

	const char* operator()(const char* fmt, ...)
	{
		if(pStr) delete [] pStr;

		pStr = new char [1024];

		va_list args;
		va_start(args, fmt);
		_vsnprintf_s(pStr, 1024, _TRUNCATE, fmt, args);
		va_end(args);

		return pStr;
	}

	operator const char*() const
	{
		return pStr;
	}

	char& operator[](int idx)
	{
		if( pStr == NULL )
		{
			THROW_ERROR(AL_ERROR, "字符串为空，不能获取指定的字符。");//抛出异常
		}

		if( (idx < 0) || (idx >= Length()) ) 
		{
			THROW_ERROR(AL_ERROR, "字符索引不合理，不能获取指定的字符。");//抛出异常
		}

		return pStr[idx]; 
	}

	char  operator[](int idx) const
	{
		if( pStr == NULL )
		{
			THROW_ERROR(AL_ERROR, "字符串为空，不能获取指定的字符。");//抛出异常
		}

		if( (idx < 0) || (idx >= Length()) ) 
		{
			THROW_ERROR(AL_ERROR, "字符索引不合理，不能获取指定的字符。");//抛出异常
		}

		return pStr[idx]; 
	}

	friend bool operator ==(const FormatString& _Left, const FormatString& _Right)
	{
		  if( _Left.pStr ==  _Right.pStr) return true; 
		  if( (_Left.pStr==NULL) || (_Left.pStr==NULL) ) return false; 
		  return (strcmp(_Left.pStr, _Right.pStr)==0); 

	}

	friend bool operator !=(const FormatString& _Left, const FormatString& _Right)
	{
		return !(_Left == _Right);
	}

	friend bool operator ==(const FormatString& _Left, const char* _Right)
	{
		return (_Left == FormatString(_Right));
	}

	friend bool operator !=(const FormatString& _Left, const char* _Right)
	{
		return (_Left != FormatString(_Right));
	}
};

#pragma warning(pop)

#endif //_FORMAT_STRING_H_


