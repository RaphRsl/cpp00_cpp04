#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG] This is a debug message." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] This is an info message." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] This is a warning message." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR] This is an error message." << std::endl;
}

int	levelDetector(std::string level)
{
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					detectedLevel = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			detectedLevel = i;
	}
	return (detectedLevel);
}

void	Harl::complain(std::string level)
{
	int	detectedLevel = levelDetector(level);
	void	(Harl::*levelFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (detectedLevel == -1)
		std::cout << "Invalid level. Expected level are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
	else
		(this->*levelFunctions[detectedLevel])();
}