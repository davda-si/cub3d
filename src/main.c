/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/08/29 18:24:38 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void startGame()
{
	data()->mlx = mlx_init(); 
	data()->win = mlx_new_window(data()->mlx, RESW, RESH, "CADA 1 NO SEU QUADRADO");
	calculus(data()->map->map);
	mlx_loop(data()->mlx);
}

int main(int ac, char **av)
{
	t_data	*game;

	if (ac != 2)
		error_handle(0, "wrong number of arguments\n", &game);
	if (ft_strnstr(av[1] + ft_strlen(av[1]) - 4,
		".cub", ft_strlen(av[1])) == NULL)
		error_handle(0, "wrong file name\n", &game);
	ft_memset(&game, 0, sizeof(t_data));
	game = data();
	if (ac == 2)
	{
		check_file(av[1], &game);
		startGame();
		//run game with all the calculus
	}
	return (0);
}
