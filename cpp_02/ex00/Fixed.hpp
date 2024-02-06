/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:23 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/06 16:00:03 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_numberFracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed&fixed);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
