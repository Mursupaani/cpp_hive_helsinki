#pragma once
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		using StackType = typename std::stack<T, Container>;
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator =
			typename Container::const_reverse_iterator;
		MutantStack(void) {};
		MutantStack(const MutantStack<T> &other) : StackType(other) {};
		MutantStack &operator=(const MutantStack<T, Container> &other) {
			if (this == &other)
				return (*this);
			this->StackType::operator=(other);
			return (*this);
		};
		~MutantStack(void) {};

		iterator begin() {
			return (this->c.begin());
		}
		iterator end() {
			return (this->c.end());
		}
		const_iterator cbegin() const {
			return (this->c.cbegin());
		}
		const_iterator cend() const {
			return (this->c.cend());
		}
		reverse_iterator rbegin() {
			return (this->c.rbegin());
		}
		reverse_iterator rend() {
			return (this->c.rend());
		}
		const_reverse_iterator crbegin() const {
			return (this->c.crbegin());
		}
		const_reverse_iterator crend() const {
			return (this->c.crend());
		}
};
