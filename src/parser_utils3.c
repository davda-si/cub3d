/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:00:12 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/19 15:24:29 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	clear_file(int fd, char *file, t_data *game)
{
	char	**cpy_file;

	cpy_file = read_file(fd, game, file);
	if (!cpy_file)
		error_handle(1, "Error: empty file\n", game);
	if (check_textr(cpy_file, game))
	{
		free_mtx(cpy_file);
		error_handle(1, "textures don't work\n", game);
	}
	if (!game->map.ntt.img || !game->map.wtt.img || !game->map.ett.img
		|| !game->map.stt.img || !game->map.fcolor || !game->map.ccolor)
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

int	texttime(char *start, char **map, t_data *game, char *file)
{
	if (!ft_strcmp(start, "NO") && !game->map.ntt.name)
	{
		init_texture(&game->map.ntt);
		return (texture_info(file, &game->map.ntt, game, map));
	}
	else if (!ft_strcmp(start, "SO") && !game->map.stt.name)
	{
		printf("start-%s\n", start);
		init_texture(&game->map.stt);
		return (texture_info(file, &game->map.stt, game, map));
	}
	else if (!ft_strcmp(start, "WE") && !game->map.wtt.name)
	{
		init_texture(&game->map.wtt);
		return (texture_info(file, &game->map.wtt, game, map));
	}
	else if (!ft_strcmp(start, "EA") && !game->map.ett.name)
	{
		init_texture(&game->map.ett);
		return (texture_info(file, &game->map.ett, game, map));
	}
	else
		return (-1);
}

//printf("ntt-%p, wtt-%p, ett-%p, stt-%p, f-%d c%d\n",game->map.ntt.img,
//game->map.wtt.img, game->map.ett.img, game->map.stt.img, game->map.fcolor,
//game->map.ccolor);
