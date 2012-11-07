// 20120226
// longhua

/**
 * 利用模板实现单件
 */

// Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <memory> // for auto_ptr

template <typename T> class T
{
	public:
		static inline T* instance();
	private:
		T() {}
		~T() {}
		T(const T&) {}
		T & operator=(const T&) {}

		static auto_ptr<T> _instance;
};

#endif /* _SINGLETON_H_*/
