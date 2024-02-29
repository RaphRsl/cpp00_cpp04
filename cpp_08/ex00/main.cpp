/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:36:20 by tblaase           #+#    #+#             */
/*   Updated: 2024/02/29 14:52:11 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

void test_list(void)
{
	std::list<int> testList;
	testList.push_back(42);
	testList.push_back(43);
	testList.push_back(55);
	
	std::list<int>::const_iterator	it = testList.end();

	std::cout << "===== Looking for 42 =====" << std::endl;
	try
	{
		it = ::easyfind(testList, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != testList.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	it = testList.end();

	std::cout << "===== Looking for 55 =====" << std::endl;
	try
	{
		it = ::easyfind(testList, 55);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != testList.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	it = testList.end();

	std::cout << "===== Looking for 52 =====" << std::endl;
	try
	{
		it = ::easyfind(testList, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != testList.end())
		std::cout << "\t-> " << *it << " found" << std::endl;
	return ;
}


void	test_vector(void)
{
	std::vector<char> testVector;
	testVector.push_back('T');
	testVector.push_back('e');
	testVector.push_back('s');
	testVector.push_back('t');
	testVector.push_back(' ');
	testVector.push_back('i');
	testVector.push_back('s');
	testVector.push_back(' ');
	testVector.push_back('O');
	testVector.push_back('K');
	testVector.push_back('!');

	std::cout << "===== Printing my entire vector =====" << std::endl;
	std::cout << "\tVector: " << std::flush;
	for(size_t i = 0; i < testVector.size(); i++)
	    std::cout << testVector[i] << std::flush;
	std::cout << std::endl;
	
	std::vector<char>::const_iterator	it = testVector.end();

	std::cout << "===== Looking for K =====" << std::endl;
	try
	{
		it = ::easyfind(testVector, 'K');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != testVector.end())
		std::cout << "\t-> " << *it << " found" << std::endl;

	it = testVector.end();

	std::cout << "===== Looking for N =====" << std::endl;
	try
	{
		it = ::easyfind(testVector, 'N');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != testVector.end())
		std::cout << "\t-> " << *it << " found" << std::endl;
	return ;
}

int main()
{
	std::cout << " <<<<< TEST LIST >>>>>" << std::endl;
	test_list();
	std::cout << std::endl;
	std::cout << " <<<<< TEST VECTOR >>>>>" << std::endl;
	test_vector();
	return (0);
}