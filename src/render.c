/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:21:13 by phanta            #+#    #+#             */
/*   Updated: 2024/09/18 16:45:27 by davda-si         ###   ########.fr       */
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
	data()->rotspeed = frametime * ROT_MULTIPLIER;
}

int	renderloop(void)
{
	camera();
	do_rotate();
	do_walk();
	raycast_loop();
	updates();
	return (0);
}

//static int a;
// if(++a%2==0)i
// {
// 	printf("FPS:%f\n",(1.0 / frameTime));
// 	mlx_string_put(data()->mlx, data()->win, 50, 50,
//0x000000, ft_itoa((int)1.0/frameTime));
// }