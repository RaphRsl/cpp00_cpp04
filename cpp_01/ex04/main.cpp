#include <iostream>
#include <string>
#include <fstream>

std::string replaceString(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result = line;
	size_t pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos) {
		result.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
	return result;
}


int	main(int ac, char **av)
{
	std::fstream	inFile;
	std::fstream	outFile;
	std::string		fileName;
	std::string		s1;
	std::string		s2;
	std::string		line;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments.\nExpected format: [filename][string to be replaced][string of replacement]." << std::endl;
		return (1);
	}

	fileName = av[1];
	s1 = av[2];
	s2 = av[3];

	inFile.open(fileName.c_str(), std::ios::in);
	if (!inFile.is_open())
	{
		std::cout << "Error opening " << fileName << "." << std::endl;
		return (1);
	}
	fileName = fileName + ".replace";
	outFile.open(fileName.c_str(), std::ios::out);
	if (!outFile.is_open())
	{
		std::cout << "Error creating " << fileName << ".replace." << std::endl;
		return (1);
	}
	while (std::getline(inFile, line))
	{
		std::string replacedLine = replaceString(line, s1, s2);
		outFile << replacedLine << std::endl;
	}

	inFile.close();
	outFile.close();

	std::cout << "File " << fileName << " successfully replaced." << std::endl;
	return (0);
}