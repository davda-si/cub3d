/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:40:43 by phanta            #+#    #+#             */
/*   Updated: 2024/09/24 15:52:06 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

//rotate counterclockwise btw
void	rotate_vector(double *x, double *y, double radians)
{
	double	newy_x;
	double	newy_y;

	newy_x = (*x) * cos(radians) - (*y) * sin(radians);
	newy_y = (*x) * sin(radians) + (*y) * cos(radians);
	*x = newy_x;
	*y = newy_y;
}

void	rotate(double radians)
{
	rotate_vector(&(data()->dir_x), &(data()->dir_y), radians);
	rotate_vector(&(data()->plane_x), &(data()->plane_y), radians);
}

void	do_rotate(void)
{
	rotate(data()->rotspeed * data()->rotation);
}

void	camera(void)
{
	int		mouse_x;
	int		mouse_y;
	double	rot_factor;

	mlx_mouse_get_pos(data()->mlx, data()->win, &mouse_x, &mouse_y);
	rot_factor = (mouse_x - (RESW / 2)) * 0.005;
	rotate((rot_factor * data()->rotspeed));
	mlx_mouse_move(data()->mlx, data()->win, RESW / 2, RESH / 2);
}
