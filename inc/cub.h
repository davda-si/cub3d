/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:55 by david             #+#    #+#             */
/*   Updated: 2024/09/24 18:58:09 by davda-si         ###   ########.fr       */
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

# define ROT_MULTIPLIER 3.0
# define MOVE_SPEED_MULTIPLIER 5.0

// typedef struct s_tt
// {
// 	void	*img;
// 	char	*name;
// 	char	*addr;
// 	int		bpp;
// 	int		l_length;
// 	int		endian;
// 	int		x;
// 	int		y;
// }				t_tt;

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
}				t_mapdata;

typedef struct s_img
{
	void	*img;
	char	*name;
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
	int				file_size;
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
	t_img			textures[4];
	int				first;
	t_img			created_texture[4];
	t_img			last_crtd_txts[4];
	int				toggle;
}				t_data;

//general
t_data			*data(void);
void			set_data(t_data *game);
size_t			cb_strlen(const char *s);
void			error_handle(int err, char *msg, t_data *game);
int				ft_strcmp(char *str1, char *str2);
void			free_mtx(char **mtx);
int				safeguard(int value, int flag);
void			free_stuff(t_data *game);

//parsing
void			check_file(char *file, t_data *game);
int				check_line(char *file);
int				check_str(char *str);
int				find_path(char *str);
int				add_texture(char *file, t_data *game, char **map);
int				color_info(char *file, t_mapdata *map, int fl);
int				skip_spaces(char *file, char *start);
int				map_start(char *file);
int				read_map(char **file, char **map, t_data *game);
void			allct_map(char **map, t_data *game);
int				map_parse(t_mapdata *map);
int				around_chr(char **map, int i, int j);
void			init_texture(t_img *txt);
int				check_upanddown(char **map, int i, int j, int flag);
void			clear_file(int fd, char *file, t_data *game);
int				texture_info(char *type, t_img *txt, t_data *game, char **map);
int				texttime(char *start, char **map, t_data *game, char *file);
char			**read_file(int fd, t_data *game, char *fl);
int				check_textr(char **file, t_data *game);
int				check_map(char **line, t_data *game);
void			init_start(char *start);
int				has_spaces(char *line);
int				jump_spaces(char **line, t_data *game);
void			floor_ceiling(char **rgb, int fl, t_mapdata *map);
int				count_commas(char *line);

//raycasting
void			calculus(char **map);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	get_color(t_img *image, int x, int y);
int				timern(void);
void			set_pdata(int a, int b, double c, double d);
void			raycast_data(int x);
void			setdist(void);
void			setline(void);
void			hitzero(void);
void			settex(t_img *tex, t_img textures[]);
void			drawst(int texy, int texx, int x, t_img *tex);
t_img			raycast_loop(t_img textures[]);
int				stop(int keycode);
int				walk(int keycode);
void			do_walk(void);
int				renderloop(void);
void			rotate_vector(double *x, double *y, double radians);
void			do_rotate(void);
void			camera(void);
int				close_win(void);
void			rotate(double radians);

#endif