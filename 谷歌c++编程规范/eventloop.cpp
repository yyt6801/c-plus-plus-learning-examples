//Copyright 2008 Google Inc.    版权
//License(BSD/GPL/...)			许可证, BSD/GPL/MIT/...
//Author: voidccc				作者
//This is ...					文件内容简短说明


								//包含次序标准化避免隐藏依赖
#include "eventloop.h"			//1 本类的声明(第一个包含本类h文件,有效减少依赖)
#include <sys/types.h>			//2 C系统文件
#include <vector>				//3 C++系统文件
#include "base/basictypes.h"	//4 其他库文件
#include "foo/public/bar.h"		//5 本项目内头文件(避免使用UNIX文件路径"."和"..")

using std::string				//可以在整个cc文件和h文件的方法内使用using  禁止使用using namespace xx污染命名空间

namespace mynamespace {

EventLoop::EventLoop()
    : _num_entries_(10),						//多行初始化列表, ":"前4空格缩进,以","结尾
	  _num_complated_connections_(false) {		//多个变量折行对齐
...												//单行初始化列表 Class::Class() : _var(xx) {
												//构造函数中值进行那些没有实际意义的初始化
}

ReturnType ClassName::ReallyLongFuntionName(const Type& par_name1,		//参数过多时","结尾  每行一个变量对齐
											Type* par_name2) {
  bool retval = DoSomething(averyveryveryverylongargument1,
							argument2, argument3);						//参数过多时","结尾
  if (condition) {														//条件括号内无空格, (condition)左右1空格, if执行体2空格缩进
    for (int i = 0; i < kSomeNumber; ++i) {							//前置自增运算
	  if (this_one_thing > this_other_thing &&						//条件变量过多时, 条件运算符 && 结尾
		  a_third_thing == a_fourth_thing) {						//条件左对齐
		  // TODO(name@abc.com): xxx								//临时方案使用TODO(大写)注释, 后面括号里加上你的大名,邮箱等
	  }
	}
  } else {							//大括号与else同行,else左右1空格
	  nt j = g()					//尽量使用初始化时声明
  }
  switch (var) {					//(var)左右各1空格
	case 0: {						//条件相对switch 2空格缩进
	  ...							//执行体相对switch 4空格缩进
	break;
	}
	default: {
		assert(false);				//若default永不执行可使用assert
	}
  }
  return x;							//返回值不需要加括号
}

}  // namespace mynamespace         命名空间结束注释