#include "PmergeMe.hpp"

#include <chrono>

std::vector<std::vector<int>>			 PmergeMe::_vMain;
std::vector<std::vector<int>>			 PmergeMe::_vPend;
std::vector<std::vector<int>>			 PmergeMe::_vOdd;
std::chrono::duration<float, std::milli> PmergeMe::_vDuration;

std::deque<std::deque<int>>				 PmergeMe::_dMain;
std::deque<std::deque<int>>				 PmergeMe::_dPend;
std::deque<std::deque<int>>				 PmergeMe::_dOdd;
std::chrono::duration<float, std::milli> PmergeMe::_dDuration;

void PmergeMe::validateElement(char *elem) {
	for (int i = 0; elem[i]; ++i) {
		if (!std::isdigit(elem[i]))
			throw std::runtime_error("Invaliv input " + std::string(elem));
	}
}

void PmergeMe::loadInputToVector(const int ac, char **av) {
	int a;
	int b;
	for (int i = 1; i < ac; ++i) {
		std::vector<int> v;
		if (i + 1 < ac) {
			validateElement(av[i]);
			validateElement(av[i + 1]);
			a = std::stoi(av[i]);
			b = std::stoi(av[++i]);
			if (a > b) {
				v.push_back(b);
				v.push_back(a);
			} else {
				v.push_back(a);
				v.push_back(b);
			}
		} else {
			validateElement(av[i]);
			a = std::stoi(av[i]);
			v.push_back(a);
		}
		_vMain.push_back(v);
	}
}

void PmergeMe::vectorSort(const int ac, char **av) {
	PmergeMe::Timer timer(_vDuration);
	loadInputToVector(ac, av);
	printContainer(_vMain);
}

std::chrono::duration<float, std::milli> PmergeMe::getVDuration(void) {
	return (_vDuration);
}

std::chrono::duration<float, std::milli> PmergeMe::getDDuration(void) {
	return (_dDuration);
}

PmergeMe::Timer::Timer(std::chrono::duration<float, std::milli> &duration)
	: _duration(duration) {
	_start = std::chrono::steady_clock::now();
}

PmergeMe::Timer::~Timer(void) {
	_end = std::chrono::steady_clock::now();
	_duration = _end - _start;
}
