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

#include "Serializer.hpp"

int main(void) {
	{
		std::cout << "TEST 1 WITH HEAP:\n\n";
		Data *data = new Data;
		data->string = "This is important data.";
		data->value = 42;

		uintptr_t serialized = Serializer::serialize(data);
		std::cout << "Original pointer value: " << data << "\n";
		std::cout << "Serialized uintptr_t value: " << serialized << "\n\n";
		Data *deserialized = Serializer::deserialize(serialized);
		std::cout << "Original pointer value: " << data << "\n";
		std::cout << "Serialized uintptr_t value: " << deserialized << "\n\n";

		std::cout << "Data in original pointer:\n";
		std::cout << data->string << "\n";
		std::cout << data->value << "\n\n";
		std::cout << "Data in deserialized pointer:\n";
		std::cout << deserialized->string << "\n";
		std::cout << deserialized->value << "\n\n";
		delete data;
	}
	{
		std::cout << "TEST 2 WITH STACK:\n\n";
		Data data;
		data.string = "This is very, VERY important data.";
		data.value = 84;

		uintptr_t serialized = Serializer::serialize(&data);
		std::cout << "Original struct address: " << &data << "\n";
		std::cout << "Serialized uintptr_t value: " << serialized << "\n\n";
		Data *deserialized = Serializer::deserialize(serialized);
		std::cout << "Original struct address: " << &data << "\n";
		std::cout << "Serialized uintptr_t value: " << deserialized << "\n\n";

		std::cout << "Data in struct:\n";
		std::cout << data.string << "\n";
		std::cout << data.value << "\n\n";
		std::cout << "Data in deserialized pointer:\n";
		std::cout << deserialized->string << "\n";
		std::cout << deserialized->value << "\n\n";
	}
	{
		std::cout << "TEST 3 WITH NULLPTR:\n\n";
		Data *data = nullptr;

		uintptr_t serialized = Serializer::serialize(data);
		std::cout << "Original pointer value: " << data << "\n";
		std::cout << "Serialized uintptr_t value: " << serialized << "\n\n";
		Data *deserialized = Serializer::deserialize(serialized);
		std::cout << "Original pointer value: " << data << "\n";
		std::cout << "Serialized uintptr_t value: " << deserialized << "\n\n";

		if (data) {
			std::cout << "Data in original pointer:\n";
			std::cout << data->string << "\n";
			std::cout << data->value << "\n\n";
			delete data;
		}
		if (deserialized) {
			std::cout << "Data in deserialized pointer:\n";
			std::cout << deserialized->string << "\n";
			std::cout << deserialized->value << "\n\n";
		}
	}
}
