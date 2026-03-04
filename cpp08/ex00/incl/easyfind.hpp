#pragma once
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
auto &easyfind(T &container, int find) {
	auto it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::runtime_error(std::to_string(find) + " not found");
	return (*it);
}

template <typename T>
const auto &easyfind(const T &container, int find) {
	auto it = std::find(container.cbegin(), container.cend(), find);
	if (it == container.cend())
		throw std::runtime_error(std::to_string(find) + " not found");
	return (*it);
}
