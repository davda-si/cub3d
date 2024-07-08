/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:55 by david             #+#    #+#             */
/*   Updated: 2024/07/08 17:39:08 by guest            ###   ########.fr       */
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

//general
t_data	    *data(void);
t_mapdata	*mapdata(void);
void		error_handle(int err, char *msg, t_data *game);
int			ft_strcmp(char *str1, char *str2);

//parsing
void	check_file(char *file, t_data *game);
int     check_line(char **file);

//raytracing
void    calculus(char **map);

#endif