/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/09/17 15:59:36 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	check_textr(char **file, t_data *game)
{
	int	flag;
	int	i;
	int err;

	flag = 0;
	i = 0;
	err = 0;
	while (file[i] && !map_start(file[i]) && (err == 0 || flag != 6))
	{
		if (!(check_line(file[i])))
		{
			if (add_texture(file[i], game, file) == -1)
				err = 1;
			flag++;
		}
		i++;
	}
	if (flag != 6 || err == 1)
		return (1);
	game->map.after_txtr = i;
	return (0);
}

static int	check_map(char **line, t_data *game)
{
	int	i;

	i = game->map.after_txtr;
	while (line[i] && !map_start(line[i]))
		i++;
	if (!line[i])
	{
		free_mtx(line);
		error_handle(1, "No map found\n", game);
	}
	if (read_map(&line[i], line, game))
	{
		free_mtx(line);
		error_handle(1, "Map invalid\n", game);
	}
	if (map_parse(&game->map))
	{
		free_mtx(line);
		error_handle(1, "Map invalid\n", game);
	}
	return (0);
}

static void	how_big(int fd, t_data *game, char *fl)
{
	char	c;
	int		i;

	i = 0;
	fd = open(fl, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	if (c != '\n')
		i++;
	game->file_size = i;
	close(fd);
}

static char	**read_file(int fd, t_data *game, char *fl)
{
	int		i;
	char	**file;

	i = 0;
	how_big(fd, game, fl);
	fd = open(fl, O_RDONLY);
	file = (char **)malloc(sizeof(char *) * (game->file_size + 1));
	if (!file)
		return (NULL);
	while (i <= game->file_size)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
			break ;
		i++;
	}
	file[i] = NULL;
	close(fd);
	return (file);
}


void	check_file(char *file, t_data *game)
{
	int		fd;
	char	**cpy_file;

	if ((fd = open(file, __O_DIRECTORY)) != -1)
	{
		close(fd);
		error_handle(1, "file's a directory\n", game);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
		error_handle(1, "can't open file\n", game);
	close(fd);
	cpy_file = read_file(fd, game, file);
	if (!cpy_file)
		error_handle(1, "Error: empty file\n", game);
	if (check_textr(cpy_file, game))
	{
		free_mtx(cpy_file);
		error_handle(1, "textures don't work\n", game);
	}
	if (!game->map.ntt.img || !game->map.wtt.img || !game->map.ett.img || !game->map.stt.img || !game->map.fcolor || !game->map.ccolor)
	{
		printf("ntt - %p wtt - %p ett - %p stt - %p f - %d c %d\n", game->map.ntt.img, game->map.wtt.img, game->map.ett.img, game->map.stt.img, game->map.fcolor, game->map.ccolor);
		free_mtx(cpy_file);
		error_handle(1, "textures missing\n", game);
	}
	if (check_map(cpy_file, game))
	{
		free_mtx(cpy_file);
		error_handle(1, "invalid map\n", game);
	}
	free_mtx(cpy_file);
}
