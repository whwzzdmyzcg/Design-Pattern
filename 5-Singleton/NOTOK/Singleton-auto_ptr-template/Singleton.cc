// 20120226
// longhua

// Singleton.cc
template <typename T> auto_ptr<T> T<T>::_instance;

template <typename T> inline T* T<T>::instance()
{
	if ( 0 == _instance.get())
	{
		_instance.reset(new T);
	}
	return _instance.get();
}
