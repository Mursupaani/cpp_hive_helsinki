#pragma once
#include <cstddef>

template <typename T, typename Func>
void iter(T *array, const size_t size, Func func) {
	if (!array)
		return;
	for (size_t i = 0; i < size; ++i) {
		func(array[i]);
	}
}
