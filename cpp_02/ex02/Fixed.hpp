/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:23:16 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/09 11:33:20 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# define CALL_LOG 0
# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed
{
	private:
		int	_fixedPoint;
		static const int _numberFracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed	&operator=(const Fixed &fixed);
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
		
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif