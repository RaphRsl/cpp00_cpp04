#pragma once
#include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget //NOTE: copy from ASpell
{
	protected:
		std::string _type;

	public:
		ATarget();
		ATarget(ATarget const & src);
		ATarget &operator=(ATarget const & src);
		virtual ~ATarget();
		ATarget(std::string type);
		
		std::string const & getType() const; //NOTE: const ... const
		virtual ATarget* clone() const = 0; //NOTE ATarget - clone() - const + virtual .. = 0;

		void getHitBySpell(ASpell const & spell) const; //NOTE: return const a la fin !!! comme LAUNCH
};