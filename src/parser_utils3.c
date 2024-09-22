/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:00:12 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/22 17:47:46 by phanta           ###   ########.fr       */
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
	if (!game->textures[0].img || !game->textures[1].img || !game->textures[2].img
		|| !game->textures[3].img || !game->map.fcolor || !game->map.ccolor)
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
	if (!ft_strcmp(start, "NO") && !game->textures[0].name)
	{
		init_texture(&game->textures[0]);
		return (texture_info(file, &game->textures[0], game, map));
	}
	else if (!ft_strcmp(start, "SO") && !game->textures[2].name)
	{
		printf("start-%s\n", start);
		init_texture(&game->textures[2]);
		return (texture_info(file, &game->textures[2], game, map));
	}
	else if (!ft_strcmp(start, "WE") && !game->textures[1].name)
	{
		init_texture(&game->textures[1]);
		return (texture_info(file, &game->textures[1], game, map));
	}
	else if (!ft_strcmp(start, "EA") && !game->textures[3].name)
	{
		init_texture(&game->textures[3]);
		return (texture_info(file, &game->textures[3], game, map));
	}
	else
		return (-1);
}

//printf("ntt-%p, wtt-%p, ett-%p, stt-%p, f-%d c%d\n",game->map.ntt.img,
//game->map.wtt.img, game->map.ett.img, game->map.stt.img, game->map.fcolor,
//game->map.ccolor);
