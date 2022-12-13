#include "Vector.h"



template<typename T>
void Vector<T>::clear()
{
	delete[] _Ptr;
	_Ptr = nullptr;
	_Size = 0;
	_Capacity = 0;
}


template<typename T>
void Vector<T>::erase(const int index)
{
	T* tempPtr = new T[_Capacity];

	for (size_t i = 0; i < index; i++)
		tempPtr[i] = _Ptr[i];

	for (size_t i = index + 1; i < _Size; i++)
		tempPtr[i - 1] = _Ptr[i];

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	_Size--;

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = tempPtr[i];
}



template<typename T>
void Vector<T>::insert(size_t _Where, int _Val)
{
	if (_Where >= _Size)
		throw "Выход за границы вектора";


	if (_Capacity <= _Size)
	{
		T* tempPtr = new T[++_Capacity];

		for (size_t i = 0; i < _Size; i++)
			tempPtr[i] = _Ptr[i];

		delete[] _Ptr;
		_Ptr = new T[++_Capacity];

		for (size_t i = 0; i < _Size; i++)
			_Ptr[i] = tempPtr[i];
	}

	T* tempPtr = new T[_Capacity];

	for (size_t i = 0; i < _Where; i++)
		tempPtr[i] = _Ptr[i];

	tempPtr[_Where] = _Val;
	_Size++;

	for (size_t i = _Where + 1; i < _Size; i++)
		tempPtr[i] = _Ptr[i - 1];

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = tempPtr[i];
}



template<typename T>
void Vector<T>::shrink_to_fit() noexcept
{
	_Capacity = _Size;

	T* tempPtr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		tempPtr[i] = _Ptr[i];

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = tempPtr[i];
}



template<typename T>
void Vector<T>::pop_back() noexcept
{
	T* tempPtr = new T[_Capacity];
	_Size--;

	for (size_t i = 0; i < _Size; i++)
		tempPtr[i] = _Ptr[i];

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = tempPtr[i];
}





template<typename T>
void Vector<T>::push_back(const T _Val) noexcept
{
	if (_Capacity <= _Size)
	{
		T* tempPtr = new T[++_Capacity];

		for (size_t i = 0; i < _Size; i++)
			tempPtr[i] = _Ptr[i];

		delete[] _Ptr;
		_Ptr = new T[++_Capacity];

		for (size_t i = 0; i < _Size; i++)
			_Ptr[i] = tempPtr[i];
	}

	_Ptr[_Size] = _Val;
	_Size++;
}



template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& _Other)
{
	_Size = _Other.size();
	_Capacity = _Other.capacity();

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = _Other._Ptr[i];

	return *this;
}




template<typename T>
T& Vector<T>::operator[](size_t index)
{
	if (index < _Size)
	{
		auto ptr = _Ptr;

		for (size_t i = 0; i < index; i++)
			ptr++;
		return *ptr;
	}
	throw;
}



template<typename T>
Vector<T>::Vector() noexcept
{
	_Ptr = nullptr;
	_Size = 0;
	_Capacity = 0;
}



template<typename T>
Vector<T>::Vector(const Vector& _Right) noexcept
{
	_Size = _Right.size();
	_Capacity = _Right.capacity();

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = _Right._Ptr[i];
}



template<typename T>
Vector<T>::Vector(Vector&& _Right) noexcept
{
	_Size = move(_Right.size());
	_Capacity = move(_Right.capacity());

	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (size_t i = 0; i < _Size; i++)
		_Ptr[i] = _Right._Ptr[i];

	_Right._Ptr = nullptr;
	_Right._Size = 0;
	_Right._Capacity = 0;
}



template<typename T>
Vector<T>::Vector(std::initializer_list<T> _list)
	:Vector(_list.size())
{
	_Capacity = _list.size() * 2;
	auto it = _list.begin();
	auto e = _list.end();
	auto d = _Ptr;
	while (it != e) {
		(*d)++ = (*it)++;
	}
}


template<typename T>
Vector<T>::Vector(const size_t _Count, const T _Value)
	:_Size(_Count), _Capacity(_Count * 2)
{
	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (auto i = _Ptr; i < this->end(); ++i)
		*i = _Value;
}



template<typename T>
Vector<T>::Vector(const size_t _Count)
	:_Size(_Count), _Capacity(_Count * 2)
{
	delete[] _Ptr;
	_Ptr = new T[_Capacity];

	for (auto i = _Ptr; i < this->end(); ++i)
		*i = 0;
}



template<typename T>
const T* const Vector<T>::end() const
{
	return &this->_Ptr[_Size];
}
