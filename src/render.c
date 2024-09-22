/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:21:13 by phanta            #+#    #+#             */
/*   Updated: 2024/09/22 19:06:39 by phanta           ###   ########.fr       */
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
	if(data()->movespeed>0.7)
		data()->movespeed=0.7;
	data()->rotspeed = frametime * ROT_MULTIPLIER;
	data()->first=0;
}

void	freakier_render()
{
	t_img final_frame;
	int i;
	int j;
	
	j=-1;
	if(data()->first==1)
	{
		while(++j<4)
			data()->last_created_textures[j]=data()->textures[j];
	}
	//should make player look north at first but then i need to reset his orientation after the loop-_-
	i=-1;
	while(++i<4)
	{
		data()->created_texture[i]=raycast_loop(data()->last_created_textures);
		rotate(1.5708);//90º left
	}
	final_frame=raycast_loop(data()->created_texture);
	mlx_put_image_to_window(data()->mlx, data()->win,
		final_frame.img, 0, 0);
	mlx_destroy_image(data()->mlx, final_frame.img);
	i=-1;
	while(++i<4)
	{
		mlx_destroy_image(data()->mlx, data()->last_created_textures[i].img);
		data()->last_created_textures[i]=data()->created_texture[i];
	}
}

void	freaky_render()
{
	t_img final_frame;
	int i;
	
	//should make player look north at first but then i need to reset his orientation after the loop-_-
	i=-1;
	while(++i<4)
	{
		data()->created_texture[i]=raycast_loop(data()->textures);
		rotate(1.5708);//90º left
	}
	final_frame=raycast_loop(data()->created_texture);
	mlx_put_image_to_window(data()->mlx, data()->win,
		final_frame.img, 0, 0);
	mlx_destroy_image(data()->mlx, final_frame.img);
	i=-1;
	while(++i<4)
		mlx_destroy_image(data()->mlx, data()->created_texture[i].img);
}

void	normal_render()
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
	//normal_render();
	freaky_render();
	//freakier_render();
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