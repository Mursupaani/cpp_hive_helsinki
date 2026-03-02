#pragma once
#include <vector>

class Span
{
private:
	std::vector<int> _data;
	size_t			_maxSize;
public:
	Span(void) = delete;
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	void addNumber(const unsigned int num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
	void fillSpan(const unsigned int count);

	//FIXME: delete me:
	void printSpan();
};
