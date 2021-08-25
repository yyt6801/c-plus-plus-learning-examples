/****************************************************************************** */
/*	文件名	: Algorithm.h														*/
/*																				*/
/*	功  能	: 通用算法函数库													*/
/*																				*/
/*	版本历史：																	*/
/*	--------------------------------------------------------------------------	*/
/*	   版本号|	 日 期	  | 作者  | 修改注释									*/
/*		1.00 | 2011-06-07 | 宋 勇 |	初始版本									*/
/*																				*/
/*	--------------------------------------------------------------------------	*/
/*																				*/
/*						COPYRIGHT (C)  NERCAR of USTB							*/
/*																				*/
/****************************************************************************** */

#ifndef _ALGORITH_H_
#define _ALGORITH_H_


#include <math.h>
#include <float.h>

#pragma warning(push)
#pragma warning(disable: 4244)	//double -> float


class Algorithm
{

public:

	//
	// 判断数据是否无效
	//
	template<class TypeX, class Type>
    static inline bool IsValid(TypeX x, Type min, Type max)
    {
		const char *dt = typeid(x).name();
		if (!strncmp (dt, "float", 5) || !strncmp (dt, "double", 6))
		{
			if (_fpclass(x) < 8 || _fpclass(x) == 512)	
			{
				return  false;	//无效浮点数
			}
		}

		return (x >= min && x <= max);	
	}

	//
	// 限幅处理
	//
	template<class TypeX, class Type>
    static inline TypeX Limiter(TypeX x, Type min, Type max)
    {
		//无效浮点数处理
		const char *dt = typeid(x).name();
		if (!strncmp (dt, "float", 5) || !strncmp (dt, "double", 6))
		{
			if ( _fpclass(x) <    8 )	return  min;
			if ( _fpclass(x) == 512 )	return  max;	
		}

		if		(x < min)	return min;
		else if (x > max)	return max;
		else				return x;
	}

	//
	// 判断x为奇或偶数
	//
	template<class Type>
    static inline bool IsEven(Type x)
    {
        return (x&1)?0:1;
    }
	template<class Type>
    static inline bool IsOdd(Type x)
    {
        return (x&1)?1:0;
    }

	//
	//	位操作
	//
	template<class Type>
    static inline void SetBit(Type& x, int n)
	{
		x |= (1<<n);
	}
	template<class Type>
    static inline void ClearBit(Type& x, int n)
	{
		x &= (~(1<<n));
	}
	template<class Type>
    static inline bool BitIsClear(Type x, int n)
	{
		return( (x & (1<<n)) == 0 );
	}
	template<class Type>
    static inline bool BitIsSet(Type x, int n)
	{
		return( !BitIsClear(x, n) );
	}

	//
	// 查找算法（查找数组xa[]中第一个大于或等于x的元素索引）
	//
	// 注意：要求xa[]值为单调上升
	//
	template<class Type>
    static inline int Search(const Type& x, const Type xa[], int n)
    {
		int i;

		for (i=0; i<n-1; i++)
		{
			if (xa[i] >= x)	break;
		}

		return i;
	}


	//
	// 查找数组的最小值元素的索引
	//
	template<class Type>
	static  inline int IndexOfMin(const Type xa[], int n)
	{
		int  i,j = 0;
		Type Min = xa[0];

		for (i = 1; i < n; i++)
		{
			if (xa[i] < Min)
			{
				Min = xa[i];
				j = i;
			}
		}

		return (j);
	}


	//
	// 查找数组的最大值元素的索引
	//
	template<class Type>
	static  inline int IndexOfMax(const Type xa[], int n)
	{
		int  i,j = 0;
		Type Max = xa[0];

		for (i = 1; i < n; i++)
		{
			if (xa[i] > Max)
			{
				Max = xa[i];
				j = i;
			}
		}

		return (j);
	}

    
	//
	// 查找数组的最小值
	//
	template<class Type>
	static  inline Type Min(const Type xa[], int n)
	{
		int  i;
		Type Min = xa[0];

		for (i = 1; i < n; i++)
		{
			if (xa[i] < Min)
			{
				Min = xa[i];
			}
		}

		return (Min);
	}

