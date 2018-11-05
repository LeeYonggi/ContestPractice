#pragma once


template<class T>
class Singleton
{
private:
	static T *p;
public:
	static T *GetInstance()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		SAFE_DELETE(p);
	}
};

template<class T>
T *Singleton<T>::p = nullptr;