/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:40:44 by david             #+#    #+#             */
/*   Updated: 2024/08/20 19:47:59 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	map_start(char *file)
{
	int	i;

	i = 0;
	if (file[i] == '\0')
		return (0);
	while(file[i])
	{
		if (file[i] && (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13) && !ft_strchr("10NSWE", file[i])))
			return (0);
		i++;
	}
	return (1);
}

int	read_map(char **file, t_data *game)
{
	int	i;

	i = 0;
	while(map_start(file[i]))
	{
		game->map->map_start = i;
	}
}