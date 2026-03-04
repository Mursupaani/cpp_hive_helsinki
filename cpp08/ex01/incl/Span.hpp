#pragma once
#include <algorithm>
#include <climits>
#include <random>
#include <stdexcept>
#include <vector>

class Span {
	private:
		std::vector<int> _data;
		size_t			 _maxSize;

	public:
		Span(void) = delete;
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void		 addNumber(const unsigned int num);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		void		 fillSpanRandom(const int smallest, const int largest);

		template <typename Iter>
		void fillSpan(Iter begin, Iter end) {
			unsigned int count = std::distance(begin, end);
			if ((_data.size() + count) > _maxSize)
				throw std::runtime_error("Adding " + std::to_string(count) +
										 " would overflow container.");
			_data.insert(_data.end(), begin, end);
		}
};
