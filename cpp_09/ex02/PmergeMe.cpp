#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <sstream>
#include <list>
#include "PmergeMe.hpp"

// ---------- DEFAULT/COPY CONSTRUCTORS - DESTRUCTOR - OPERATOR= ----------

PmergeMe::PmergeMe(void)
{
    if (VERBOSE)
        std::cout << "PmergeMe - default constructor" << std::endl;
    return ;
};

PmergeMe::PmergeMe(const PmergeMe& pmm)
{
    if (VERBOSE)
        std::cout << "PmergeMe - copy constructor" << std::endl;
    *this = pmm;
}

PmergeMe::~PmergeMe(void)
{    
    if (VERBOSE)
        std::cout << "PmergeMe - default destructor" << std::endl;
    return ;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& pmm)
{
    if (VERBOSE)
    {
        std::cout << "PmergeMe - operator =" << std::endl;
    }
	(void)pmm;
	return *this;
}


// ---------- UTILS ----------

unsigned int ft_str_to_uint(const std::string& str)
{
	unsigned int nb;
	std::stringstream sstream(str);

	sstream >> nb;
	return nb;
}


// ---------- VECTOR ----------

static void vec_print(std::vector<unsigned int>& vectorSort)
{
	std::vector<unsigned int>::const_iterator itVec;
	for (itVec = vectorSort.begin(); itVec != vectorSort.end(); itVec++)
		std::cout << *itVec << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> vec_merge(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
    std::vector<unsigned int> vectorSorted;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            vectorSorted.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            vectorSorted.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        vectorSorted.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
	{
        vectorSorted.push_back(right.front());
        right.erase(right.begin());
    }
    return vectorSorted;
}

static std::vector<unsigned int> vec_merge_insert(std::vector<unsigned int>& vectorSort) {
    if (vectorSort.size() <= 1)
        return vectorSort;

    int middle = vectorSort.size() / 2;
    std::vector<unsigned int> left(vectorSort.begin(), vectorSort.begin() + middle);
    std::vector<unsigned int> right(vectorSort.begin() + middle, vectorSort.end());

    left = vec_merge_insert(left);
    right = vec_merge_insert(right);

    return vec_merge(left, right);
}

double PmergeMe::vec_sort(int ac, char **av)
{
	std::vector<unsigned int> vectorSort;

	for (int i = 1; i < ac; i += 1)
		vectorSort.push_back(ft_str_to_uint(av[i]));

	std::cout << "<vec>\tBefore: " << std::flush;
	vec_print(vectorSort);

	std::clock_t start = std::clock();

	vectorSort = vec_merge_insert(vectorSort);

	double usedTime = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000000;

	std::cout << "<vec>\tAfter: " << std::flush;
	vec_print(vectorSort);

	return (usedTime);
}


// ---------- LIST ----------

static void list_print(std::list<unsigned int>& listSort)
{
	std::list<unsigned int>::const_iterator itList;
	for (itList = listSort.begin(); itList != listSort.end(); itList++)
		std::cout << *itList << " ";
	std::cout << std::endl;
}

static std::list<unsigned int> list_merge(std::list<unsigned int>& left, std::list<unsigned int>& right)
{
    std::list<unsigned int> listSorted;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            listSorted.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            listSorted.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        listSorted.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
	{
        listSorted.push_back(right.front());
        right.erase(right.begin());
    }
    return listSorted;
}

static std::list<unsigned int> list_merge_insert(std::list<unsigned int>& listSort) {
    if (listSort.size() <= 1)
        return listSort;

    int middle = listSort.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

    for (int i = 0; i < middle; i++)
    {
        left.push_back(listSort.front());
        listSort.pop_front();
    }
    right = listSort;

    left = list_merge_insert(left);
    right = list_merge_insert(right);

    return list_merge(left, right);
}

double PmergeMe::list_sort(int ac, char **av)
{
	std::list<unsigned int> listSort;

	for (int i = 1; i < ac; i += 1)
		listSort.push_back(ft_str_to_uint(av[i]));

    std::cout << "<list>\tBefore: " << std::flush;
	list_print(listSort);

	std::clock_t start = std::clock();

	listSort = list_merge_insert(listSort);

	double usedTime = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000000;

    std::cout << "<list>\tAfter: " << std::flush;
	list_print(listSort);
    std::cout << std::endl;

    return (usedTime);
}


// ---------- EXCEPTIONS ----------

const char*	PmergeMe::InvalidElementException::what() const throw()
{
	return "PmergeMe exception: invalid element in the sequence.";
}

const char*	PmergeMe::DoubleElementException::what() const throw()
{
	return "PmergeMe exception: element twice in the sequence.";
}