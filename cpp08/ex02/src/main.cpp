/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:41 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:21 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main(void) {
	{
		std::cout << "TEST 1 (from subject):\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 2:\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		MutantStack<int> mstack_copy(mstack);
		std::cout << "Original contents:\n";
		for (auto &elem : mstack)
			std::cout << elem << std::endl;
		std::cout << "\nCopy contents:\n";
		for (auto &elem : mstack_copy)
			std::cout << elem << std::endl;
		std::cout << "\nPop one from original\n";
		mstack.pop();
		std::cout << "\nOriginal contents:\n";
		for (auto &elem : mstack)
			std::cout << elem << std::endl;
		std::cout << "\nCopy contents:\n";
		for (auto &elem : mstack_copy)
			std::cout << elem << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3:\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		MutantStack<int> mstack_copy;
		mstack_copy = mstack;
		std::cout << "Original contents:\n";
		for (auto &elem : mstack)
			std::cout << elem << std::endl;
		std::cout << "\nCopy contents:\n";
		for (auto &elem : mstack_copy)
			std::cout << elem << std::endl;
		std::cout << "\nPop one from original\n";
		mstack.pop();
		std::cout << "\nOriginal contents:\n";
		for (auto &elem : mstack)
			std::cout << elem << std::endl;
		std::cout << "\nCopy contents:\n";
		for (auto &elem : mstack_copy)
			std::cout << elem << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4:\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(4);
		mstack.push(3);
		mstack.push(2);
		mstack.push(1);
		std::cout << "Iterator:\n";
		for (auto it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "\nReverse iterator:\n";
		for (auto it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5:\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(4);
		mstack.push(3);
		mstack.push(2);
		mstack.push(1);
		const MutantStack<int> const_mstack(mstack);
		std::cout << "Const iterator:\n";
		for (auto it = const_mstack.cbegin(); it != const_mstack.cend(); ++it)
			std::cout << *it << std::endl;
		std::cout << "\nConst reverse iterator:\n";
		for (auto it = const_mstack.crbegin(); it != const_mstack.crend(); ++it)
			std::cout << *it << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5 (using vector and strings):\n\n";
		MutantStack<std::string, std::vector<std::string>> mstack;
		mstack.push("Test 1");
		mstack.push("Test 2");
		mstack.push("Test 3");
		mstack.push("Test 4");
		mstack.push("Test 5");
		std::cout << "Iterator:\n";
		for (auto it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "\nReverse iterator:\n";
		for (auto it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 6 (using list and float):\n\n";
		MutantStack<float, std::list<float>> mstack;
		mstack.push(0.1f);
		mstack.push(0.2f);
		mstack.push(0.3f);
		mstack.push(0.4f);
		mstack.push(0.5f);
		std::cout << "Iterator:\n";
		for (auto it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "\nReverse iterator:\n";
		for (auto it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << std::endl;
		std::cout << "____________________\n\n";
	}
	return 0;
}
