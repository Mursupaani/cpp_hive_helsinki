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
		static std::vector<std::vector<int>>			_vMain;
		static std::vector<std::vector<int>>			_vPend;
		static std::vector<std::vector<int>>			_vOdd;
		static std::chrono::duration<float, std::milli> _vDuration;

		static std::deque<std::deque<int>>				_dMain;
		static std::deque<std::deque<int>>				_dPend;
		static std::deque<std::deque<int>>				_dOdd;
		static std::chrono::duration<float, std::milli> _dDuration;

		static void loadInputToVector(const int ac, char **av);
		static void validateElement(char *elem);

	public:
		PmergeMe(void) = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe(void) = delete;

		static void vectorSort(const int ac, char **av);
		static std::chrono::duration<float, std::milli> getVDuration(void);
		static std::chrono::duration<float, std::milli> getDDuration(void);

		class Timer {
			private:
				std::chrono::duration<float, std::milli>		  &_duration;
				std::chrono::time_point<std::chrono::steady_clock> _start, _end;

			public:
				Timer(std::chrono::duration<float, std::milli> &duration);
				~Timer();
		};

		template <typename T>
		static void printContainer(T container) {
			int i = 0;
			for (const auto &elem : container) {
				// std::cout.width(3);
				std::cout << std::setw(3) << std::right;
				std::cout << i++ << ": | ";
				for (const auto &e : elem) {
					std::cout << e << " | ";
				}
				std::cout << std::endl;
			}
		}
};
