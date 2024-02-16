/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:38 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:22:44 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &dog);
		~Dog();

		Dog	&operator=(const Dog &dog);

		void	makeSound(void) const;
		void	whatsInMyMind(void) const;
		void	sleep(void);
};

#endif
