#pragma once
#include <iostream>
#include <stack>
#include <stdexcept>

class RPN {
	private:
		static std::stack<int> _stack;

	public:
		RPN(void) = delete;
		RPN(const RPN &other) = delete;
		RPN &operator=(const RPN &other) = delete;
		~RPN(void) = delete;

		static void calculate(const std::string &input);
};
