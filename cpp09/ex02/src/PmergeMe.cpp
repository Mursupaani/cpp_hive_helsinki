#include "PmergeMe.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iterator>
#include <utility>
#include <vector>

std::vector<std::vector<int>> PmergeMe::_vecMain{};
std::vector<std::vector<int>> PmergeMe::_vecPend{};
std::vector<std::vector<int>> PmergeMe::_vecNonPart{};
std::chrono::duration<float>  PmergeMe::_vecDuration{};
int							  PmergeMe::_vecDepth{};

std::deque<std::deque<int>>	  PmergeMe::_deqMain{};
std::deque<std::deque<int>>	  PmergeMe::_deqPend{};
std::vector<std::vector<int>> PmergeMe::_deqNonPart{};
std::chrono::duration<float>  PmergeMe::_deqDuration{};
int							  PmergeMe::_deqDepth{};

// FIXME: Debug printing:
template <typename T>
static void printPend(T pend, std::vector<size_t> order) {
	for (size_t i = 0; i < pend.size(); ++i) {
		std::cout << std::setw(3) << std::right;
		std::cout << i << ": | ";
		for (const auto &e : pend[i]) {
			std::cout << e << " | ";
		}
		std::cout << "\tJ: " << order[i] << std::endl;
	}
}

template <typename T>
static void printState(T main, T nonPart, T pend, int recDepth,
					   bool printRecDepth, std::vector<size_t> *insertOrder) {
	{
		if (printRecDepth) {
			std::cout << "Recursion depth: " << recDepth << std::endl;
		}
		std::cout << "\nMain ( size: " << main.size() << " ) :\n";
		PmergeMe::printContainer(main);
		std::cout << "\nNon Participating ( size: " << nonPart.size()
				  << " ) :\n";
		PmergeMe::printContainer(nonPart);
		std::cout << "\nPending ( size: " << pend.size() << " ) :\n";
		if (insertOrder) {
			printPend(pend, *insertOrder);
		} else {
			PmergeMe::printContainer(pend);
		}
		std::cout << "\n______________________________\n";
	}
}

// NOTE: Generic helper methods:
void PmergeMe::validateElement(char *elem) {
	for (int i = 0; elem[i]; ++i) {
		if (!std::isdigit(elem[i]))
			throw std::runtime_error("Invalid input " + std::string(elem));
	}
}

// NOTE: Jacobstahl sequence generation:
unsigned int PmergeMe::getJacobstahlInIndex(unsigned int i) {
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return (getJacobstahlInIndex(i - 1) + 2 * getJacobstahlInIndex(i - 2));
}

std::vector<size_t> PmergeMe::buildJacobstahlSequence(const size_t pendSize) {
	std::vector<size_t> sequence{};
	if (pendSize == 0) {
		return (sequence);
	}
	int	   jacobIndex = 3;
	size_t prevJacob = 1;
	while (true) {
		size_t curJacob = getJacobstahlInIndex(jacobIndex++);
		size_t groupStart = std::min(pendSize + 1, curJacob);
		for (; groupStart > prevJacob; --groupStart) {
			sequence.push_back(groupStart - 2);
		}
		if (curJacob >= pendSize + 1) {
			return (sequence);
		}
		prevJacob = curJacob;
	}
	return (sequence);
}

// NOTE: Vector methods:
void PmergeMe::vectorSort(const int ac, char **av) {
	PmergeMe::Timer timer(_vecDuration);
	loadInputToVector(ac, av);
	{
		std::cout << "Before sorting:\n";
		printState(_vecMain, _vecNonPart, _vecPend, _vecDepth, false, nullptr);
	}
	vectorSortRecursion();
}

void PmergeMe::loadInputToVector(const int ac, char **av) {
	int a;
	for (int i = 1; i < ac; ++i) {
		std::vector<int> v;
		validateElement(av[i]);
		a = std::stoi(av[i]);
		if (duplicateFoundInContainer(_vecMain, a))
			continue;
		v.push_back(a);
		_vecMain.push_back(v);
	}
}

