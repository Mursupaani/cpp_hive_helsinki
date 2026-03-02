#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
	_data.reserve(N);
}

Span::Span(const Span &other){
	_data = other._data;
}

Span &Span::operator=(const Span &other){
	if (this == &other)
		return (*this);
	_data = other._data;
	return (*this);
}

Span::~Span(void){}

void Span::addNumber(const unsigned int num)
{
	if (_data.size() < _maxSize)
		_data.push_back(num);
	else
		throw std::runtime_error("Couldn't add " + std::to_string(num) + ". Span is already full.");
}

unsigned int Span::shortestSpan(void) const
{
	size_t size = _data.size();
	if (size < 2)
		throw std::runtime_error("Can't find span when size is " + std::to_string(_data.size()));
	std::vector<int> sortedCopy = _data;
	std::sort(sortedCopy.begin(), sortedCopy.end());
	unsigned int span = UINT_MAX;
	for (size_t i = 0; i < sortedCopy.size() - 1; ++i)
	{
		unsigned int temp = sortedCopy[i + 1] - sortedCopy[i];
		if (temp < span)
			span = temp;
	}
	return (span);
}

unsigned int Span::longestSpan(void) const{
	if (_data.size() < 2)
		throw std::runtime_error("Can't find span when size is " + std::to_string(_data.size()));
	auto [minIt, maxIt] = std::minmax_element(_data.begin(), _data.end());
	return (*maxIt - *minIt);
}

void Span::fillSpan(const unsigned int count) {
	(void)count;
}

// FIXME: delete me
#include <iostream>
void Span::printSpan(){
	for (auto val : _data)
		std::cout << val << "\n";
}
