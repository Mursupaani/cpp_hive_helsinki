#pragma once
#include <deque>
#include <iostream>
#include <stack>
#include <string>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T> &other);
		MutantStack<T> &operator=(const MutantStack<T> &other);
		~MutantStack<T>(void);
};