	//
	// 查找数组的最大值
	//xa[10]={'12','34'..}
	//int a= Max(xa,10)
	template<class Type>
	static  inline Type Max(const Type xa[], int n)
	{
		int  i;
		Type Max = xa[0];

		for (i = 1; i < n; i++)
		{
			if (xa[i] > Max)
			{
				Max = xa[i];
			}
		}

		return (Max);
	}

	//
	// 计算数组的平均值
	//
	template<class Type>
	static  inline Type Mean(const Type xa[], int n)
	{
		if (n <= 0)  return (Type(0));	//2012-7-13 add

		int  i;
		Type Mean = xa[0];

		for (i = 1; i < n; i++)
		{
			Mean += xa[i];
		}

		return Type(Mean/(1.0*n));
	}

	//
	// 计算数组的Sigma值
	//
	template<class Type>
	static  inline double Sigma(const Type xa[], int n)
	{
		int    i;
		Type   Mean  = MeanOf(xa, n);
		double Sigma = 0;

		for (i = 0; i < n; i++)
		{
			Sigma += (xa[i] - Mean) * (xa[i] - Mean);
		}

		if (n > 1)
		{
			Sigma /= n-1;

			if(Sigma > 0.0)
			{
				Sigma = sqrt(Sigma);
			}
		}

		return Sigma;
	}


	//
	// 分段线性插值算法
	//
	// 注意：要求xa[]值为单调
	//
	template<class TypeX, class TypeY>
    static TypeY LinearInterp(const TypeX& x, const TypeX xa[], const TypeY ya[], int n)
    {
		int left   = 0;     
		int right  = n - 1;

		if (n <= 1)
		{
			return ya[0];
		}
		else if (n > 2) 
		{   
			int desc = (xa[left] > xa[right]);  

			//左侧外推
			if ( (!desc && x <= xa[left]) || (desc && x >= xa[left]) ) 
			{
				right = left + 1;   
			}
			//右侧外推
			else if( (!desc && x >= xa[right]) || (desc && x <= xa[right]) )
			{
				left = right - 1;
			}
			//区间内插值
			else
			{    
				//查找x所在的区间
				while (right > left+1)
				{   
					int middle = (left + right + 1) / 2;

					if ( (!desc && x > xa[middle]) || (desc && x < xa[middle]) )
					{
						left = middle;
					} 
					else
					{  
						right = middle;
					}
				}
			} 
		}

		if (xa[left] == xa[right])
		{
			return (ya[right]);
		}
		else if (xa[left] == x)
		{
			return (ya[left]);
		}
		else
		{
			//线性插值
			return ( ya[left] + 
				1.0 * (ya[right]-ya[left]) / (xa[right]-xa[left])
				* (x - xa[left]) );
		}

   }

