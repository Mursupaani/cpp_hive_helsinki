#include "PmergeMe.hpp"

#include <cmath>
#include <cstddef>
#include <deque>
#include <vector>

std::chrono::duration<float> PmergeMe::_vecDuration{};
std::chrono::duration<float> PmergeMe::_deqDuration{};

// NOTE: Generic helper methods:
void PmergeMe::validateInputNumbers(const int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (!std::isdigit(av[i][j]))
				throw std::runtime_error("Invalid input " + std::string(av[i]));
		}
	}
}

// NOTE: Jacobstahl generation:
unsigned int PmergeMe::getJacobstahlInIndex(unsigned int i) {
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return (getJacobstahlInIndex(i - 1) + 2 * getJacobstahlInIndex(i - 2));
}

// NOTE: Vector sort:
void PmergeMe::vectorSort(const int ac, char **av) {
	PmergeMe::Timer				  timer(_vecDuration);
	std::vector<std::vector<int>> nonPart{};
	std::vector<std::vector<int>> pend{};
	std::vector<std::vector<int>> main =
		loadInput<std::vector<std::vector<int>>, std::vector<int>>(ac, av);
	SortRecursion<std::vector<std::vector<int>>, std::vector<int>>(main, pend,
																   0);
	printContainer(main);
}

// NOTE: Deque sort:
void PmergeMe::dequeSort(const int ac, char **av) {
	PmergeMe::Timer				timer(_deqDuration);
	std::deque<std::deque<int>> nonPart{};
	std::deque<std::deque<int>> pend{};
	std::deque<std::deque<int>> main =
		loadInput<std::deque<std::deque<int>>, std::deque<int>>(ac, av);
	SortRecursion<std::deque<std::deque<int>>, std::deque<int>>(main, pend, 0);
	printContainer(main);
}

// NOTE: PmergeMe::Timer:
PmergeMe::Timer::Timer(std::chrono::duration<float> &duration)
	: _duration(duration) {
	_start = std::chrono::steady_clock::now();
}

PmergeMe::Timer::~Timer(void) {
	_end = std::chrono::steady_clock::now();
	_duration = _end - _start;
}

std::chrono::duration<float> PmergeMe::getVDuration(void) {
	return (_vecDuration);
}

std::chrono::duration<float> PmergeMe::getDDuration(void) {
	return (_deqDuration);
}
