/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/07/07 02:01:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		error_handle(0);
	if (ft_strnstr(av[1] + ft_strlen(av[1]) - 4,
		".cub", ft_strlen(av[1])) == NULL)
		error_handle(1);
	ft_memset(&game, 0, sizeof(t_data));
	check_file(av[1], &game);
	return (0);
	if (ac == 2)
	{
		//parsing of the file, then of the map
		calculus(/*map*/NULL);
		//run game with all the calculus
	}
	else
		ft_printf("Wrong number of arguments, try again\n");
}
