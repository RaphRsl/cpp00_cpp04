#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell*> _spellBook; //NOTE: map avec string + pointeur ASpell

		Warlock();
		Warlock(Warlock const & src);
		Warlock &operator=(Warlock const & src);

	public:
		void setTitle(std::string const & str);
		Warlock(std::string _name, std::string _title);
		~Warlock();

		std::string const & getName() const;
		std::string const & getTitle() const;

		void introduce() const;

//NOTE: for the 3 following functions : ca a l'air ok comme ça
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget & target);
};