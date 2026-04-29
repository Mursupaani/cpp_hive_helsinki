#pragma once
#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <string>
#include <vector>

class PmergeMe {
	private:
		// FIXME: Debug printing:
		template <typename ContCont, typename Cont>
		static void printPend(ContCont pend, Cont order) {
			for (size_t i = 0; i < pend.size(); ++i) {
				std::cout << std::setw(3) << std::right;
				std::cout << i << ": | ";
				for (const auto &e : pend[i]) {
					std::cout << e << " | ";
				}
				std::cout << "\tJ: " << order[i] << std::endl;
			}
		}

		template <typename ContCont, typename Cont>
		static void printState(ContCont main, ContCont nonPart, ContCont pend,
							   int recDepth, bool printRecDepth,
							   Cont *insertOrder) {
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
		// FIXME: Remove above^^

		static std::chrono::duration<float> _vecDuration;
		static std::chrono::duration<float> _deqDuration;

		template <typename ContCont, typename Cont>
		static ContCont loadInput(const int ac, char **av) {
			int		 a;
			ContCont main{};
			for (int i = 1; i < ac; ++i) {
				Cont v;
				a = std::stoi(av[i]);
				if (duplicateFoundInContainer(main, a))
					continue;
				v.push_back(a);
				main.push_back(v);
			}
			return (main);
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

			// INFO: Create new main from split parts
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
			main = std::move(newMain);

			// INFO: Generate vecPend from main.
			auto bVecIt = main.begin() + 2;
			while (bVecIt != main.end()) {
				pend.insert(pend.end(), *bVecIt);
				bVecIt = main.erase(bVecIt);
				if (bVecIt == main.end()) {
					break;
				}
				++bVecIt;
			}

			// INFO: If an element in nonPart matches the size of current
			// set add it to pend.
			if (nonPart.size() > 0) {
				auto nonPartIt = nonPart.rbegin();
				if (nonPartIt->size() == setSize) {
					pend.push_back(std::move(*nonPartIt));
					nonPart.pop_back();
				}
			}
			Cont insertOrder = buildJacobstahlSequence<Cont>(pend.size());

			// INFO: If an element in nonPart matches the size of current
			// set
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

		// INFO: Generic:

	public:
		PmergeMe(void) = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe(void) = delete;

		static void							vectorSort(const int ac, char **av);
		static void							dequeSort(const int ac, char **av);
		static std::chrono::duration<float> getVDuration(void);
		static std::chrono::duration<float> getDDuration(void);
		static unsigned int getJacobstahlInIndex(unsigned int j);
		static void			validateInputNumbers(const int ac, char **av);

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

		template <typename T>
		static void printContainer(T container) {
			int i = 0;
			for (const auto &elem : container) {
				std::cout << std::setw(3) << std::right;
				std::cout << i++ << ": | ";
				for (const auto &e : elem) {
					std::cout << e << " | ";
				}
				std::cout << std::endl;
			}
		}
};
