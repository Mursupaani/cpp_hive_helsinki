#include "Span.hpp"

#include <vector>

Span::Span(unsigned int N) : _maxSize(N) {
	_data.reserve(N);
}

Span::Span(const Span &other) : _data(other._data), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return (*this);
	_data = other._data;
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(const unsigned int num) {
	if (_data.size() < _maxSize)
		_data.push_back(num);
	else
		throw std::runtime_error("Couldn't add " + std::to_string(num) +
								 ". Span is already full.");
}

unsigned int Span::shortestSpan(void) const {
	size_t size = _data.size();
	if (size < 2)
		throw std::runtime_error("Can't find span when size is " +
								 std::to_string(_data.size()));
	std::vector<int> sortedCopy(this->_data);
	std::sort(sortedCopy.begin(), sortedCopy.end());
	std::vector<unsigned int> spans(_maxSize, 0);
	std::adjacent_difference(sortedCopy.begin(), sortedCopy.end(),
							 spans.begin());
	return (*std::min_element(spans.begin() + 1, spans.end()));
}

unsigned int Span::longestSpan(void) const {
	if (_data.size() < 2)
		throw std::runtime_error("Can't find span when size is " +
								 std::to_string(_data.size()));
	auto [minIt, maxIt] = std::minmax_element(_data.begin(), _data.end());
	return (*maxIt - *minIt);
}

void Span::fillSpanRandom(const int smallest, const int largest) {
	unsigned int toAdd = _maxSize - _data.size();
	if (toAdd < 1) {
		throw std::runtime_error("Container is already full");
	}
	if (smallest >= largest) {
		throw std::runtime_error("Smallest has to be smaller than largest");
	}
	std::vector<int>::iterator oldEnd = _data.end();
	_data.resize(_maxSize);
	std::random_device				   rd;
	std::mt19937					   algo(rd());
	std::uniform_int_distribution<int> range(smallest, largest);
	std::generate(oldEnd, _data.end(), [&]() { return (range(algo)); });
}
