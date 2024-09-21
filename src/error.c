/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/09/21 10:36:59 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

static void	free_text(t_data *game)
{
	if (game->textures[0].img)
		mlx_destroy_image(game->mlx, game->textures[0].img);
	if (game->textures[0].name)
		free(game->textures[0].name);
	if (game->textures[1].img)
		mlx_destroy_image(game->mlx, game->textures[1].img);
	if (game->textures[1].name)
		free(game->textures[1].name);
	if (game->textures[2].img)
		mlx_destroy_image(game->mlx, game->textures[2].img);
	if (game->textures[2].name)
		free(game->textures[2].name);
	if (game->textures[3].img)
		mlx_destroy_image(game->mlx, game->textures[3].img);
	if (game->textures[3].name)
		free(game->textures[3].name);
}

static void	free_stuff(t_data *game)
{
	if (!game)
		return ;
	if (game->map.map)
		free_mtx(game->map.map);
	if (game->map.tmp)
		free_mtx(game->map.tmp);
	free_text(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	error_handle(int err, char *msg, t_data *game)
{
	if (err == 0)
	{
		ft_printf(msg);
		exit (1);
	}
	else if (err == 1)
	{
		free_stuff(game);
		ft_printf(msg);
		exit (1);
	}
}
