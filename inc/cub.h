/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:55 by david             #+#    #+#             */
/*   Updated: 2024/09/17 19:28:16 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <math.h>
# include <sys/time.h>

# define RESW 1080
# define RESH 720

# define MULTIPLIER 64

# define ROT_MULTIPLIER 3.0
# define MOVE_SPEED_MULTIPLIER 5.0

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
	int			map_end;
	int			height;
	int			length;
	int			fcolor;
	int			ccolor;
	t_tt		ntt;
	t_tt		wtt;
	t_tt		ett;
	t_tt		stt;
}				t_mapdata;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_tt			frame;
	t_mapdata		map;
	double			pos_x;//player pos
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			sidedir_x;
	double			sidedir_y;
	double			plane_x;//perpendicular to dir (at least while you're sober)
	double			plane_y;
	double			perpwalldist;
	double			time;
	double			oldtime;
	double			camera_x;
	double			movespeed;
	double			rotspeed;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			raydirx;
	double			raydiry;
	double			wallx;
	double			step;
	double			texpos;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				side;
	int				hit;
	int				rotation;
	int				w;
	int				a;
	int				s;
	int				d;
	unsigned int	color;
	t_img			current_frame;
	t_img			*textures;
}				t_data;

//general
t_data		*data(void);
void		set_data(t_data *game);
void		error_handle(int err, char *msg, t_data *game);
int			ft_strcmp(char *str1, char *str2);
void		free_mtx(char **mtx);

//parsing
void		check_file(char *file, t_data *game);
int			check_line(char *file);
int			check_str(char *str);
int			find_path(char *str, int i);
int			add_texture(char *file, t_data *game, char **map);
int			color_info(char *file, t_mapdata *map, int fl);
int			skip_spaces(char *file, char *start);
int			map_start(char *file);
int			read_map(char **file, char **map, t_data *game);
void		allct_map(char **map, t_data *game);
int			map_parse(t_mapdata *map);
int			around_chr(char **map, int i, int j);
void		init_texture(t_tt *txt);
int			check_upanddown(char **map, int i, int j, int flag);

//raytracing
void		calculus(char **map);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			timern(void);
char		check_borders(int mapx, int mapy);
void		set_pdata(int a, int b, int c, int d);
void		raycast_data(int x);
void		setdist(void);
void		hitzero(void);
void		settex(t_img *tex);
void		drawst(int texy, int texx, int x, t_img tex);

#endif