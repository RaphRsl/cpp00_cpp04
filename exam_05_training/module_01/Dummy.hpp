#pragma once
#include "ATarget.hpp" //note : pas besoin de iostream


class Dummy : public ATarget
{
	private:

	public:
		Dummy();
		~Dummy();
		ATarget* clone() const;
};
