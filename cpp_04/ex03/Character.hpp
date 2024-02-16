#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		static const int	_inventorySize = 4;
		AMateria			*_inventory[_inventorySize];
		std::string			_name;
		
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &character);
		virtual ~Character();

		Character	&operator=(const Character &character);

		std::string const &getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
		void				printInventory(void) const; //UTILE ?
};

#endif
