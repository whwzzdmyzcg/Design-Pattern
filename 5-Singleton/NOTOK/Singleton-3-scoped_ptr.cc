
/**
 * 使用scoped_ptr让单件实例自动释放内存
 * 缺陷：需要安装boost库
 */
#include <iostream>
#include <boost/scoped_ptr.h> // for scoped_ptr

using std::cout;
using std::endl;
using std::scoped_ptr;

// Singleton.h
class Singleton
{
	public:
		static Singleton *Instance()
		{
			if (0 == _instance.get())
			{
				_instance = scoped_ptr<Singleton>(new Singleton());
				// or,_instance.reset(new Singleton);
			}
			return _instance.get();
		}
		~Singleton()
		{
			cout << "Destroy Singleton" << endl;
		}
	private:
		Singleton()
		{
			cout << "Create Singleton" << endl;
		}
		friend class scoped_ptr<Singleton>;
		static scoped_ptr<Singleton> _instance;
};

// Singleton.cc
scoped_ptr<Singleton> Singleton::_instance;

// XXX.cc
int main(int argc, char *argv[])
{
	Singleton::Instance();
}
