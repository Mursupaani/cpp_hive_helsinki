#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
auto &easyfind(T container, int i) {
	auto it = std::find(container.begin(), container.end(), i);
	return (it);
	throw std::runtime_error("Value not found in container");
}
