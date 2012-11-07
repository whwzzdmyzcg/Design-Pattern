/*
 * =====================================================================================
 *
 *       Filename:  Singleton-InnerClass.cc
 *
 *    Description:  Q：若父类不是单件模式，子类是否可以是单件模式。
 *    				A：Yes。
 *    				这个问题比较白痴，例如Java中任何类都至少是Object的子类，那么父类是否单件对子类根本没有影响。
 *                  Q：单件模式中构造函数的参数传递。
 *                  A：按常规方式给构造函数传参数即可
 *                  Q：单件模式的对象释放
 *					A：一个内嵌类加一个静态成员实现单件实例的释放
 *
 *        Version:  1.0
 *        Created:  02/22/2012 07:41:12 PM
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
using std::string;

/*
 * SuperSingleton.h
 */
class SuperSingleton
{
	public:
		SuperSingleton() // Constructor
		{
			cout << "Create SuperSingleton" << endl;
		}

		~SuperSingleton() // Destructor
		{
			cout << "Destroy SuperSingleton" << endl;
		}
};

/*
 * Singleton.h
 */
class Singleton : public SuperSingleton
{
	public:
		static Singleton *Instance(string str = "Initial String")
		{
			if (NULL == _instance)
			{
				_instance = new Singleton(str);
				static Cleaner clr; // static member clr
			}
			return _instance;
		}

		void Print()
		{
			cout << _str << endl;
		}

		~Singleton() // Destructor
		{
			cout << "Destroy Singleton" << endl;
		}

	private:
		static Singleton *_instance;

		string _str;

		Singleton(string str) // Constructor; Private
		{
			cout << "Create Singleton" << endl;
			_str = str;
		}

		Singleton(Singleton &) {}; // Copy Constructor
		Singleton &operator=(Singleton &temp) {}; // =

		/*
		 * Inner Class-Cleaner
		 * Cleaner类的唯一工作就是在析构函数中删除单件实例
		 * 定义为私有内嵌类，以防该类在其他地方被滥用
		 */
		class Cleaner
		{
			public:
				Cleaner()
				{
					cout << "Create Cleaner" << endl;
				}

				~Cleaner()
				{
					cout << "Destroy Cleaner" << endl;
					// Q：带参数时，不能去删除Instance方法，只能删除_instance指针？
					// Q：如果Singleton类中有多个指针变量怎么处理？一个一个指针地删除似乎太低效了。。。
					if (Singleton::_instance)
						delete Singleton::_instance;
					// 不能这样删除单件实例
					//if (Singleton::Instance(str))
					//	delete Singleton::Instance(str);
				}
		};

		// QA：写在这个位置无效，Why? 
		// static Cleaner clr;
};

/*
 * Singleton.cc
 */
Singleton *Singleton::_instance = NULL;

/*
 * Example.cc
 */
int main(int argc, char *argv[])
{
	// 也可以无参调用，这时的实例总是输出Initial String
	// Singleton::Instance()->Print();
	Singleton::Instance("Hello, world!")->Print();
	// 上一个Print时已创建了实例，这里不会再创建一次，所以仍然输出Hello, world!，不会输出Morning, everyone!
	Singleton::Instance("Morning, everyone!")->Print();

	return 0;
}
