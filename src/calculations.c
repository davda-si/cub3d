/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:30 by phanta            #+#    #+#             */
/*   Updated: 2024/09/19 19:05:01 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	setplayer(char c, int y, int x)
{
	data()->pos_x = (double)x + 0.5;
	data()->pos_y = (double)y + 0.5;
	if (c == 'N')
		set_pdata(0, -1, 0.66, 0);
	if (c == 'S')
		set_pdata(0, 1, -0.66, 0);
	if (c == 'E')
		set_pdata(1, 0, 0, 0.66);
	if (c == 'W')
		set_pdata(-1, 0, 0, -0.66);
}

static void	drawray(int x, t_img tex)
{
	int		i;
	int		texy;
	int		texx;

	texy = 0;
	texx = (int)(data()->wallx * tex.x);
	if (fabs(data()->perpwalldist) < 1e-6)
	{
		data()->step = 0;
		data()->texpos = (double)tex.y / 2.0;
	}
	else
	{
		data()->step = (double)tex.y / (double)data()->lineheight;
		data()->texpos = (data()->drawstart - RESH
			/ 2 + data()->lineheight / 2) * data()->step;
	}
	i = -1;
	while (++i < data()->drawstart)
		my_mlx_pixel_put(&(data()->current_frame), x, i, 0x87CEEB);
	while (data()->drawstart <= data()->drawend)
		drawst(texy, texx, x, &tex);
	while (++data()->drawend < RESH)
		my_mlx_pixel_put(&(data()->current_frame), x,
			data()->drawend, 0x8ACE00);
}

void	raycast_loop(void)
{
	t_img	img;
	t_img	tex;
	int		x;

	img.img = mlx_new_image(data()->mlx, RESW, RESH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	data()->current_frame = img;
	x = -1;
	while (++x < RESW)
	{
		raycast_data(x);
		setdist();
		while (data()->hit == 0)
			hitzero();
		setline();
		data()->wallx -= floor((data()->wallx));
		settex(&tex);
		drawray(x, tex);
	}
	mlx_put_image_to_window(data()->mlx, data()->win,
		data()->current_frame.img, 0, 0);
	mlx_destroy_image(data()->mlx, data()->current_frame.img);
}

void	calculus(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data()->map.height)
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				setplayer(map[i][j], i, j);
				printf("----------------------\ni=%i, j=%i\n", i, j);
				printf("---------------------------\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
	data()->time = timern();
	data()->oldtime = timern();
}

//prints do raycastloop()
//printf("raydirX=%f, raydirY=%f\n",rayDirX, rayDirY);
//printf("---------x=%i--------rayDirX=%f, rayDirY=%f--------\n\n",
//x, rayDirX, rayDirY);
//printf("sideDistX=%f, sideDistY=%f\n\n", sideDistX, sideDistY);
//printf("MAP X=%i, MAP Y=%i, content=%c\n\n\n\n",
//mapX, mapY, data()->map->map[mapY][mapX]);
//printf("side=%i, raydirX=%f, raydirY=%f\n",side, rayDirX, rayDirY);
// if (side == 0)
//color = (color & 0xfefefe) >> 1;
//printf("data()->perpWallDist=%f, start=%i, end=%i, lineHeight=%i\n\n",
// data()->perpWallDist, drawStart, drawEnd, lineHeight);