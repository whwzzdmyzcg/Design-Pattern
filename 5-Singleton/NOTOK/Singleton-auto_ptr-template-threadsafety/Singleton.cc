// 20120226
// longhua

// Singleton.cc
template <typename T> auto_ptr<T> Singleton<T>::_instance;
template <typename T> ThreadSafety Singleton<T>::_ts;

template <typename T> inline T* Singleton<T>::Instance()
{
	if ( 0 == _instance.get())
	{
		ThreadSafety:: ts(_ts);
		if ( 0 == _instance.get())
		{
			_instance.reset(new T);
		}
	}
	return _instance.get();
}
