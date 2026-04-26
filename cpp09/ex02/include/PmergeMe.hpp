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
		static std::vector<std::vector<int>> _vMain;
		static std::vector<std::vector<int>> _vPend;
		static std::vector<std::vector<int>> _vNonParticipating;
		static std::vector<std::vector<int>> _vOdd;
		static std::chrono::duration<float>	 _vDuration;
		static int							 _vDepth;

		static void loadInputToVector(const int ac, char **av);
		static void vectorSortRecursion(void);
		static void vectorSortJacobstahl(void);

		// Deque:
		static std::deque<std::deque<int>>	 _dMain;
		static std::deque<std::deque<int>>	 _dPend;
		static std::vector<std::vector<int>> _dNonParticipating;
		static std::deque<std::deque<int>>	 _dOdd;
		static std::chrono::duration<float>	 _dDuration;
		static int							 _dDepth;

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
		static unsigned int getJacobstahlInIndex(unsigned int j);

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
