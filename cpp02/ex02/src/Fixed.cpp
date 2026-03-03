/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:26:16 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/10 10:26:18 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{}

Fixed::Fixed(const Fixed &other)
{
	_rawBits = other._rawBits;
}

Fixed::Fixed(int const value)
{
	_rawBits = (value << _fractionalBits);
}

Fixed::Fixed(float const value)
{
	_rawBits = std::roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed(void)
{}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	_rawBits = other._rawBits;
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed sum;
	int rawBits = _rawBits + other._rawBits;
	sum.setRawBits(rawBits);
	return (sum);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	int rawBits = _rawBits - other._rawBits;
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long rawBits = static_cast<long long>(_rawBits) * other._rawBits;
	result.setRawBits(static_cast<int>(rawBits >> _fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed division;
	long long rawBits = (static_cast<long long>(_rawBits) << _fractionalBits);
	division.setRawBits(static_cast<int>(rawBits / other._rawBits));
	return (division);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;
	_rawBits++;
	return (temp);
}

Fixed &Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;
	_rawBits--;
	return (temp);
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
