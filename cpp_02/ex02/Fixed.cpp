/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:23:07 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 11:33:22 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	if (CALL_LOG)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	if (CALL_LOG)
		std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int n) : _fixedPoint(n << _numberFracBits)
{
	if (CALL_LOG)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixedPoint((int)roundf(f * (1 << _numberFracBits)))
{
	if (CALL_LOG)
		std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	if (CALL_LOG)
		std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (CALL_LOG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixedPoint = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	if (CALL_LOG)
		std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(const int raw)
{
	if (CALL_LOG)
		std::cout << "setRawBits member function called" << std::endl;
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

// COMPARISON OPERATORS //

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

// ARITHMETIC OPERATORS //

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

// INCREMENT OPERATORS //

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

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (CALL_LOG)
		std::cout << "Static min function called" << std::endl;
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (CALL_LOG)
		std::cout << "Static max function called" << std::endl;
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (CALL_LOG)
		std::cout << "Static const min overload called" << std::endl;
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (CALL_LOG)
		std::cout << "Static const max overload called" << std::endl;
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}
