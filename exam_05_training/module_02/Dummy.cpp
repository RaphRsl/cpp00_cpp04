#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("arget Practice Dummy")
{}

Dummy::~Dummy(void)
{}

ATarget* Dummy::clone(void) const
{
	return(new Dummy());
}