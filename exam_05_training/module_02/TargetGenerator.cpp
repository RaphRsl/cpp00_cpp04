#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::TargetGenerator(TargetGenerator const & src)
{
	*this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src)
{
	_TG = src._TG;
	return (*this);
}

TargetGenerator::~TargetGenerator()
{
	// for(std::map<std::string, ATarget*>::iterator it = _TG.begin() ; it != _TG.end() ; ++it)
	// 	delete it->second;
	// _TG.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if(target)
		_TG[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const & targetName)
{
	if(_TG.find(targetName) != _TG.end())
	{
		delete _TG[targetName];
		_TG.erase(targetName);
	}
}

ATarget* TargetGenerator::createTarget(std::string const & targetName)
{
	ATarget* tmp = NULL;
	if (_TG.find(targetName) != _TG.end())
		tmp = _TG[targetName];
	return(tmp);
}