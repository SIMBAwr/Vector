#pragma once

#include <initializer_list>

template<typename T>
class Vector
{
private:
	T* _Ptr;
	size_t _Size;
	size_t _Capacity;

public:

	explicit Vector() noexcept;
	explicit Vector(const Vector& _Right) noexcept;
	explicit Vector(Vector&& _Right) noexcept;
	Vector(std::initializer_list<T> _list);
	Vector(const size_t _Count, const T _Value);
	Vector(const size_t _Count);
	~Vector() { delete[] _Ptr; }

	T* begin() const { return &_Ptr[0]; }
	T* end() const;

	const size_t size() const noexcept { return _Size; };
	const size_t capacity() const noexcept { return _Capacity; };
	void push_back(const T _Val) noexcept;
	void pop_back() noexcept;
	void shrink_to_fit() noexcept;
	void insert(size_t _Where, int _Val);

	T& operator[](size_t index);
	Vector<T>& operator=(const Vector<T>& _Other);


};