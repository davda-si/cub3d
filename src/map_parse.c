/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:36:11 by davda-si          #+#    #+#             */
/*   Updated: 2024/08/28 19:48:55 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	check_each_line(char **map)
{
	int		i;
	int		j;
	char	*letters;

	i = 0;
	letters = "10NEWS\n";
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (ft_strchr(letters, map[i][j] == 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static check_st_end(char **map)
{
	
}

int	map_parse(t_mapdata *map)
{
	if (check_each_line(map->map) && check_st_end(map->map))
		return (1);
	if (check_around_chr(map->map) && find_player(map->map))
		return (1);
}