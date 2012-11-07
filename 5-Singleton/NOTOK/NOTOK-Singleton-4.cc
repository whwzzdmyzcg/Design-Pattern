// 20120223
// longhua

/**
 * 带注册功能的单件模式
 * 单件模式本不适用于该类拥有子类的情况，这里使用一个容器来保存子类对象，形成一个带有注册功能的单件模式。这样，可以由父类来统一管理多个子类对象：需要时向父类注册子类，。
 * 当想集中管理一个应用程序所需的所有配置时，可以声明一个CToolsOptions的类，其中包含配置属性集合。对于这个类的实例，显然是一个实例就够了；当编写绘图程序时，考虑绘制矩形，圆形等分别使用CGraphTool派生的工具类，每个派生类负责处理具体的绘制动作和相关的UI相应逻辑。这些工具类典型的在被用户选择工具栏的图元按钮时被选中。依照这种模式，你应该对所有的图元工具从事注册工作，使得绘图程序了解运行时刻可以使用那些图元工具。
 */

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

// Singleton.h
class Singleton
{
	private:
		// 保存子类对象的map容器
		static map<string, Singleton*> mapSingleton;
	public:
		// 将对象添加到map容器中，即注册
		// name,表示对象，之后可据此获取对象
		static void registerInstance(string name, Singleton *ptrSingleton)
		{
			cout << "Register--" << name << endl;
			mapSingleton.insert(make_pair(name, ptrSingleton));
		}
		// 据对象注册时的名字从容器中获取对象
		static Singleton *getInstance(string name)
		{
			cout << "getInstance--" << name << endl;
			map<string, Singleton*>::const_iterator iter = mapSingleton.find(name);
			if (iter != mapSingleton.end())
				return (*iter).second;
			else
				return NULL;
		}
		// 重置instance
		// 如果您想要改变Singleton父类传回的子类Singleton，可以在 Singleton类别中加入一个reset()方法，将instance设定为null，然后重新设定环境变数，之后再利用 Singleton父类的getInstance()方法重新取得注册表中的其它子类。
		// Q:不懂这段是什么意思。。。
		static void reset(Singleton *instance)
		{
			instance = NULL;
		}
};

// Singleton.cc
map<string, Singleton*> Singleton::mapSingleton = map<string, Singleton*>();

// subSingleton.h
class subSingleton : public Singleton
{
	public:
		subSingleton(string _name)
		{
			// 注册
			name = _name;
			registerInstance(name, this);
			cout << "Registered--" << name << endl;
		}
		string getName()
		{
			cout << "getName--" << name << endl;
			return name;
		}
	private:
		string name;
};

// subSingleton2.h
class subSingleton2 : public Singleton
{
	public:
		subSingleton2(string _name)
		{
			// 注册
			name = _name;
			registerInstance(name, this);
			cout << "Registered--" << name << endl;
		}
		string getName()
		{
			cout << "getName--" << name << endl;
			return name;
		}
	private:
		string name;
};

// XXX.cc
int main(int argc, char *argv[])
{
	// 创建并注册对象
	new subSingleton("Summer");
	new subSingleton2("Spring");

	// 获取已注册对象
	subSingleton *ptrsubSingleton = (subSingleton *)Singleton::getInstance("Summer");
	if (ptrsubSingleton != NULL)
		cout << ptrsubSingleton->getName() << endl;
	else
		cout << "No such subSingleton Object..." << endl;
	// 获取已注册对象
	subSingleton2 *ptrsubSingleton2 = (subSingleton2 *)Singleton::getInstance("Spring");
	if (ptrsubSingleton2 != NULL)
		cout << ptrsubSingleton2->getName() << endl;
	else
		cout << "No such subSingleton Object..." << endl;

	return 0;
}