void PmergeMe::vectorSortRecursion(void) {
	if (_vecMain.size() < 2) {
		--_vecDepth;
		vectorSortJacobstahl();
		return;
	}

	auto mainIt = _vecMain.begin();
	while (mainIt != _vecMain.end()) {
		if ((mainIt + 1) != _vecMain.end()) {
			auto nextIt = mainIt + 1;
			if (mainIt->back() < nextIt->back()) {
				mainIt->insert(mainIt->end(), nextIt->begin(), nextIt->end());
				_vecMain.erase(nextIt);
				++mainIt;
			} else {
				nextIt->insert(nextIt->end(), mainIt->begin(), mainIt->end());
				mainIt = _vecMain.erase(mainIt);
				++mainIt;
			}
		} else {
			_vecNonPart.push_back(std::move(*mainIt));
			mainIt = _vecMain.erase(mainIt);
		}
	}
	{ printState(_vecMain, _vecNonPart, _vecPend, _vecDepth, true, nullptr); }
	++_vecDepth;
	vectorSortRecursion();
}

void PmergeMe::vectorSortJacobstahl(void) {
	if (_vecDepth < 0)
		return;
	size_t setSize = pow(2, _vecDepth);

	// INFO: Create new main from split parts
	std::vector<std::vector<int>> newMain{};
	{
		for (auto &innerVec : _vecMain) {
			if (innerVec.size() > setSize) {
				std::vector<int> firstHalf(innerVec.begin(),
										   innerVec.begin() + setSize);
				std::vector<int> secondHalf(innerVec.begin() + setSize,
											innerVec.end());
				newMain.push_back(firstHalf);
				newMain.push_back(secondHalf);
			}
		}
	}
	_vecMain = std::move(newMain);

	// INFO: Generate _vecPend from _vecMain.
	auto bVecIt = _vecMain.begin() + 2;
	while (bVecIt != _vecMain.end()) {
		_vecPend.insert(_vecPend.end(), *bVecIt);
		bVecIt = _vecMain.erase(bVecIt);
		if (bVecIt == _vecMain.end()) {
			break;
		}
		++bVecIt;
	}

	// INFO: If an element in _vecNonPart matches the size of current set
	// add it to pend.
	if (_vecNonPart.size() > 0) {
		auto nonPartIt = _vecNonPart.rbegin();
		if (nonPartIt->size() == setSize) {
			_vecPend.push_back(std::move(*nonPartIt));
			_vecNonPart.pop_back();
		}
	}
	std::vector<size_t> insertOrder = buildJacobstahlSequence(_vecPend.size());
	{
		std::cout << "\nBefore sorting:\n";
		printState(_vecMain, _vecNonPart, _vecPend, _vecDepth, true,
				   &insertOrder);
	}

	// INFO: If an element in _vecNonPart matches the size of current set
	size_t addedCount{};
	for (auto idx : insertOrder) {
		size_t limit = idx + addedCount + 2;
		auto   pendIt = _vecPend.begin() + idx;
		auto   searchRangeEnd = _vecMain.begin() + limit;
		auto   insertPos = std::upper_bound(
			  _vecMain.begin(), searchRangeEnd, *pendIt,
			  [](const std::vector<int> &a, const std::vector<int> &b) {
				  return (a.back() < b.back());
			  });
		_vecMain.insert(insertPos, *pendIt);
		for (auto e : *pendIt) {
			std::cout << " | " << e;
		}
		std::cout << " | limit: " << limit << std::endl;
		++addedCount;
	}
	_vecPend.erase(_vecPend.begin(), _vecPend.end());
	{
		std::cout << "\nAfter sorting:\n";
		printState(_vecMain, _vecNonPart, _vecPend, _vecDepth, true, nullptr);
		std::cout << "\n______________________________\n";
	}

	--_vecDepth;
	vectorSortJacobstahl();
}

// NOTE: PmergeMe::Timer:
std::chrono::duration<float> PmergeMe::getVDuration(void) {
	return (_vecDuration);
}

std::chrono::duration<float> PmergeMe::getDDuration(void) {
	return (_deqDuration);
}

PmergeMe::Timer::Timer(std::chrono::duration<float> &duration)
	: _duration(duration) {
	_start = std::chrono::steady_clock::now();
}

PmergeMe::Timer::~Timer(void) {
	_end = std::chrono::steady_clock::now();
	_duration = _end - _start;
}