	//
	// 分段牛顿插值算法
	//
	// 注意：要求xa[]值为严格单调上升
	//
	template<class TypeX, class TypeY>
    static TypeY NewtonInterp(const TypeX& x, const TypeX xa[], const TypeY ya[], int n)
    {
		int		i,j; 
		int		loop; 
		TypeY	y[2];			//两区间的牛顿插值的结果
		double	f1[3],f2[2];    //一阶差分和二阶差分

		//样本数不够，或x值在样本区间之外
		if( n < 3 || x <= xa[0] || x >= xa[n-1] )
		{
			return (LinearInterp(x, xa, ya, n));
		}

		//查找xa[]中第一个大于或等于x的元素索引
		i = Search(x, xa, n);
		if( xa[i] == x )
		{
			return (ya[i]);
		}

		//保证在x前后各有1个样本
		i--;

		//x之前最多只有1个样本: xa[i]、x、xa[i+1]、xa[i+2]
		if( i <= 0 )
		{
			i = 0;
			loop = 2;
		}
		else
		{
			//保证在x之前有2个样本
			i--;

			//x之后最多只有一个样本: xa[i]、xa[i+1]、x、xa[i+2]
			if( i >= n - 3 )
			{
				i = n - 3;
				loop = 2;
			}
			//x前后各有2个样本: xa[i]、xa[i+1]、x、xa[i+2]、xa[i+3]
			else
			{
				loop = 3;
			}
		}

		//执行牛顿插值
		for(j = 0; j < loop; j++)
		{
			f1[j] = 1.0 * (ya[i+j+1] - ya[i+j]) / ( xa[i+j+1] - xa[i+j]);

			if( j > 0 )
			{
				f2[j-1] = (f1[j] - f1[j-1]) / ( xa[i+j+1] - xa[i+j-1]);

				y[j-1]  = ya[i+j-1]; 
				y[j-1] += f1[j-1]*(x-xa[i+j-1]);
				y[j-1] += f2[j-1]*(x-xa[i+j-1])*(x-xa[i+j]);
			}

		}

		//如果只执行了一个区间的牛顿插值
		if(loop == 2)
		{
			y[1] = y[0];
		}

		//综合相邻两个区间的牛顿插值结果
		return ( TypeY(y[0] + 
			1.0*(y[1] - y[0])/(xa[i+2] - xa[i+1])
			* (x - xa[i+1])) );

	}

	//
	// 解线性方程组的高斯消元算法 A * X = Y
	//
	// 注意：数组a[n*n]和y[]可能会改变，矩阵A按行优先存储在a[n*n]数组中
	//
	template<class TypeX, class TypeY, class TypeA>
	static bool GaussElimination(TypeX x[], TypeA a[], TypeY y[], int n)
	{
		int		i, j, k;
		double  tmp;
	   
		// 如果主对角线元素为0，行交换
		for (i = 0; i < n; i++) 
		{    
			if ( fabs(a[i*n+i]) <= 1e-5 )
			{
				for (j = i + 1; j < n; j++) 
				{
					if (fabs(a[j*n+i]) <= 1e-5 )
						continue;

					for (k = 0; k < n; k++) 
					{
						tmp = a[i*n+k];
						a[i*n+k] = a[j*n+k];
						a[j*n+k] = tmp;
					}
					tmp  = y[i];
					y[i] = y[j];
					y[j] = tmp;
					break;
				}

				// 行交换后主对角线元素仍为0
				if (fabs(a[j*n+i]) <= 1e-5 )
				{
					return false;
				}
			}
		}

		//消元
		for (k = 0; k < n-1; k++) 
		{
			for (i = k+1; i<n; i++)
			{
				tmp = 1.0 * a[i*n+k] / a[k*n+k];
				for (j = k+1; j<n; j++)
				{
					a[i*n+j] -= tmp * a[k*n+j];
				}
				y[i] -= tmp * y[k];
			}
		}

		//求解
		x[n-1] = y[n-1]/a[(n-1)*n+n-1];
		for(i=n-2; i>=0; i--)
		{
			x[i] = y[i];
			for(j=i+1; j<n; j++)
			{
				x[i] -= a[i*n+j]*x[j];
			}
			x[i] /= a[i*n+i];
		}
	    
		return true;
	}

