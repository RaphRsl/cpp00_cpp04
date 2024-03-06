#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "RPN.hpp"

RPN::RPN(void)
{
    return ;
}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

RPN::~RPN(void)
{
    return ;
}


RPN& RPN::operator=(const RPN &rpn) {
	(void)rpn;
    return *this;
}

static int ft_stoi(const std::string& str)
{
    int nb;
    std::stringstream sstream(str);

    sstream >> nb;
    return nb;
}

bool RPN::check_valid(const std::string& str)
{
    if (str.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return true;
	return false;
}

long long RPN::calculate(const std::string& expr)
{
    int left;
    int right;
    int res;
    std::stringstream ssExpr(expr);
    std::stack<int> myStack;
    std::string strExpr;

    while (ssExpr >> strExpr)
    {
        if (strExpr == "+" || strExpr == "-" || strExpr == "/" || strExpr == "*")
        {
            if (myStack.size() < 2)
                throw ImpCalc();                
            right = myStack.top();
            myStack.pop();
            left = myStack.top();
            myStack.pop();
            switch (strExpr.at(0))
            {
                case '+': res =  left + right ; break;
                case '-': res =  left - right ; break;
                case '/':
                    if (right != 0)
                        res =  left / right; 
                    else
                        throw DivBy0();
                break;
                case '*': res =  left * right ; break;
            }
            myStack.push(res);
        }
        else
            myStack.push(ft_stoi(strExpr));
    }
	return myStack.top();
}

const char*	RPN::ImpCalc::what() const throw()
{
	return "Error: wrong expression, calculation impossible.";
}

const char*	RPN::DivBy0::what() const throw()
{
	return "Error: dividing by 0 is not allowed, calculation impossible.";
}
