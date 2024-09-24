/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:21:13 by phanta            #+#    #+#             */
/*   Updated: 2024/09/24 15:52:10 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	updates(void)
{
	double	frametime;

	data()->oldtime = data()->time;
	data()->time = timern();
	frametime = (data()->time - data()->oldtime) / 1000.0;
	data()->movespeed = frametime * MOVE_SPEED_MULTIPLIER;
	if (data()->movespeed > 0.7)
		data()->movespeed = 0.7;
	data()->rotspeed = frametime * ROT_MULTIPLIER;
	data()->first = 0;
}

static void	freakier_render(void)
{
	t_img	final_frame;
	int		i;

	i = -1;
	if (data()->first == 1)
	{
		while (++i < 4)
			data()->last_crtd_txts[i] = data()->textures[i];
	}
	i = -1;
	while (++i < 4)
	{
		data()->created_texture[i] = raycast_loop(data()->last_crtd_txts);
		rotate(1.5708);
	}
	final_frame = raycast_loop(data()->created_texture);
	mlx_put_image_to_window(data()->mlx, data()->win,
		final_frame.img, 0, 0);
	mlx_destroy_image(data()->mlx, final_frame.img);
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(data()->mlx, data()->last_crtd_txts[i].img);
		data()->last_crtd_txts[i] = data()->created_texture[i];
	}
}

static void	freaky_render(void)
{
	t_img	final_frame;
	int		i;

	i = -1;
	while (++i < 4)
	{
		data()->created_texture[i] = raycast_loop(data()->textures);
		rotate(1.5708);
	}
	final_frame = raycast_loop(data()->created_texture);
	mlx_put_image_to_window(data()->mlx, data()->win,
		final_frame.img, 0, 0);
	mlx_destroy_image(data()->mlx, final_frame.img);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(data()->mlx, data()->created_texture[i].img);
}

static void	normal_render(void)
{
	mlx_put_image_to_window(data()->mlx, data()->win,
		(raycast_loop(data()->textures)).img, 0, 0);
	mlx_destroy_image(data()->mlx, data()->current_frame.img);
}

int	renderloop(void)
{
	camera();
	do_rotate();
	do_walk();
	if (data()->toggle == 0)
		normal_render();
	else if (data()->toggle == 1)
		freaky_render();
	else if (data()->toggle == 2)
		freakier_render();
	updates();
	return (0);
}
