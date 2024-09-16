/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:35 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/16 19:58:36 by davda-si         ###   ########.fr       */
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
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != '\n')
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

int	color_info(char *file, t_mapdata *map, int fl)
{
	int		pos;
	char	**rgb;
	char	*clean_path;

	pos = find_path(file, 2);
	clean_path = ft_strtrim(&file[pos], " \n\t");
	rgb = ft_split(clean_path, ',');
	free(clean_path);
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
		return (1);
	}
	return (0);
}

int	skip_spaces(char *file, char *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13)))
				i++;
	if (file[i])
		start[j++] = file[i++];
	if (file[i] && (file[i] != ' ' && file[i] != '\t'))
		start[j++] = file[i++];
	start[j] = '\0';
	return (i);
}

int	around_chr(char **map, int i, int j)
{
	int	x;

	x = 0;
	if (!map || !map[i])
		return (x);
	if ((j + 1) < (int)ft_strlen(map[i]) && map[i][j + 1] && ft_strchr("NEWS01", map[i][j + 1]))
		x++;
	if (j > 0 && (j - 1) < (int)ft_strlen(map[i]) && map[i][j - 1] && ft_strchr("NEWS01", map[i][j - 1]))
		x++;
	if (j < (int)ft_strlen(map[i + 1]) && map[i + 1] && map[i + 1][j] && ft_strchr("NEWS01", map[i + 1][j]))
		x++;
	if (i > 0 && j < (int)ft_strlen(map[i - 1]) && map[i - 1] && map[i - 1][j] && ft_strchr("NEWS01", map[i - 1][j]))
		x++;
	return (x);
}
