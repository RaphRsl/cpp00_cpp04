#pragma once
#include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected: //NOTE: PROTECTED
		std::string _name;
		std::string _effects;

	public:
		ASpell();
		virtual ~ASpell(); //NOTE: virtual !
		ASpell(ASpell const & src);
		ASpell &operator=(ASpell const & src);
		ASpell(std::string name, std::string effects);
		
		std::string const & getName() const; //NOTE: const ... const => a voir pas forcement obligé
		std::string const & getEffects() const;
		virtual ASpell* clone() const = 0; //NOTE ASpell - clone() - const + virtual .. = 0;

		void launch(ATarget const & target) const; //NOTE: return const a la fin !!! comme getHitBySpell
};