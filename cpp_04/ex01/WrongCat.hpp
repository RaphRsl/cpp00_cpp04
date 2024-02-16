/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:36:07 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 09:36:54 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		
	public:
		WrongCat(void);
		WrongCat(const WrongCat &wrongCat);
		~WrongCat();

		WrongCat	&operator=(const WrongCat &wrongCat);

		void	makeSound(void) const;
};

#endif
