#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") //NOTE: faire comme ça
{

}

Dummy::~Dummy(void)
{

}

ATarget* Dummy::clone(void) const
{
	return(new Dummy());
}