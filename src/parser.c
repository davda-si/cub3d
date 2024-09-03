/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/09/03 19:27:16 by davda-si         ###   ########.fr       */
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
	while (file[i] && (err == 0 || flag != 6))
	{
		if (!(check_line(file[i])))
		{
			if (add_texture(file[i], game))
				err = 1;
			flag++;
		}
		i++;
	}
	if (flag != 6 || err == 1)
		return (1);
	game->map->after_txtr = i;
	return (0);
}

static int	check_map(char **line, t_data *game)
{
	int	i;

	i = game->map->after_txtr;
	while (line[i] && !map_start(line[i]))
		i++;
	if (!line[i])
		error_handle(1, "No map found\n", game);
	if (read_map(&line[i], game))
		error_handle(1, "Map invalid\n", game);
	if (map_parse(game->map))
		error_handle(1, "Map invalid\n", game);
	return (0);
}

static char	**read_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	**file;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while(1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		line = tmp2;
	}
	file = ft_split(line, '\n');
	free(line);
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
	{
		close(fd);
		error_handle(1, "can't open file\n", game);
	}
	fd = open(file, O_RDONLY);
	cpy_file = read_file(fd);
	if (!cpy_file)
		error_handle(1, "Error: empty file\n", game);
	if (check_textr(cpy_file, game))
	{
		free_mtx(cpy_file);
		error_handle(1, "textures don't work\n", game);
	}
	if (!game->map->ntt.img || !game->map->wtt.img || !game->map->ett.img || !game->map->stt.img || !game->map->fcolor || !game->map->ccolor)
	{
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
