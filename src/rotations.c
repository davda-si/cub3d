/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:40:43 by phanta            #+#    #+#             */
/*   Updated: 2024/09/04 17:14:26 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void    rotate_vector(double *x, double *y, double radians)//rotate counterclockwise btw
{
    double newyX;
    double newyY;
    newyX = (*x) * cos(radians) - (*y) * sin(radians);
    newyY = (*x)* sin(radians) + (*y) * cos(radians);

    *x=newyX;
    *y=newyY;
}

void    rotate(double radians)
{
    rotate_vector(&(data()->dirX), &(data()->dirY), radians);
    rotate_vector(&(data()->planeX), &(data()->planeY), radians);
}

void    do_rotate()
{
    rotate(data()->rotSpeed*data()->rotation);
}

void camera()
{
	int mouse_x;
	int mouse_y;
    double rot_factor;
    
	mlx_mouse_get_pos(data()->mlx, data()->win, &mouse_x,&mouse_y);
    //printf("mouse x before: %i, mouse y before: %i\n", mouse_x, mouse_y);
    rot_factor=(mouse_x-(RESW/2))*0.005;
    //printf("rot:%f\n", rot_factor);
    rotate((rot_factor*data()->rotSpeed));
    mlx_mouse_move(data()->mlx, data()->win, RESW/2, RESH/2);
}