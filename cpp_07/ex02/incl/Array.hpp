#pragma once
#include <initializer_list>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Array {
	private:
		T	  *_array;
		size_t _size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(std::initializer_list<T> init);
		Array(const Array &other);
		Array &operator=(Array other);
		~Array(void);

		unsigned int size(void) const;
		T			&operator[](const unsigned int i);
		const T		&operator[](const unsigned int i) const;
};

template <typename T>
Array<T>::Array(void) : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(const unsigned int n) : _array(new T[n]{}), _size(n) {}

template <typename T>
Array<T>::Array(std::initializer_list<T> init)
	: _array(new T[init.size()]), _size(init.size()) {
	int i = 0;
	for (const auto &element : init) {
		_array[i] = element;
		++i;
	}
}

template <typename T>
Array<T>::Array(const Array &other)
	: _array(new T[other._size]), _size(other._size) {
	for (size_t i = 0; i < _size; ++i)
		_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> other) {
	std::swap(_array, other._array);
	std::swap(_size, other._size);
	return (*this);
}

template <typename T>
T &Array<T>::operator[](const unsigned int i) {
	if (i < 0 || i >= _size)
		throw(std::out_of_range("Index " + std::to_string(i) +
								" is out of range."));
	return (_array[i]);
}

template <typename T>
const T &Array<T>::operator[](const unsigned int i) const {
	if (i < 0 || i >= _size)
		throw(std::out_of_range("Index " + std::to_string(i) +
								" is out of range."));
	return (_array[i]);
}

template <typename T>
Array<T>::~Array<T>(void) {
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (_size);
}
