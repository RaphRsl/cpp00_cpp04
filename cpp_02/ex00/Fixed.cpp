/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:29 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 13:56:51 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "[Default constructor]" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "[Copy constructor]" << std::endl;
	*this = fixed;
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