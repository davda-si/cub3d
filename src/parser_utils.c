/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/08/20 18:03:48 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int text_exists(char *type)
{
	int		fd;
	int		pos;

	pos = find_path(type, 3);
	if (fd = open(&type[pos], O_RDONLY) == -1)
	{
		close(fd);
		error_handle(1, "Path of texture invalid\n", data());
	}
	close(fd);
	return (1);
}

static int	texture_info(char *type, t_tt txt, t_data *game)
{
	int	pos;
	int	px;

	px = MULTIPLIER;
	pos = find_path(type, 3);
	if (text_exists(type))
	{
		txt.name = ft_strdup(&type[pos]);
		txt.img = mlx_xpm_file_to_image(game->mlx, txt.name, &px, &px);
		if (!txt.img)
			error_handle(1, "Error with the image\n", game);
		txt.addr = mlx_get_data_addr(txt.img, &txt.bpp, &txt.l_length, &txt.endian);
	}
	return (0);
}

int	add_texture(char *file, t_data *game)
{
	int		pos;
	char	start[3];

	pos = skip_spaces(&file, start);
	if (!ft_strncmp(start, "NO", 3))
		return (texture_info(file, game->map->ntt, game));
	else if (!ft_strncmp(start, "SO", 3))
		return (texture_info(file, game->map->stt, game));
	else if (!ft_strncmp(start, "WE", 3))
		return (texture_info(file, game->map->wtt, game));
	else if (!ft_strncmp(start, "EA", 3))
		return (texture_info(file, game->map->ett, game));
	else if (!ft_strncmp(start, "F", 2))
		return (color_info(file, game->map, game, 0));
	else if (!ft_strncmp(start, "C", 2))
		return (color_info(file, game->map, game, 1));
	else
		return (1);
}

int check_line(char *file)
{
	char	start[3];

	skip_spaces(&file, start);
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
	while (str[i] != '\n' && str[i] != NULL)
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'S' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
