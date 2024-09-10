/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/09/10 18:12:40 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int text_exists(char *type, char **map)
{
	int		fd;
	int		pos;

	pos = find_path(type, 3);
	if ((fd = open(&type[pos], O_RDONLY)) == -1)
	{
		free_mtx(map);
		error_handle(1, "Path of texture invalid\n", data());
	}
	close(fd);
	return (1);
}

static int	texture_info(char *type, t_tt *txt, t_data *game, char **map)
{
	int	pos;
	int	px;

	px = MULTIPLIER;
	pos = find_path(type, 3);
	if (text_exists(type, map))
	{
		txt->name = ft_strdup(&type[pos]);
		txt->img = mlx_xpm_file_to_image(game->mlx, txt->name, &px, &px);
		if (!txt->img)
		{
			free_mtx(map);
			error_handle(1, "Error with texture/n", game);
		}
		txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->l_length, &txt->endian);
	}
	return (0);
}

int	add_texture(char *file, t_data *game, char **map)
{
	int		i;
	char	start[3];

	i = 0;
	while(file[i] != '\n' && file[i] != '\0')
	{
		i += skip_spaces(file, start);
		if (!ft_strncmp(start, "NO", 3) && !game->map.ntt.name)
		{
			init_texture(&game->map.ntt);
			return (texture_info(file, &game->map.ntt, game, map));
		}
		else if (!ft_strncmp(start, "SO", 3) && !game->map.stt.name)
		{
			init_texture(&game->map.stt);
			return (texture_info(file, &game->map.stt, game, map));
		}
		else if (!ft_strncmp(start, "WE", 3) && !game->map.wtt.name)
		{
			init_texture(&game->map.wtt);
			return (texture_info(file, &game->map.wtt, game, map));
		}
		else if (!ft_strncmp(start, "EA", 3) && !game->map.ett.name)
		{
			init_texture(&game->map.ett);
			return (texture_info(file, &game->map.ett, game, map));
		}
		else if (!ft_strncmp(start, "F", 2) && !game->map.fcolor)
			return (color_info(file, &game->map, 1));
		else if (!ft_strncmp(start, "C", 2) && !game->map.ccolor)
			return (color_info(file, &game->map, 0));
		else
			return (-1);
		i++;
		 while (file[i] != '\n' && file[i] != '\0')
			i++;
		if (file[i] == '\n')
			i++;
	}
	return (-2);
}

int check_line(char *file)
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
	int i;

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
