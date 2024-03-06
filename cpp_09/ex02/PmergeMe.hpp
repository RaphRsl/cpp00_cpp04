#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# define VERBOSE 0
# include <exception> //needed ?

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& pmm);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe& pmm);

        void sortVec(int argc, char **argv);
        void sortList(int argc, char **argv);

        class InvalidElementException : public std::exception
        {
            public:
                virtual const char* what() const throw();  
        };
};

#endif
