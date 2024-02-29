/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:36:20 by tblaase           #+#    #+#             */
/*   Updated: 2024/02/29 13:24:34 by rsl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int main()
{
	std::list<int> test_list;
	test_list.push_back(42);
	test_list.push_back(43);
	test_list.push_back(55);
	
	std::list<int>::const_iterator	it = test_list.end();

	std::cout << "===== Looking for 42 =====" << std::endl;
	try
	{
		it = ::easyfind(test_list, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test_list.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	it = test_list.end();

	std::cout << "===== Looking for 55 =====" << std::endl;
	try
	{
		it = ::easyfind(test_list, 55);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test_list.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	it = test_list.end();

	std::cout << "===== Looking for 52 =====" << std::endl;
	try
	{
		it = ::easyfind(test_list, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test_list.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	return (0);
}