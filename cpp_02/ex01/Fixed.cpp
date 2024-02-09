/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:10:01 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 14:14:01 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "[Default constructor]" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "[Copy constructor]" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int n) : _fixedPoint(n << _numberFracBits)
{
	std::cout << "[Int constructor]" << std::endl;
	return ;
}

Fixed::Fixed(const float f) : _fixedPoint((int)roundf(f * (1 << _numberFracBits)))
{
	std::cout << "[Float constructor]" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "[Destructor]" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "[Copy assignment operator]" << std::endl;
	if (this != &fixed)
		this->_fixedPoint = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "[getRawBits function]" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "[setRawBits function]" << std::endl;
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (1 << _numberFracBits));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)_fixedPoint / (1 << _numberFracBits))));
}

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
