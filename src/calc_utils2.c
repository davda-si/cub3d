/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:20 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/22 18:52:37 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	setdist2(void)
{
	if (data()->raydiry < 0)
	{
		data()->stepy = -1;
		data()->sidedisty = (data()->pos_y - data()->mapy) * data()->deltadisty;
	}
	else
	{
		data()->stepy = 1;
		data()->sidedisty = (data()->mapy + 1.0 - data()->pos_y)
		* data()->deltadisty;
	}
}

void	setdist(void)
{
	if (data()->raydirx == 0)
		data()->deltadistx = 1e30;
	else
		data()->deltadistx = fabs(1.0 / data()->raydirx);
	if (data()->raydiry == 0)
		data()->deltadisty = 1e30;
	else
		data()->deltadisty = fabs(1.0 / data()->raydiry);
	if (data()->raydirx < 0)
	{
		data()->stepx = -1;
		data()->sidedistx = (data()->pos_x - data()->mapx) * data()->deltadistx;
	}
	else
	{
		data()->stepx = 1;
		data()->sidedistx = (data()->mapx + 1.0 - data()->pos_x)
		* data()->deltadistx;
	}
	setdist2();
}

void	setline(void)
{
	if (data()->side == 0)
		data()->perpwalldist = (data()->sidedistx - data()->deltadistx);
	else
		data()->perpwalldist = (data()->sidedisty - data()->deltadisty);
	if (fabs(data()->perpwalldist) < 1e-6)
		data()->lineheight = RESH;
	else
		data()->lineheight = (int)(RESH / data()->perpwalldist);
	data()->drawstart = (RESH / 2) - ((data()->lineheight / 2));
	if (data()->drawstart < 0)
		data()->drawstart = 0;
	data()->drawend = (RESH / 2) + (data()->lineheight / 2);
	if (data()->drawend > RESH)
		data()->drawend = RESH;
	if (data()->side == 0)
		data()->wallx = data()->pos_y + data()->perpwalldist * data()->raydiry;
	else
		data()->wallx = data()->pos_x + data()->perpwalldist * data()->raydirx;
}
//EWSN
void	settex(t_img *tex, t_img textures[])
{
	if (data()->side == 0 && data()->raydirx < 0)
		*tex = textures[3];
	else if (data()->side == 0 && data()->raydirx > 0)
		*tex = textures[1];
	else if (data()->side == 1 && data()->raydiry > 0)
		*tex = textures[2];
	else if (data()->side == 1 && data()->raydiry < 0)
		*tex = textures[0];
}

void	drawst(int texy, int texx, int x, t_img *tex)
{
	texy = (int)data()->texpos % (tex->y - 1);
	data()->texpos += data()->step;
	data()->color = get_color(tex, texx, texy);
	my_mlx_pixel_put(&(data()->current_frame), x, data()->drawstart++,
		data()->color);
}
