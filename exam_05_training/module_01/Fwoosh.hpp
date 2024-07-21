#pragma once
#include "ASpell.hpp" //note : pas besoin de iostream


class Fwoosh : public ASpell
{
	private :


	public :
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const; //NOTE: Aspell* - clone() - const
};
