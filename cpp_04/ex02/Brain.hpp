/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:52 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:23:51 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	protected:
		std::string	_ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &brain);
		virtual ~Brain();

		Brain	&operator=(const Brain &brain);

		void	showIdeas(void) const;
		void	anotherIdea(std::string idea);
};

#endif
