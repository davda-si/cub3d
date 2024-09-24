/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/09/24 16:35:24 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	text_exists(char *type, char **map, int pos, t_data *game)
{
	int		fd;
	char	*clean_path;

	clean_path = ft_strtrim(&type[pos], " \n\t");
	if (ft_strnstr(clean_path + ft_strlen(clean_path) - 4,
			".xpm", ft_strlen(clean_path)) == NULL)
	{
		free(clean_path);
		free_mtx(map);
		error_handle(1, "Path of texture invalid\n", game);
	}
	fd = open(clean_path, O_RDONLY);
	if (fd == -1)
	{
		free(clean_path);
		free_mtx(map);
		error_handle(1, "Path of texture invalid\n", game);
	}
	free(clean_path);
	close(fd);
	return (1);
}

int	texture_info(char *type, t_img *txt, t_data *game, char **map)
{
	int		pos;
	char	*clean_path;

	pos = find_path(type);
	if (text_exists(type, map, pos, game))
	{
		clean_path = ft_strtrim(&type[pos], " \n\t");
		txt->name = ft_strdup(clean_path);
		txt->img = mlx_xpm_file_to_image(game->mlx, txt->name, &(txt->x),
				&(txt->y));
		free(clean_path);
		if (!txt->img)
		{
			free_mtx(map);
			error_handle(1, "Error with texture\n", game);
		}
		txt->addr = mlx_get_data_addr(txt->img,
				&txt->bits_per_pixel, &txt->line_length, &txt->endian);
	}
	return (0);
}

int	add_texture(char *file, t_data *game, char **map)
{
	int		i;
	char	start[4];

	i = -1;
	init_start(start);
	while (file[++i] != '\n' && file[i] != '\0')
	{
		i += skip_spaces(file, start);
		if (texttime(start, map, game, file) == 0)
			return (0);
		else
		{
			if (!ft_strncmp(start, "F", 2) && !game->map.fcolor)
				return (color_info(file, &game->map, 1));
			else if (!ft_strncmp(start, "C", 2) && !game->map.ccolor)
				return (color_info(file, &game->map, 0));
			else
				return (-1);
		}
		while (file[i] != '\n' && file[i] != '\0')
			i++;
		if (file[i] == '\n')
			i++;
	}
	return (-2);
}

int	check_line(char *file)
{
	char	start[4];

	init_start(start);
	skip_spaces(file, start);
	if (!ft_strncmp(start, "NO", 3) || !ft_strncmp(start, "SO", 3)
		|| !ft_strncmp(start, "WE", 3) || !ft_strncmp(start, "EA", 3))
		return (0);
	else if (!ft_strncmp(start, "F", 2) || !ft_strncmp(start, "C", 2))
		return (0);
	return (1);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'S' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
