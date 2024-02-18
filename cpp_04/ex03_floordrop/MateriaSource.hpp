#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		static const int	_inventorySize = 4;
		AMateria			*_inventory[_inventorySize];
		
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &materiaSource);
		virtual ~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &materiaSource);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string &type);
};

#endif