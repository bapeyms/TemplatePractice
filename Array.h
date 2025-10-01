#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T = double>
class Array
{
	static int count;
	T* ptr;
	int size;
public:
	Array() : ptr(new T[1]), size(1) 
	{ 
		++count; 
	}
	Array(int size) : ptr(new T[size]), size(size) 
	{ 
		++count; 
	}

	Array(const Array<T>& obj);
	Array& operator=(const Array& obj);
	~Array() 
	{ 
		delete[] this->ptr; 
	--count; 
	}

	void FillArray();
	void PrintArray();

	int getSize() const 
	{ 
		return this->size; 
	}

	T& operator[] (int index)
	{
		return index >= 0 && index < size ? ptr[index] : ptr[0];
	}
	const T& operator[] (int index) const
	{
		return index >= 0 && index < size ? ptr[index] : ptr[0];
	}
	Array operator+(const Array<T>& obj);

	static int GetInstanceCount()
	{
		return count;
	}
};

template <typename T>
void Array<T>::FillArray()
{
	for (int i = 0; i < this->size; ++i)
	{
		ptr[i] = rand() % 50;
	}
}

template <typename T>
void Array<T>::PrintArray()
{
	using std::cout;
	using std::endl;
	for (int i = 0; i < this->size; ++i)
	{
		cout << ptr[i] << " ";
	}
	cout << endl;
}

template<typename T>
inline Array<T> Array<T>::operator+(const Array<T>& obj)
{
	int newSize;
	if (size > obj.size)
	{
		newSize = size;
	}
	else
	{
		newSize = obj.size;
	}
	Array<T> newArr(newSize);
	for (int i = 0; i < newSize; i++)
	{
		T left = 0;
		T right = 0;
		if (i < size)
		{
			left = ptr[i];
		}
		if (i < obj.size)
		{
			right = obj.ptr[i];
		}
		newArr[i] = left + right;
	}
	return newArr;
}


template <typename T>
Array<T>::Array(const Array<T>& obj)
{
	this->size = obj.size;
	this->ptr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		this->ptr[i] = obj.ptr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return *this;

	this->size = obj.size;
	delete[]this->ptr;
	this->ptr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		this->ptr[i] = obj.ptr[i];
	}

	++count;
	return *this;
}

template <typename TInner>
int Array<TInner>::count;

template <>
int Array<double>::count = -1;