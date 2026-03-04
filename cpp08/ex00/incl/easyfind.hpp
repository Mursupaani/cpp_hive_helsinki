#pragma once
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
auto &easyfind(T &container, int i) {
	auto it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::runtime_error(std::to_string(i) + " not found");
	return (*it);
}

template <typename T>
const auto &easyfind(const T &container, int i) {
	auto it = std::find(container.cbegin(), container.cend(), i);
	if (it == container.cend())
		throw std::runtime_error(std::to_string(i) + " not found");
	return (*it);
}
