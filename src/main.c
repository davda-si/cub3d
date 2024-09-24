/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/09/24 16:03:15 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	close_win(void)
{
	ft_printf("Bye Bye!\n");
	free_stuff(data());
	exit (0);
}

static void	start_game(void)
{
	data()->win = mlx_new_window(data()->mlx, RESW, RESH,
		"CADA 1 NO SEU QUADRADO");
	calculus(data()->map.map);
	data()->rotation = 0;
	data()->first = 1;
	data()->toggle = 0;
	mlx_loop_hook(data()->mlx, &renderloop, NULL);
	mlx_hook(data()->win, 02, (1L << 0), walk, NULL);
	mlx_hook(data()->win, 03, (1L << 1), stop, NULL);
	mlx_hook(data()->win, 17, (1L << 2), close_win, NULL);
	mlx_loop(data()->mlx);
}

int	main(int ac, char **av)
{
	t_data	*game;

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
	game = data();
	game->mlx = mlx_init();
	check_file(av[1], game);
	start_game();
	return (0);
}
