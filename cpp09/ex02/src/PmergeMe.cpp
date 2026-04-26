#include "PmergeMe.hpp"

#include <cmath>
#include <cstddef>

std::vector<std::vector<int>> PmergeMe::_vMain;
std::vector<std::vector<int>> PmergeMe::_vPend;
std::vector<std::vector<int>> PmergeMe::_vNonParticipating;
std::vector<std::vector<int>> PmergeMe::_vOdd;
std::chrono::duration<float>  PmergeMe::_vDuration;
int							  PmergeMe::_vDepth = 0;

std::deque<std::deque<int>>	  PmergeMe::_dMain;
std::deque<std::deque<int>>	  PmergeMe::_dPend;
std::vector<std::vector<int>> PmergeMe::_dNonParticipating;
std::deque<std::deque<int>>	  PmergeMe::_dOdd;
std::chrono::duration<float>  PmergeMe::_dDuration;
int							  PmergeMe::_dDepth = 0;

// NOTE: Generic helper methods:
void PmergeMe::validateElement(char *elem) {
	for (int i = 0; elem[i]; ++i) {
		if (!std::isdigit(elem[i]))
			throw std::runtime_error("Invalid input " + std::string(elem));
	}
}

unsigned int PmergeMe::getJacobstahlInIndex(unsigned int j) {
	if (j == 0)
		return (0);
	if (j == 1)
		return (1);
	return (getJacobstahlInIndex(j - 1) + 2 * getJacobstahlInIndex(j - 2));
}

// NOTE: Vector methods:
void PmergeMe::vectorSort(const int ac, char **av) {
	PmergeMe::Timer timer(_vDuration);
	loadInputToVector(ac, av);
	std::cout << "\nBefore sort:\n";
	std::cout << "\nMain:\n";
	printContainer(_vMain);
	std::cout << "\nNon participating:\n";
	printContainer(_vPend);
	std::cout << "\n______________________________\n";
	vectorSortRecursion();
}

void PmergeMe::loadInputToVector(const int ac, char **av) {
	int a;
	for (int i = 1; i < ac; ++i) {
		std::vector<int> v;
		validateElement(av[i]);
		a = std::stoi(av[i]);
		if (duplicateFoundInContainer(_vMain, a))
			continue;
		v.push_back(a);
		_vMain.push_back(v);
	}
}

void PmergeMe::vectorSortRecursion(void) {
	if (_vMain.size() < 2) {
		--_vDepth;
		vectorSortJacobstahl();
		return;
	}
	for (size_t i = 0; i < _vMain.size(); ++i) {
		if (_vMain[i + 1].size() == pow(2, _vDepth)) {
			if (*_vMain[i].rbegin() < *_vMain[i + 1].rbegin()) {
				_vMain[i].insert(_vMain[i].end(), _vMain[i + 1].begin(),
								 _vMain[i + 1].end());
				_vMain.erase(_vMain.begin() + i + 1);
			} else {
				_vMain[i + 1].insert(_vMain[i + 1].end(), _vMain[i].begin(),
									 _vMain[i].end());
				_vMain.erase(_vMain.begin() + i);
			}
		} else {
			_vNonParticipating.push_back(_vMain[i]);
			_vMain.erase(_vMain.begin() + i);
		}
	}
	{
		std::cout << "Recursion depth: " << _vDepth << std::endl;
		std::cout << "\nAfter sort:\n";
		std::cout << "size: " << _vMain.size() << std::endl;
		std::cout << "\nMain:\n";
		printContainer(_vMain);
		std::cout << "\nNon participating:\n";
		printContainer(_vNonParticipating);
		std::cout << "\n______________________________\n";
	}
	++_vDepth;
	vectorSortRecursion();
}

void PmergeMe::vectorSortJacobstahl(void) {
	if (_vDepth < 0)
		return;
	if ((*_vNonParticipating.rbegin()).size() == pow(2, _vDepth)) {
		_vPend.push_back(*_vNonParticipating.rbegin());
		_vNonParticipating.erase(_vNonParticipating.end() - 1);
	}
	size_t setSize = pow(2, _vDepth);
	for (int i = 0; static_cast<size_t>(i) < _vMain.size(); ++i) {
		if (_vMain[i].size() == 2 * setSize) {
			std::vector<int> v;
			for (size_t j = 0; j < setSize; ++j) {
				v.push_back(_vMain[i][0]);
				_vMain[i].erase(_vMain[i].begin());
			}
			_vMain.insert(_vMain.cend(), v);
		}
	}
	{
		std::cout << "\nDepth: " << _vDepth << std::endl;
		std::cout << "\nMain (size " << _vMain.size() << "):\n";
		printContainer(_vMain);
		std::cout << "\nPend:\n";
		printContainer(_vPend);
	}
	--_vDepth;
	vectorSortJacobstahl();
}

// NOTE: PmergeMe::Timer:
std::chrono::duration<float> PmergeMe::getVDuration(void) {
	return (_vDuration);
}

std::chrono::duration<float> PmergeMe::getDDuration(void) {
	return (_dDuration);
}

PmergeMe::Timer::Timer(std::chrono::duration<float> &duration)
	: _duration(duration) {
	_start = std::chrono::steady_clock::now();
}

PmergeMe::Timer::~Timer(void) {
	_end = std::chrono::steady_clock::now();
	_duration = _end - _start;
}

// void PmergeMe::loadInputToVector(const int ac, char **av) {
// 	int	 a;
// 	int	 b;
// 	bool duplicateFound;
// 	for (int i = 1; i < ac; ++i) {
// 		std::vector<int> v;
// 		if (i + 1 < ac) {
// 			validateElement(av[i]);
// 			a = std::stoi(av[i]);
// 			if (duplicateFoundInContainer(_vMain, a))
// 				continue;
// 			validateElement(av[i + 1]);
// 			while (++i < ac) {
// 				b = std::stoi(av[i]);
// 				duplicateFound = duplicateFoundInContainer(_vMain, b) || a == b;
// 				if (duplicateFound)
// 					continue;
// 				else
// 					break;
// 			}
// 			if (duplicateFound == false) {
// 				v.push_back(std::min(a, b));
// 				v.push_back(std::max(a, b));
// 			} else
// 				v.push_back(a);
// 		} else {
// 			validateElement(av[i]);
// 			a = std::stoi(av[i]);
// 			if (duplicateFoundInContainer(_vMain, a))
// 				continue;
// 			v.push_back(a);
// 		}
// 		_vMain.push_back(v);
// 	}
// }
