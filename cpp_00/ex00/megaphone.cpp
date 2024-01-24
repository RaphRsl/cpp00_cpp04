/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:01:02 by rroussel          #+#    #+#             */
/*   Updated: 2024/01/24 15:01:03 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av && av[i])
		{
			j = 0;
			while (av[i][j])
				std::cout << (char)std::toupper(av[i][j++]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
