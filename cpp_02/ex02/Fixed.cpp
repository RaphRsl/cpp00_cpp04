/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:23:07 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 15:14:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	if (VERBOSE_LOG)
		std::cout << "[Default constructor]" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	if (VERBOSE_LOG)
		std::cout << "[Copy constructor]" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int n) : _fixedPoint(n << _numberFracBits)
{
	if (VERBOSE_LOG)
		std::cout << "[Int constructor]" << std::endl;
}

Fixed::Fixed(const float f) : _fixedPoint((int)roundf(f * (1 << _numberFracBits)))
{
	if (VERBOSE_LOG)
		std::cout << "[Float constructor]" << std::endl;
}

Fixed::~Fixed()
{
	if (VERBOSE_LOG)
		std::cout << "[Destructor]" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (VERBOSE_LOG)
		std::cout << "[Copy assignment operator]" << std::endl;
	if (this != &fixed)
		this->_fixedPoint = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	if (VERBOSE_LOG)
		std::cout << "[getRawBits function]" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(const int raw)
{
	if (VERBOSE_LOG)
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

// 6 COMPARISON OPERATORS //

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_fixedPoint > fixed._fixedPoint);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_fixedPoint < fixed._fixedPoint);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_fixedPoint >= fixed._fixedPoint);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_fixedPoint <= fixed._fixedPoint);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_fixedPoint == fixed._fixedPoint);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_fixedPoint != fixed._fixedPoint);
}

// 4 ARITHMETIC OPERATORS //

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

// 4 INCREMENT/DECREMENT OPERATORS //

Fixed	&Fixed::operator++(void)
{
	++(this->_fixedPoint);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--(this->_fixedPoint);
	return (*this);
}

Fixed	Fixed::operator++(int n)
{
	Fixed	temp(*this);

	if (n >= 0)
	{
		for (int i = 0; i <= n; i++)
			++(*this);
	}
	else
	{
		for (int i = 0; i <= (-n); i++)
			--(*this);
	}
	return (temp);
}

Fixed	Fixed::operator--(int n)
{
	Fixed	temp(*this);

	if (n >= 0)
	{
		for (int i = 0; i <= n; i++)
			--(*this);
	}
	else
	{
		for (int i = 0; i <= (-n); i++)
			++(*this);
	}
	return (temp);
}

// 4 STATIC FUNCTIONS //

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (VERBOSE_LOG)
		std::cout << "[Static min function]" << std::endl;
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (VERBOSE_LOG)
		std::cout << "[Static max function]" << std::endl;
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (VERBOSE_LOG)
		std::cout << "[Static const min function]" << std::endl;
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (VERBOSE_LOG)
		std::cout << "[Static const max function]" << std::endl;
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}
