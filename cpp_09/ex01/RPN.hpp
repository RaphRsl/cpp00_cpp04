#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <exception>

class RPN {
    public:
        RPN(void);
        RPN(const RPN &rpn);
        ~RPN(void);

        RPN &operator=(const RPN &rpn);

        static bool check_valid(const std::string& str);
        static long long calculate(const std::string& expr);

        class ImpCalc : public std::exception
        {
            public:
                virtual const char* what() const throw();  
        };

        class DivBy0 : public std::exception
        {
            public:
                virtual const char* what() const throw();  
        };
};

#endif
