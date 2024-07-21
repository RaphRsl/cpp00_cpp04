#pragma once
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> _TG;
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator &operator=(TargetGenerator const & src);


	public:
		TargetGenerator();
		~TargetGenerator();


		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};