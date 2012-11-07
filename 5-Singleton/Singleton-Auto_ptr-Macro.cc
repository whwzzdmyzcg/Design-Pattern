/*
 * =====================================================================================
 *
 *       Filename:  Singleton-Auto_ptr-Macro.cc
 *
 *    Description:  单件的智能指针宏实现
 *
 *        Version:  1.0
 *        Created:  11/07/2012 08:59:42 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Rachel
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory>	// auto_ptr

using std::cout;
using std::endl;

/*
 * Singleton.h
 * (auto_ptr)单件的宏定义
 * 多行宏定义的注释问题-http://tonybai.com/2008/03/14/the-problems-of-commenting-multiple-lines-macro/
 */
#define DEFINE_SINGLETON(cls)\
	private:\
		static std::auto_ptr<cls> _instance;\
		cls(const cls&){} /* Copy Constructor */\
		cls & operator=(const cls&){} /* = */\
	protected:\
		cls(){} /* Constructor */\
	public:\
		~cls(){} /* Destructor */\
		static cls * Instance()\
		{\
			if (!_instance.get())\
			{\
				_instance = std::auto_ptr<cls>(new cls());\
			}\
			return _instance.get();\
		}\

#define IMPLEMENT_SINGLETON(cls)\
std::auto_ptr<cls> cls::_instance(NULL);
//	std::auto_ptr<cls> cls::_instance;

/*
 * subSingleton.h
 * 利用宏定义来实现单件，若还需要定义其他单件类，再写类似的.h和.cc文件即可。
 */
class subSingleton
{
	DEFINE_SINGLETON(subSingleton);
	public:
		void Print()
		{
			std::cout << "subSingleton" << std::endl;
		}
		// 不能重载构造函数。。。
	//	subSingleton()
	//	{
	//		std::cout << "subSingleton" << std::endl;
	//	}
};

/*
 * subSingleton.cc
 */
IMPLEMENT_SINGLETON(subSingleton);

/*
 * Example.cc
 */
int main(int argc, char *argv[])
{
	subSingleton * ss = subSingleton::Instance();
	ss->Print();

	return 0;
}
