// 20120226
// longhua

/**
 * 实现模板形式的auto_ptr垃圾自动回收
 */
#ifndef _TEST_H_
#define _TEST_H_
// XXX.h
// Class that will implement the singleton mode, must use the macro in it's declare file
#include "Singleton.h"

//#define DECLARE_SINGLETON_CLASS(type) \
	friend class auto_ptr<type>; \
	friend class Singleton<type>;
class Test
{
	public:
		void Run()
		{
		}
	private:
		Test()
		{
		}
		~Test()
		{
		}
		DECLARE_SINGLETON_CLASS(Test);
};
typedef Singleton<Test> test;
#endif /*_TEST_H_*/
