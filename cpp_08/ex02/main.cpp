
#include "MutantStack.hpp"

void test_from_subject(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int my_test(void)
{
	std::cout << "--> String stack" << std::endl;
	MutantStack<std::string> str_mstack;
	str_mstack.push("One");
	str_mstack.push("Two");
	str_mstack.pop();
	str_mstack.push("Three");
	str_mstack.push("Forty Two");

	std::cout << "--> Int stack" << std::endl;
	MutantStack<int> int_mstack;
	int_mstack.push(1);		
	int_mstack.push(2);	
	int_mstack.pop();		
	int_mstack.push(3);		
	int_mstack.push(42);

	std::cout << std::endl;

	std::cout << "--> String stack - iterators creation" << std::endl;
	MutantStack<std::string>::iterator str_it_beg = str_mstack.begin();
	MutantStack<std::string>::iterator str_it_end = str_mstack.end();
	++str_it_beg;
	--str_it_beg;
	std::cout << "--> String stack iteration:\n";
	while (str_it_beg != str_it_end)
	{
		std::cout << "\t[" << *str_it_beg << "]\n";
		++str_it_beg;
	}

	std::cout << "\n\t> Information \n\tSize: " << str_mstack.size() << "\n\tEmpty: " << (str_mstack.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl << "\n\t(Pop 3 elements from the string stack)" << std::endl;
	str_mstack.pop();
	str_mstack.pop();
	str_mstack.pop();
	std::cout << "\t> Information \n\tSize: " << str_mstack.size() << "\n\tEmpty: " << (str_mstack.empty() ? "true" : "false") << std::endl;

	std::cout << std::endl;

	std::cout << "--> Int stack - iterators creation" << std::endl;
	MutantStack<int>::iterator int_it_beg = int_mstack.begin();
	MutantStack<int>::iterator int_it_end = int_mstack.end();
	++int_it_beg;
	--int_it_beg;
	std::cout << "--> Int stack iteration:\n";
	while (int_it_beg != int_it_end)
	{
		std::cout << "\t[" << *int_it_beg << "]\n";
		++int_it_beg;
	}

	std::cout << "\n\t> Information \n\tSize: " << int_mstack.size() << "\n\tEmpty: " << (int_mstack.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl << "\n\t(Pop 2 elements from the int stack)" << std::endl;
	int_mstack.pop();
	int_mstack.pop();
	std::cout << "\t> Information \n\tSize: " << int_mstack.size() << "\n\tEmpty: " << (int_mstack.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	return 0;
}

int	main(void)
{
	std::cout << "===== TEST FROM SUBJECT =====" << std::endl;
	test_from_subject();
	std::cout << std::endl;
	std::cout << "===== MY TEST =====" << std::endl;
	my_test();
	std::cout << std::endl;
	return (0);
}
