/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/07/05 13:23:41 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int main(int ac, char **av)
{
	if (ac != 2)
		error_handle(0);
	if (ft_strnstr(av[1] + ft_strlen(av[1]) - 4,
		".cub", ft_strlen(av[1])) == NULL)
		error_handle(1);
	return (0);
	(void)av;
	if (ac == 2)
	{
		//parsing of the file, then of the map
		calculus(/*map*/NULL);
		//run game with all the calculus
	}
	else
		ft_printf("Wrong number of arguments, try again\n");
}
