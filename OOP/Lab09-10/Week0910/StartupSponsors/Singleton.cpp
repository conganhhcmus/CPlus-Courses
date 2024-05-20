#include "Singleton.h"

template < class T >
T& Singleton<T>::getInstance() {
	if (_instance == nullptr) {
		_instance = new T();
	}

	return *_instance;
}

template<class T>
T* Singleton<T>::_instance = nullptr;