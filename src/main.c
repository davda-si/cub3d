/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/09/16 20:04:36 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	startGame()
{
	data()->mlx = mlx_init(); 
	data()->win = mlx_new_window(data()->mlx, RESW, RESH, "CADA 1 NO SEU QUADRADO");
	calculus(data()->map.map);
	mlx_loop(data()->mlx);
}

int main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		ft_putendl_fd("Wrong number of arguments", 2);
		exit (0);
	}
	if (ft_strnstr(av[1] + ft_strlen(av[1]) - 4,
		".cub", ft_strlen(av[1])) == NULL)
	{
		ft_putendl_fd("Invalid file name", 2);
		exit (0);
	}
	ft_memset(&game, 0, (sizeof(t_data)));
	game.mlx = mlx_init();
	*data() = game;
	if (ac == 2)
	{
		check_file(av[1], &game);
		//startGame();
	}
	error_handle(1, "acabou ta certo\n", &game);
	return (0);
}
