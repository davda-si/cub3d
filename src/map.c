/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:40:44 by david             #+#    #+#             */
/*   Updated: 2024/08/22 20:19:15 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	check_each_line(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		
		i++;
	}
	return (0);
}

static int	is_wall(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && !(line[i] >= 9 && line[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

int	map_start(char *file)
{
	int	i;

	i = 0;
	if (file[i] == '\0')
		return (0);
	while(file[i])
	{
		if ((file[i] != '\n' && file[i] != ' ' && !(file[i] >= 9 && file[i] <= 13)) && !ft_strchr("10NWES", file[i]))
			return (0);
		i++;
	}
	return (1);
}

int	read_map(char **file, t_data *game)
{
	int	i;

	i = 0;
	while(file[i])
	{
		while(map_start(file[i]))
			i++;
		game->map->map_start = i;
		
	}
}