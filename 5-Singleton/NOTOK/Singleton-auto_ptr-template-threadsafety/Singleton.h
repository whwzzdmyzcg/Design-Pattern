// 20120226
// longhua

// Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <memory> // for auto_ptr
#include "ThreadSafety.h"

template <typename T> class Singleton
{
	public:
		static inline T* Instance();
	private:
		Singleton() {}
		~Singleton() {}
		Singleton(const Singleton&) {}
		Singleton & operator=(const Singleton&) {}

		static auto_ptr<T> _instance;
		static ThreadSafety _ts;
};

#endif /* _SINGLETON_H_*/
