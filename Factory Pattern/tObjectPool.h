#pragma once
#include <vector>
#include "SimpleSprite.h"

template<typename T>
class tObjectPool
{
public:
	//std::vector<SimpleSprite*> vec;

	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	T* pool;							// all objects stored in the pool
	bool* free = true;					// indicates whether an object is available
	size_t count;

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
inline tObjectPool<T>::tObjectPool()
{
}

template<typename T>
inline tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	pool = new tObjectPool [initialCapacity];
}

template<typename T>
inline tObjectPool<T>::~tObjectPool()
{

}

template<typename T>
inline T * tObjectPool<T>::retrieve()
{
	for (int i = 0; i <= count; i++)
	{
		if (pool[i].free == true)
		{
			pool[i].free == false;
			return &pool[i];
		}
		else
		{
			return NULL;
		}
	}
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj)
{
	pool[obj].free == true;
}

template<typename T>
inline size_t tObjectPool<T>::capacity()
{
	return pool.capacity();
}
