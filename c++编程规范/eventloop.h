//Copyright 2008 Google Inc.    版权
//License(BSD/GPL/...)			许可证, BSD/GPL/MIT/...
//Author: voidccc				作者
//This is ...					文件内容简短说明
#ifndef PROJECT_EVENTLOOP_H_	//防止重复包含 宏格式为: <project>_<path>_<file>_
#define PROJECT_EVENTLOOP_H_

class Channel;

namespace mynamespace {

class EventLoop : public CallbackInterface {	//类名大写开头单词, 使用组合通常比使用继承更适宜   若使用继承,只用共有继承   另:接口类命名以"Interface"结尾
 public:										//访问限定符1空格缩进
												//每一个限定符内, 声明顺序如下
												//1 typedefs和enums
												//2 常量
												//3 构造函数
												//4 析构函数
												//5 成员函数, 含静态数据成员
												//6 成员变量, 含静态成员变量

  typedef vector<int> IntVector;				//2空格缩进
  enum UrlTableErrors {							//枚举名同类名, 大写开头单词
    ERROR_OUT_OF_MEMORY = 0,					//枚举值2空格缩进, 全大写下划线
	ERROR_MALFORMED_INPUT,
  };
  explicit EventLoop(const int xx);				//explicit修饰单参数构造函数,防止隐式类型转换误用    若定义了成员变量无其他构造函数,要定义一个默认构造函数

  void Add(const std::string& input, Channel* output)		//普通函数命名,大写开头单词,输入参数在前为const引用,输入参数在后为指针部位参数设置缺省值
															//存取函数命名, 取:同变量名, 存:值函数名为set_varname  短小的存取函数可用内联
  int num_entries() const { return num_entries_; }			//尽可能使用const
  void set_num_entries(int num_entries) { num_entries_ = num_entries; }

 private:										//仅在需要拷贝对象时使用拷贝构造函数 
  DISALLOW_COPY_AND_ASSIGN(EventLoop);			//不需要拷贝时在private里使用DISALLOW_COPY_AND_ASSIGN宏
												//变量用描述性名称,不要节约可能构建,让别人理解你的代码更重要
  const int kDaysInWeek = 7;					//const变量为k开头,后跟大写开头单词
  int num_entries_;								//变量命名:全小写, 有意义的单词和下划线
  int num_conplated_connections_;				//类成员变量下划线结尾

  Channel* channel_;							//头文件中只用了指针/引用, 则前向声明而非引入头文件

};
} // namespace mynamespace

#endif	// PROJECT_EVENTLOOP_H_			保护宏结尾加注释