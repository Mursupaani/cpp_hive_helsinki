#pragma once
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ratio>
#include <string>
#include <vector>

class PmergeMe {
	public:
		PmergeMe(void) = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe(void) = delete;

		static std::vector<std::vector<int>> vectorSort(const int ac,
														char	**av);
		static std::deque<std::deque<int>>	 dequeSort(const int ac, char **av);
		static std::chrono::duration<float>	 getVDuration(void);
		static std::chrono::duration<float>	 getDDuration(void);
		static size_t						 getNumOfElements(void);
		static void validateInputNumbers(const int ac, char **av);
		static void printResults(std::vector<std::vector<int>> &sortedVec);

		template <typename ContCont>
		static void printResults(int ac, char **av,
								 const ContCont &sortedCont) {
			std::cout << "Before:\t";
			for (int i = 1; i < ac; ++i) {
				std::cout << av[i];
				if (i < ac - 1) {
					std::cout << " ";
				}
			}
			std::cout << "\nAfter:\t";
			printContainer(sortedCont);
			std::cout << "\nTime to process a range of " << _numOfElems
					  << " elements with std::vector\t: "
					  << PmergeMe::getVDuration().count() * 1000 << " ms";
			std::cout << "\nTime to process a range of " << _numOfElems
					  << " elements with std::deque\t: "
					  << PmergeMe::getDDuration().count() * 1000 << " ms";
			std::cout << std::endl;
		}

		class Timer {
			private:
				std::chrono::duration<float>					  &_duration;
				std::chrono::time_point<std::chrono::steady_clock> _start, _end;

			public:
				Timer() = delete;
				Timer(std::chrono::duration<float> &duration);
				Timer(const PmergeMe::Timer &other) = delete;
				Timer &operator=(const PmergeMe::Timer &other) = delete;
				~Timer();
		};

	private:
		static std::chrono::duration<float> _vecDuration;
		static std::chrono::duration<float> _deqDuration;
		static size_t						_numOfElems;

		static unsigned int getJacobstahlInIndex(unsigned int j);

		template <typename ContCont>
		static bool duplicateFoundInContainer(const ContCont &container,
											  const int		  elem) {
			if (container.size() == 0)
				return (false);
			for (const auto &container : container) {
				for (const auto &containerElem : container) {
					if (elem == containerElem) {
						return (true);
					}
				}
			}
			return (false);
		}

		template <typename ContCont>
		static void printContainer(const ContCont &container) {
			auto mainIt = container.begin();
			for (; mainIt != container.end(); ++mainIt) {
				auto it = mainIt->begin();
				for (; it != mainIt->end(); ++it) {
					std::cout << *it;
					if (mainIt + 1 != container.end())
						std::cout << " ";
				}
			}
		}

		template <typename ContCont, typename Cont>
		static size_t loadInput(const int ac, char **av, ContCont &main) {
			size_t numOfElements{};
			int	   a;
			for (int i = 1; i < ac; ++i) {
				Cont v;
				a = std::stoi(av[i]);
				if (duplicateFoundInContainer(main, a))
					continue;
				v.push_back(a);
				main.push_back(v);
				++numOfElements;
			}
			return (numOfElements);
		}

		template <typename ContCont, typename Cont>
		static void SortRecursion(ContCont &main, ContCont &nonPart,
								  int recursionDepth) {
			if (main.size() < 2) {
				SortJacobstahl<ContCont, Cont>(main, nonPart, --recursionDepth);
				return;
			}

			auto mainIt = main.begin();
			while (mainIt != main.end()) {
				if ((mainIt + 1) != main.end()) {
					auto nextIt = mainIt + 1;
					if (mainIt->back() < nextIt->back()) {
						mainIt->insert(mainIt->end(), nextIt->begin(),
									   nextIt->end());
						mainIt = main.erase(nextIt);
					} else {
						nextIt->insert(nextIt->end(), mainIt->begin(),
									   mainIt->end());
						mainIt = main.erase(mainIt);
						++mainIt;
					}
				} else {
					nonPart.push_back(std::move(*mainIt));
					mainIt = main.erase(mainIt);
				}
			}
			SortRecursion<ContCont, Cont>(main, nonPart, ++recursionDepth);
		}

		template <typename ContCont, typename Cont>
		static void SortJacobstahl(ContCont &main, ContCont &nonPart,
								   int recursionDepth) {
			if (recursionDepth < 0)
				return;
			ContCont pend{};
			size_t	 setSize = std::pow(2, recursionDepth);

			ContCont newMain{};
			{
				for (auto &innerVec : main) {
					if (innerVec.size() > setSize) {
						Cont firstHalf(innerVec.begin(),
									   innerVec.begin() + setSize);
						Cont secondHalf(innerVec.begin() + setSize,
										innerVec.end());
						newMain.push_back(firstHalf);
						newMain.push_back(secondHalf);
					}
				}
			}
			main = newMain;

			auto bVecIt = main.begin() + 2;
			while (bVecIt != main.end()) {
				pend.insert(pend.end(), *bVecIt);
				bVecIt = main.erase(bVecIt);
				if (bVecIt == main.end()) {
					break;
				}
				++bVecIt;
			}

			if (nonPart.size() > 0) {
				auto nonPartIt = nonPart.rbegin();
				if (nonPartIt->size() == setSize) {
					pend.push_back(*nonPartIt);
					nonPart.pop_back();
				}
			}
			Cont insertOrder = buildJacobstahlSequence<Cont>(pend.size());

			size_t addedCount{};
			for (auto idx : insertOrder) {
				size_t limit = idx + addedCount + 2;
				auto   pendIt = pend.begin() + idx;
				auto   searchRangeEnd = main.begin() + limit;
				auto   insertPos =
					std::upper_bound(main.begin(), searchRangeEnd, *pendIt,
									 [](const Cont &a, const Cont &b) {
										 return (a.back() < b.back());
									 });
				main.insert(insertPos, *pendIt);
				++addedCount;
			}
			pend.erase(pend.begin(), pend.end());
			SortJacobstahl<ContCont, Cont>(main, nonPart, --recursionDepth);
		}

		template <typename Cont>
		static Cont buildJacobstahlSequence(const size_t pendSize) {
			Cont sequence{};
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
};
