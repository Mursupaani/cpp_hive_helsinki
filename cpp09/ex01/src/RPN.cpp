#include "RPN.hpp"

std::stack<int> RPN::_stack;

void RPN::calculate(const std::string &input) {
	for (size_t i = 0; i < input.length(); ++i) {
		char current = input[i];
		if (std::isdigit(current)) {
			_stack.push(current - '0');
		} else if (_operators.find(current) != std::string::npos) {
			if (_stack.size() < 2) {
				throw(std::runtime_error("ERROR: Invalid input"));
			}
			switch (current) {
				int operand;
				case '+':
					operand = _stack.top();
					_stack.pop();
					_stack.top() += operand;
					break;
				case '-':
					operand = _stack.top();
					_stack.pop();
					_stack.top() -= operand;
					break;
				case '*':
					operand = _stack.top();
					_stack.pop();
					_stack.top() *= operand;
					break;
				case '/':
					operand = _stack.top();
					if (operand == 0)
						throw(std::runtime_error("ERROR: Division by zero"));
					_stack.pop();
					_stack.top() /= operand;
					break;
			}
		} else
			throw(std::runtime_error("ERROR: Invalid input"));
		if (std::isspace(input[++i]) || input[i] == '\0')
			continue;
		else
			throw(std::runtime_error("ERROR: Invalid input"));
	}
	if (_stack.size() != 1)
		throw(std::runtime_error("ERROR: Invalid input"));
	std::cout << _stack.top() << std::endl;
}
