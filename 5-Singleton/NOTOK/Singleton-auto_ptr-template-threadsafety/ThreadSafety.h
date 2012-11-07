// 20120226
// longhua

#ifndef _THREADSAFETY_H_
#define _THREADSAFETY_H_
/**
 * Instances of this clas will be accessed by multiple threads. So,
 * all members of this class(except the constructor and detructor) must be thread-safe.
 * For Windows
 */
class ThreadSafety
{
	public:
		ThreadSafety()
		{
			guardcount = 0;
			InitializeCriticalSection(&_cs);
		}
		~ThreadSafety()
		{
			DeleteCriticalSection(&_cs);
		}
		// isGuarded is used for debugging
		bool isGuarded() const
		{
			return (guardcount>0);
		}

		// inner class
		class Safety
		{
			public:
				Safety(ThreadSafety& ts):_ts(ts)
				{
					_rg.Guard();
				}
				~Safety()
				{
					_rg.unGuard();
				}
			private:
				ThreadSafety& _ts;
		};
	private:
		void Guard()
		{
			EnterCriticalSection(&_cs);
			guardcount++;
		}
		void unGuard()
		{
			guardcount--;
			LeaveCriticalSection(&_cs);
		}
		// Guard/unGuard can only be accessed by the inner class Safety
		friend class ThreadSafety::Safety;

		CRITICAL_SECTION _cs;
		long guardcount;
};
#endif /*_THREADSAFETY_H_*/
