/*
 * =====================================================================================
 *
 *       Filename:  Singleton-StaticMethod.cc
 *
 *    Description:  使用静态方法创建单件实例
 *    				程序启动后，对象立即被创建出来
 *    				程序结束后，系统会负责处理对象的释放等问题
 *
 *        Version:  1.0
 *        Created:  02/26/2012 07:41:12 PM
 *       Modified:  03/06/2012 07:41:12 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Rachel
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * Singleton.h
 * 延迟实例化-在调用该类的instance方法后，对象才被创建出来
 * 在多线程（之前没有被任何单线程调用过）调用的时候，会发生内存错误-原因，操作的非原子性
 */
//class Singleton
//{
//	public:
//		static Singleton& Instance()
//		{
//			static Singleton _instance;
//			return _instance;
//		}
//
//		~Singleton() // Destructor
//		{
//			cout << "Destroy Singleton" << endl;
//		}
//
//		void Print()
//		{
//		cout << "Hello, world!" << endl;
//		}
//
//	private:
//		Singleton() // Constructor; Private
//		{
//			cout << "Create Singleton" << endl;
//		}
//};

/*
 * Singleton.h
 * Another Method
 * 急切实例化-程序启动后，就直接创建出来，因此在多线程中也不会存在问题
 */
class Singleton
{
	public:
		static Singleton& Instance()
		{
			return _instance;
		}

		void Print()
		{
			cout << "Hello, world!" << endl;
		}

		~Singleton() // Destructor
		{
			cout << "Destroy Singleton" << endl;
		}

	protected:
		Singleton() // Constructor; Private
		{
			cout << "Create Singleton" << endl;
		}

	private:
		static Singleton _instance;
};

/*
 * Singleton.cc
 */
Singleton Singleton::_instance; // Create an object

/*
 * Example.cc
 */
int main(int argc, char *argv[])
{
	Singleton::Instance().Print();
	Singleton::Instance().Print();
	Singleton::Instance().Print();

	return 0;
}
