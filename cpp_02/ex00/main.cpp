/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:35 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 14:04:30 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	std::cout << "-> Fixed a" << std::endl;
	Fixed	a;
	std::cout << "--------" << std::endl;
	std::cout << "-> Fixed b(a)" << std::endl;
	Fixed	b(a);
	std::cout << "--------" << std::endl;
	std::cout << "-> Fixed c" << std::endl;
	Fixed	c;
	std::cout << "--------" << std::endl;

	std::cout << "-> c = b" << std::endl;
	c = b;
	std::cout << "--------" << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}
