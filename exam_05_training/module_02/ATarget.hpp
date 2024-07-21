#pragma once
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected :
		std::string _type;

	public :
		ATarget();
		virtual ~ATarget();
		ATarget(ATarget const & src);
		ATarget &operator=(ATarget const & src);
		ATarget(std::string type);

		std::string const & getType() const;
		virtual ATarget* clone() const = 0;

		void getHitBySpell(ASpell const & spell) const;
};