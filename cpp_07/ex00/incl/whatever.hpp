#pragma once
#include <concepts>

template <typename T>
concept Comparable = requires(const T &a, const T &b) {
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
	{ a < b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <Comparable T>
T &min(T &a, T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <Comparable T>
T &max(T &a, T &b) {
	if (a > b)
		return (a);
	return (b);
}
