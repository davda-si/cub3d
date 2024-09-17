/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/09/17 19:15:47 by davda-si         ###   ########.fr       */
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
	if (game->map.ntt.img)
		mlx_destroy_image(game->mlx, game->map.ntt.img);
	if (game->map.ntt.name)
		free(game->map.ntt.name);
	if (game->map.wtt.img)
		mlx_destroy_image(game->mlx, game->map.wtt.img);
	if (game->map.wtt.name)
		free(game->map.wtt.name);
	if (game->map.ett.img)
		mlx_destroy_image(game->mlx, game->map.ett.img);
	if (game->map.ett.name)
		free(game->map.ett.name);
	if (game->map.stt.img)
		mlx_destroy_image(game->mlx, game->map.stt.img);
	if (game->map.stt.name)
		free(game->map.stt.name);
}

void	free_stuff(t_data *game)
{
	if (!game)
		return ;
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->frame.name)
		free(game->frame.name);
	if (game->frame.addr)
		free(game->frame.addr);
	if (game->map.map)
		free_mtx(game->map.map);
	if (game->map.tmp)
		free_mtx(game->map.tmp);
	free_text(game);
	if (game->current_frame.img)
		mlx_destroy_image(game->mlx, game->current_frame.img);
	if (game->current_frame.addr)
		free(game->current_frame.addr);
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

//mlx_destroy_window(game->mlx, game->win);