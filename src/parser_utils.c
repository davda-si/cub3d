/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/09/20 23:05:09 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	text_exists(char *type, char **map, int pos, t_data *game)
{
	int		fd;
	char	*clean_path;

	clean_path = ft_strtrim(&type[pos], " \n\t");
	fd = open(clean_path, O_RDONLY);
	printf("clean - %s\n", clean_path);
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

int	texture_info(char *type, t_tt *txt, t_data *game, char **map)
{
	int		pos;
	int		px;
	char	*clean_path;

	px = MULTIPLIER;
	pos = find_path(type, 3);
	if (text_exists(type, map, pos, game))
	{
		clean_path = ft_strtrim(&type[pos], " \n\t");
		txt->name = ft_strdup(clean_path);
		txt->img = mlx_xpm_file_to_image(game->mlx, txt->name, &px, &px);
		free(clean_path);
		if (!txt->img)
		{
			free(clean_path);
			free_mtx(map);
			error_handle(1, "Error with texture\n", game);
		}
		txt->addr = mlx_get_data_addr(txt->img,
				&txt->bpp, &txt->l_length, &txt->endian);
	}
	return (0);
}

int	add_texture(char *file, t_data *game, char **map)
{
	int		i;
	char	start[3];

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
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
		i++;
		while (file[i] != '\n' && file[i] != '\0')
			i++;
		if (file[i] == '\n')
			i++;
	}
	return (-2);
}

int	check_line(char *file)
{
	char	start[3];

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
