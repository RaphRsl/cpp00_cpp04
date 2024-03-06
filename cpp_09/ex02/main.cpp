#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"

unsigned int ft_str_to_uint(const std::string& str);

int main(int ac, char **av)
{
	if (ac == 1)
    {
        std::cout << "Expected format:   ./PmergeMe [unsigned int sequence]" << std::endl;
	    return EXIT_SUCCESS;
    }
    PmergeMe pmm;

    try {
        for (int i = 1; i < ac; i++)
            if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw PmergeMe::InvalidElementException();

        std::vector<unsigned int>vecCheck;
        for (int i = 1; i < ac; i++)
            vecCheck.push_back(ft_str_to_uint(av[i]));

        std::vector<unsigned int>::iterator it_1;
        std::vector<unsigned int>::iterator it_2;
        for (it_1 = vecCheck.begin(); it_1 != vecCheck.end(); it_1++)
        {
            for (it_2 = it_1 + 1; it_2 != vecCheck.end(); it_2++)
                if (*it_2 == *it_1)
			        throw PmergeMe::DoubleElementException();
        }
    }

    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    double vecUsedTime = pmm.vec_sort(ac, av);
    std::cout << std::endl;
    double listUsedTime = pmm.list_sort(ac, av);

    std::cout << "<vec>\tTime to process a range of " << ac - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << vecUsedTime << " µs" << std::endl;
	std::cout << "<list>\tTime to process a range of " << ac - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << listUsedTime << " µs" << std::endl;
         
	return EXIT_SUCCESS;
}
