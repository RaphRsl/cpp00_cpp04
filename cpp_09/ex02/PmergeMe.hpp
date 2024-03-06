#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# define VERBOSE 0

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& pmm);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe& pmm);

        double vec_sort(int argc, char **argv);
        double list_sort(int argc, char **argv);

        class InvalidElementException : public std::exception
        {
            public:
                virtual const char* what() const throw();  
        };

        class DoubleElementException : public std::exception
        {
            public:
                virtual const char* what() const throw();  
        };
};

#endif
