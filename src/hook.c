/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:04:42 by phanta            #+#    #+#             */
/*   Updated: 2024/09/23 19:02:09 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	rightback(void)
{
	if (data()->s == 1)
	{
		if (data()->map.map[(int)(data()->pos_y)][(int)(data()->pos_x
		- data()->dir_x * data()->movespeed)] != '1')
			data()->pos_x -= data()->dir_x * data()->movespeed;
		if (data()->map.map[(int)(data()->pos_y - data()->dir_y
				* data()->movespeed)][(int)(data()->pos_x)] != '1')
			data()->pos_y -= data()->dir_y * data()->movespeed;
	}
	if (data()->d == 1)
	{
		if (data()->map.map[(int)(data()->pos_y)][(int)(data()->pos_x
		+ data()->sidedir_x * data()->movespeed)] != '1')
			data()->pos_x += data()->sidedir_x * data()->movespeed;
		if (data()->map.map[(int)(data()->pos_y + data()->sidedir_y
				* data()->movespeed)][(int)(data()->pos_x)] != '1')
			data()->pos_y += data()->sidedir_y * data()->movespeed;
	}
}

void	do_walk(void)
{
	data()->sidedir_x = data()->dir_x;
	data()->sidedir_y = data()->dir_y;
	rotate_vector(&(data()->sidedir_x), &(data()->sidedir_y), 1.5708);
	if (data()->w == 1)
	{
		if (data()->map.map[(int)(data()->pos_y)][(int)(data()->pos_x
		+ data()->dir_x * data()->movespeed)] != '1')
		{
			data()->pos_x += data()->dir_x * data()->movespeed;
			printf("moved from pos_x=%i to after x=%i\n", (int)(data()->pos_x), (int)(data()->pos_x
		+ data()->dir_x * data()->movespeed));
		}
		if (data()->map.map[(int)(data()->pos_y + data()->dir_y
				* data()->movespeed)][(int)(data()->pos_x)] != '1')
		{
			data()->pos_y += data()->dir_y * data()->movespeed;
			printf("moved from pos_y=%i, to after_y=%i\n", (int)(data()->pos_y), (int)(data()->pos_y + data()->dir_y
				* data()->movespeed));
		}
	}
	if (data()->a == 1)
	{
		if (data()->map.map[(int)(data()->pos_y)][(int)(data()->pos_x
		- data()->sidedir_x * data()->movespeed)] != '1')
			data()->pos_x -= data()->sidedir_x * data()->movespeed;
		if (data()->map.map[(int)(data()->pos_y - data()->sidedir_y
				* data()->movespeed)][(int)(data()->pos_x)] != '1')
			data()->pos_y -= data()->sidedir_y * data()->movespeed;
	}
	rightback();
}

int	walk(int keycode)
{
	if (keycode == 119)
		data()->w = 1;
	if (keycode == 97)
		data()->a = 1;
	if (keycode == 115)
		data()->s = 1;
	if (keycode == 100)
		data()->d = 1;
	if (keycode == 65307)
		close_win();
	if (keycode == 65361)
		data()->rotation--;
	if (keycode == 65363)
		data()->rotation++;
	return (0);
}

int	stop(int keycode)
{
	if (keycode == 119)
		data()->w = 0;
	if (keycode == 97)
		data()->a = 0;
	if (keycode == 115)
		data()->s = 0;
	if (keycode == 100)
		data()->d = 0;
	if (keycode == 65361)
		data()->rotation++;
	if (keycode == 65363)
		data()->rotation--;
	return (0);
}