	//
	// 多元线性回归算法  y = a0 + a1 * x1 + a2 * x2 + ....+ am * xm
	//
	// 注意：数组a[]的元素个数为m+1, xi样本按行优先存储在xm[n*m]数组中，n为样本个数
	//
	template<class TypeX, class TypeY, class TypeA>
    static bool MultiLinearRegress(TypeA a[], int m, const TypeX xm[], const TypeY ya[], int n)
    {
		int	   i, j, k;
		double *sum_x, sum_y;
		double sum_xx, sum_xy;
		double *lnn, *lny;
		double *b;
		bool   ret;

		sum_x	= new double[m];
		lnn		= new double[m*m];
		lny		= new double[m];
		b		= new double[m];

		//求每列的和
		for(i=0; i<m; i++)
		{
			sum_x[i] = 0;
			for(j=0; j<n; j++)
			{
				sum_x[i] += xm[j*m + i];
			}
		}
		sum_y = 0;
		for(j=0; j<n; j++)
		{
			sum_y += ya[j];
		}

		//构造正规方程组
		for(i=0; i<m; i++)
		{
			for(k=i; k<m; k++)
			{
				sum_xx = 0;
				for(j=0; j<n; j++)
				{
					sum_xx += xm[j*m + i]*xm[j*m + k];
				}
				lnn[i*m + k] = sum_xx - sum_x[k] * sum_x[i] / n;
				lnn[k*m + i] = lnn[i*m + k];
			}
			sum_xy = 0;
			for(j=0; j<n; j++)
			{
				sum_xy += xm[j*m + i]*ya[j];
			}
			lny[i] = sum_xy - sum_x[i] * sum_y / n;
		}

		//求解方程组
		if(GaussElimination(b, lnn, lny, m))
		{
			a[0] = sum_y;
			for(i=0; i<m; i++)
			{
				a[i+1] = b[i];
				a[0]  -= b[i]*sum_x[i];
			}
			a[0] /= 1.f * n;

			ret = true;
		}
		else
		{
			ret = false;
		}

		delete [] sum_x;
		delete [] lnn;
		delete [] lny;
		delete [] b;

		return ret;
	}

	//
	// 多项式回归算法   y = a0 + a1 * x + a2 * x^2 + ....+ am * x^m
	//
	// 注意：数组a[]的元素个数为m+1
	//
	template<class TypeX, class TypeY, class TypeA>
    static bool PolyRegress(TypeA a[], int m, const TypeX xa[], const TypeY ya[], int n)
    {
		int	   i, j;
		double *xm;
		bool   ret;

		xm = new double[n*m];

		//将多项式回归转换为多元线性回归
		for(i=0; i<n; i++)
		{
			xm[i*m + 0] = xa[i];
			for(j=1; j<m; j++)
			{
				xm[i*m + j] = xm[i*m + j-1] * xa[i];
			}
		}

		//多元线性回归
		ret = MultiLinearRegress(a, m, xm, ya, n);

		delete [] xm;

		return ret;
	}
	
	//					    /b
	// 龙贝格积分算法   y = |  f(x) * dx
	//					    /a
	//
	#define EPSILON			0.001	//精度
	#define MAX_INTER		10		//最多迭代次数
	template<class TypeX, class TypeY>
	static TypeY RombergIntegral(TypeY (*fun)(TypeX x), TypeX a, TypeX b)
	{
		int		i, k;
		int		m, n;		
		double	h, s, q;
		double	p;			//p为待计算元素的前一个元素(同一行)
		double	y[MAX_INTER];
		double	ep;			

		//初值
		h = b - a;
		y[0] = h * (fun(a) + fun(b))/2.0;
		m = 1; 
		n = 1; 

		//迭代计算
		do
		{ 
			//求T2n
			p = 0.0;
			for(i = 0; i < n; i++)
			{ 
				p += fun(a + (i + 0.5) * h);
			}
			p *= h;
			p = (y[0] + p)/2.0;	//p -> T2n 

			//求第m行元素
			s = 1.0;
			for (k = 1; k <= m; k++)
			{ 
				s *= 4.0;
				q = (s * p - y[k-1]) / (s - 1.0);
				y[k-1] = p; 
				p = q;
			}

			ep = fabs((q - y[m-1])/q); //积分精度
			m++; 
			y[m-1] = q; 
			n *= 2;			//复化梯形积分的分点数
			h *= 0.5;

		}while ((ep >= EPSILON) && (m < MAX_INTER-1));

		return ((TypeY)q);
	}


};


#pragma warning(pop)

#endif //_ALGORITH_H_
