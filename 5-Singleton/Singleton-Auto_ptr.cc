/*
 * =====================================================================================
 *
 *       Filename:  Singleton-Auto_ptr.cc
 *
 *    Description:  使用auto_ptr让单件实例自动释放内存
 *
 *        Version:  1.0
 *        Created:  02/23/2012 07:31:44 PM
 *       Modified:  02/26/2012 07:31:44 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Rachel
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory> // auto_ptr

using std::cout;
using std::endl;
using std::string;
using std::auto_ptr;

/*
 * Singleton.h
 */
class Singleton
{
	public:
		static Singleton *Instance(string str = "Initial String")
		{
			if (0 == _instance.get()) // 使用get成员检测auto_ptr对象
			{
				_instance = auto_ptr<Singleton>(new Singleton(str));
				// OR
				// _instance.reset(new Singleton(str));
			}

			return _instance.get();
		}

		~Singleton() // Destructor
		{
			cout << "Destroy Singleton" << endl;
		}

		void Print()
		{
			cout << str << endl;
		}

	private:
		Singleton(string _str) // Constructor; Private
		{
			cout << "Create Singleton" << endl;
			str = _str;
		}

		string str;
		friend class auto_ptr<Singleton>;
		static auto_ptr<Singleton> _instance;
};

/*
 * Singleton.cc
 */
auto_ptr<Singleton> Singleton::_instance;

/*
 * Example.cc
 */
int main(int argc, char *argv[])
{
	// 无参调用，输出Initial String
	// Singleton::Instance()->Print();
	
	Singleton::Instance("Hello World")->Print();

	return 0;
}
