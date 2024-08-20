/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:35 by davda-si          #+#    #+#             */
/*   Updated: 2024/08/20 18:03:31 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int numb_check(char **rgb)
{
	int	i;
	int	j;
	int	fl;

	i = 0;
	fl = 0;
	while(rgb[i] && fl < 3)
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (0);
		else
			fl++;
		i++;
	}
	if (fl != 3)
		return (0);
	return (1);
}

int	find_path(char *str, int i)
{
	if (!str || !str[i])
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| (str[i] >= 9 && str[i] <= 13)))
				i++;
	return (i);
}

int	color_info(char *file, t_mapdata *map, t_data *game, int fl)
{
	int		pos;
	char	**rgb;

	pos = find_path(file, 2);
	rgb = ft_split(file[pos], ',');
	if (numb_check(rgb))
	{
		if (fl)
			map->fcolor = (ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + (ft_atoi(rgb[2]));
		else
			map->ccolor = (ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + (ft_atoi(rgb[2]));
		free_mtx(rgb);
	}
	else
	{
		free_mtx(rgb);
		error_handle(1, "Error with color values\n", game);
	}
}

int	skip_spaces(char **file, char *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*file[i] && (*file[i] == ' ' || (*file[i] >= 9 && *file[i] <= 13)))
				i++;
	start[j++] = *file[i++];
	if (*file[i] && (*file[i] != ' ' && *file[i] != '\t'))
		start[j++] = *file[i++];
	else
		start[j++] = '\0';
	start[j] = '\0';
	return (i);
}
