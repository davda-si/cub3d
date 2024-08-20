/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:55 by david             #+#    #+#             */
/*   Updated: 2024/08/20 19:47:36 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include "./libft/libft.h"
#include "./mlx_linux/mlx.h"
#include <math.h>

#define RESW 1080
#define RESH 720

#define MULTIPLIER 64

typedef struct s_tt
{
	void		*img;
	char		*name;
	char		*addr;
	int			bpp;
	int			l_length;
	int			endian;
}				t_tt;

typedef struct s_mapdata
{
	char		**map;
	char		**tmp;
	int			after_txtr;
	int			map_start;
	int			height;
	int			length;
	int			fcolor;
	int			ccolor;
	t_tt		ntt;
	t_tt		wtt;
	t_tt		ett;
	t_tt		stt;
}				t_mapdata;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_tt		frame;
	t_mapdata	*map;
	double		posX;//player pos
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;//perpendicular to dir (at least while you're sober)
	double		planeY;
	double		time;
	double		oldTime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
}				t_data;

//general
t_data		*data(void);
t_mapdata	*mapdata(void);
void		error_handle(int err, char *msg, t_data *game);
int			ft_strcmp(char *str1, char *str2);
void		free_mtx(char **mtx);

//parsing
void	check_file(char *file, t_data **game);
int		check_line(char *file);
int		check_str(char *str);
void	mapline_add(t_data *game, char *line);
int		find_path(char *str, int i);
int		add_texture(char *file, t_data *game);
int		color_info(char *file, t_mapdata *map, t_data *game, int fl);
int		skip_spaces(char **file, char *start);
int		map_start(char *file);
int		read_map(char **file, t_data *game);

//raytracing
void	calculus(char **map);

#endif