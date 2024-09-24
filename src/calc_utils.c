/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:08:10 by phanta            #+#    #+#             */
/*   Updated: 2024/09/24 15:53:30 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	timern(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return ((int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

static char	check_borders(int mapx, int mapy)
{
	if (mapy < 0 || mapx < 0 || mapy >= data()->map.height
		|| mapx >= (int)ft_strlen(data()->map.map[mapy]))
		return ('1');
	return (data()->map.map[mapy][mapx]);
}

void	set_pdata(int a, int b, double c, double d)
{
	data()->dir_x = a;
	data()->dir_y = b;
	data()->plane_x = c;
	data()->plane_y = d;
}

void	raycast_data(int x)
{
	data()->hit = 0;
	data()->mapx = data()->pos_x;
	data()->mapy = data()->pos_y;
	data()->camera_x = 2 * x / (double)(RESW - 1) - 1.0;
	data()->raydirx = data()->dir_x + data()->plane_x * data()->camera_x;
	data()->raydiry = data()->dir_y + data()->plane_y * data()->camera_x;
}

void	hitzero(void)
{
	if (data()->sidedistx < data()->sidedisty)
	{
		data()->sidedistx += data()->deltadistx;
		data()->mapx += data()->stepx;
		data()->side = 0;
	}
	else
	{
		data()->sidedisty += data()->deltadisty;
		data()->mapy += data()->stepy;
		data()->side = 1;
	}
	if (check_borders(data()->mapx, data()->mapy) == '1')
		data()->hit = 1;
}
