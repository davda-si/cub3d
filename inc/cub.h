/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:55 by david             #+#    #+#             */
/*   Updated: 2024/07/05 13:11:06 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include "./libft/libft.h"
#include "./mlx_linux/mlx.h"

typedef struct s_mapdata
{
	char		**map;
	char		**tmp;
	int			height;
	int			length;
}				t_mapdata;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		**image;
	t_mapdata	*map;
    double      posX;//player pos
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;//perpendicular to dir (at least while you're sober)
    double      planeY;
    double      time;
    double      oldTime;
}				t_data;

void calculus(char **map);
t_data	*data(void);
t_mapdata	*mapdata(void);

#endif
