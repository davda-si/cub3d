/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:46:12 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/21 09:53:02 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	allct_map(char **map, t_data *game)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = game->map.map_start;
	end = game->map.map_end;
	game->map.map = malloc(sizeof(char **) * (end - start + 1));
	if (!game->map.map)
	{
		free_mtx(map);
		error_handle(1, "Failed map allocation\n", game);
	}
	while (start < end)
	{
		game->map.map[i] = ft_strdup(map[start]);
		i++;
		start++;
	}
	game->map.height = i;
	game->map.map[i] = NULL;
}

void	init_texture(t_img *txt)
{
	txt->img = NULL;
	txt->name = NULL;
	txt->addr = NULL;
	txt->bits_per_pixel = 0;
	txt->line_length = 0;
	txt->endian = 0;
}

static int	maplength(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

int	check_upanddown(char **map, int i, int j, int flag)
{
	if (flag == 0)
	{
		while (i > 0)
		{
			i--;
			if (map[i][j] && map[i][j] == '1')
				return (0);
			if (map[i][j] && (map[i][j] == ' '
				|| (map[i][j] >= 9 && map[i][j] <= 13)))
				return (1);
		}
	}
	else
	{
		while (i < maplength(map))
		{
			i++;
			if (map[i][j] && map[i][j] == '1')
				return (0);
			if (map[i][j] && (map[i][j] == ' '
				|| (map[i][j] >= 9 && map[i][j] <= 13)))
				return (1);
		}
	}
	return (-1);
}
