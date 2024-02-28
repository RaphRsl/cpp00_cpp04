
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base *randomGen(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		std::cerr << "Error while generating A/B/C." << std::endl;
		return (NULL);
	}
}

static void identifyType(Base *testBase)
{
	if (dynamic_cast<A *>(testBase))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(testBase))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(testBase))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identifyType(Base &testBase)
{
	while (i < 3)
	{
		void *foo = NULL;
		Base &unused = (Base &)foo;
		try
		{
			if (i == 0)
				unused = dynamic_cast<A &>(testBase);
			else if (i == 1)
				unused = dynamic_cast<B &>(testBase);
			else if (i == 2)
				unused = dynamic_cast<C &>(testBase);
			else
				std::cout << "unknow type" << std::endl;
			(void)unused;
		}
		catch (std::exception &e)
		{
			i++;
			identifyType(testBase);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main()
{
	srand(time(NULL));
	for (int j = 0; j < 8; j++)
	{
		Base *testBase = randomGen();
		if (testBase == NULL)
			return (1);
		else
		{
			identifyType(testBase);
			identifyType(*testBase);
			delete (testBase);
			std::cout << std::endl;
		}
	}
	return (0);
}
