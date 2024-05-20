#pragma once

template < class T >
class Singleton {
private:
	static T* _instance;

public:
	static T& getInstance();

	Singleton() = delete;
	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton) = delete;
};