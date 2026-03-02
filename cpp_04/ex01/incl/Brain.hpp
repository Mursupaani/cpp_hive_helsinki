/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:29:41 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/19 13:10:28 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
	unsigned int _currentIdea;
public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);

	std::string getIdea(const int i);
	void setIdea(const std::string idea);
};
