#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <utility>

template <typename T>
class unique_ptr
{
	T *ptr = nullptr;
	
	unique_ptr(T *newObject): ptr {newObject} {}

public:

	unique_ptr() = default;
	~unique_ptr() { delete ptr; }

	unique_ptr(unique_ptr<T> &uptr) = delete;
	unique_ptr(unique_ptr<T> &&newObject): ptr {newObject.ptr}
	{
		newObject.ptr = nullptr;
	}

	unique_ptr& operator= (unique_ptr<T> &uptr) = delete;
	unique_ptr& operator= (unique_ptr<T> &&newObject) = delete;
	
	T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }
	
	template <typename T, class... Args>
	friend unique_ptr<T> make_unique(Args&&... args);
};

template <typename T, class... Args>
unique_ptr<T> make_unique(Args&&... args)
{
	return unique_ptr<T>(new T(args...));
}

#endif // UNIQUE_PTR_H
