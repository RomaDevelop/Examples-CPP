#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <utility>

template <typename T>
class unique_ptr
{
	T *ptr = nullptr;

public:

	unique_ptr() = default;
	~unique_ptr() { if(ptr) delete ptr; }

	unique_ptr(T *newObject)
	{
		if(ptr) delete ptr;
		ptr = newObject;
	}

	unique_ptr(unique_ptr<T> &uptr) = delete;
	unique_ptr(unique_ptr<T> &&newObject)
	{
		*this = std::move(newObject);
	}

	unique_ptr& operator= (unique_ptr<T> &uptr) = delete;
	unique_ptr& operator= (unique_ptr<T> &&newObject)
	{
		if(ptr) delete ptr;
		ptr = newObject.ptr;
		newObject.ptr = nullptr;
	}
};

template <typename T, class... Args>
unique_ptr<T> make_unique(Args&&... args)
{
	return unique_ptr<T>(new T(args...));
}

#endif // UNIQUE_PTR_H
