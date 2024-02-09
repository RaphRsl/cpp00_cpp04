/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:23:25 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 15:30:05 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static std::string	trueFalsePrint(bool b)
{
	if (b)
		return ("true!");
	return ("false!");
}

static void	testComparison(void)
{
	Fixed	a(4.87f);
	Fixed	b(9);

	std::cout << "------ COMPARISON ------" << std::endl;
	std::cout << "a = " << a << "  b = " << b << std::endl;
	std::cout << "  a > b ? " << trueFalsePrint(a > b) << std::endl;
	std::cout << "  a < b ? " << trueFalsePrint(a < b) << std::endl;
	std::cout << "  a >= b ? " << trueFalsePrint(a >= b) << std::endl;
	std::cout << "  a <= b ? " << trueFalsePrint(a <= b) << std::endl;
	std::cout << "  a == b ? " << trueFalsePrint(a == b) << std::endl;
	std::cout << "  a != b ? " << trueFalsePrint(a != b) << std::endl;
	b = a;
	std::cout << "a = " << a << "  b = " << b << std::endl;
	std::cout << "  a > b ? " << trueFalsePrint(a > b) << std::endl;
	std::cout << "  a < b ? " << trueFalsePrint(a < b) << std::endl;
	std::cout << "  a >= b ? " << trueFalsePrint(a >= b) << std::endl;
	std::cout << "  a <= b ? " << trueFalsePrint(a <= b) << std::endl;
	std::cout << "  a == b ? " << trueFalsePrint(a == b) << std::endl;
	std::cout << "  a != b ? " << trueFalsePrint(a != b) << std::endl;
}

static void	testArithmetic(void)
{
	Fixed	a(3.83f);
	Fixed	b(2);

	std::cout << "------ ARITHMETIC ------" << std::endl;
	std::cout << "a = " << a << "  b = " << b << std::endl;
	std::cout << "  a + b = " << a + b << std::endl;
	std::cout << "  a + a = " << a + a << std::endl;
	std::cout << "  a - b = " << a - b << std::endl;
	std::cout << "  a * b = " << a * b << std::endl;
	std::cout << "  a / b = " << a / b << std::endl;
}

static void	testIncrement(void)
{
	Fixed	a(1);

	std::cout << "------ INCREMENT/DECREMENT ------" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
}

static void	testMaxMin(void)
{
	Fixed		a(-3.11f);
	Fixed		b(3);
	Fixed const	c(3);

	std::cout << "------ MAX/MIN ------" << std::endl;
	std::cout << "a = " << a << "  b = " << b << std::endl;
	std::cout << "  max(a,b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "  min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a = " << a << "  c(const) = " << b << std::endl;
	std::cout << "  max(a,c) = " << Fixed::max(a, c) << std::endl;
	std::cout << "  min(a,c) = " << Fixed::min(a, c) << std::endl;
}

static void	testSubject(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "------ SUBJECT ------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

int	main(void)
{
	testSubject();
	testComparison();
	testArithmetic();
	testIncrement();
	testMaxMin();
	return (0);
}
