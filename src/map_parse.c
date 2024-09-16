/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:36:11 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/16 19:03:04 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	find_player(char **map)
{
	int		i;
	int		j;
	int		found;
	char	*player;

	i = 0;
	found = 0;
	player = "NEWS";
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (ft_strchr(player, map[i][j]))
				found++;
			j++;
		}
		i++;
	}
	return (found);
}

static int	check_st_end(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while(map && map[i])
	{
		j = 0;
		k = ft_strlen(map[i]);
		while (map[i][j] == ' ' || (map[i][j] >= 9 && map[i][j] <= 13))
			j++;
		while (map[i][k] == ' ' || (map[i][k] >= 9 && map[i][k] <= 13))
			k--;
		if (map[i][j] != '1' || map[i][k] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_around_chr(char **map)
{
	int		i;
	int		j;
	char	*player;

	player = "NEWS";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || ft_strchr(player, map[i][j]))
			{
				if (around_chr(map, i, j) != 4)
					return (1);
				else if (check_upanddown(map, i, j, 0) && check_upanddown(map, i, j, 1))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_each_line(char **map)
{
	int		i;
	int		j;
	char	*letters;

	i = 0;
	letters = "10NEWS\n";
	while(map && map[i])
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

int	map_parse(t_mapdata *map)
{
	if (check_each_line(map->map) && check_around_chr(map->map))
		return (1);
	if (check_st_end(map->map) && (find_player(map->map) != 1))
		return (1);
	return (0);
}
