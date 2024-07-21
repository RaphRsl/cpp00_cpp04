#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") //NOTE: faire comme ça
{

}

Fwoosh::~Fwoosh()
{
	
}

ASpell* Fwoosh::clone(void) const
{
	return(new Fwoosh()); //NOTE: exactement comme ça, pas de Fwoosh*, mais return Fwoshh()
}