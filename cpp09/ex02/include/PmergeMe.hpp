#pragma once
#include <chrono>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <string>
#include <vector>

class PmergeMe {
	private:
		// Vector:
		static std::vector<std::vector<int>> _vecMain;
		static std::vector<std::vector<int>> _vecPend;
		static std::vector<std::vector<int>> _vecNonPart;
		static std::vector<std::vector<int>> _vecOdd;
		static std::chrono::duration<float>	 _vecDuration;
		static int							 _vecDepth;

		static void loadInputToVector(const int ac, char **av);
		static void vectorSortRecursion(void);
		static void vectorSortJacobstahl(void);

		// Deque:
		static std::deque<std::deque<int>>	 _deqMain;
		static std::deque<std::deque<int>>	 _deqPend;
		static std::vector<std::vector<int>> _deqNonPart;
		static std::deque<std::deque<int>>	 _deqOdd;
		static std::chrono::duration<float>	 _deqDuration;
		static int							 _deqDepth;

		// Generic:
		static void validateElement(char *elem);

	public:
		PmergeMe(void) = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe(void) = delete;

		static void							vectorSort(const int ac, char **av);
		static std::chrono::duration<float> getVDuration(void);
		static std::chrono::duration<float> getDDuration(void);
		static unsigned int		   getJacobstahlInIndex(unsigned int j);
		static std::vector<size_t> buildJacobstahlSequence(
			const size_t pendSize);

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

		template <typename T>
		static bool duplicateFoundInContainer(const T  &containers,
											  const int elem) {
			if (containers.size() == 0)
				return (false);
			for (const auto &container : containers) {
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
