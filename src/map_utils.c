/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:46:12 by davda-si          #+#    #+#             */
/*   Updated: 2024/08/28 18:56:46 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	allct_map(char **map, t_data *game)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = game->map->map_start;
	end = game->map->map_end;
	game->map->map = malloc(sizeof(char **) * (end - start + 1));
	if (!game->map->map)
		error_handle(1, "Failed map allocation\n", game);
	while (start < end)
	{
		game->map->map[i] = ft_strdup(map[start]);
		i++;
		start++;
	}
}
