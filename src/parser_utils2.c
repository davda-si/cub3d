/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:35 by davda-si          #+#    #+#             */
/*   Updated: 2024/09/23 21:11:04 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	numb_check(char **rgb)
{
	int	i;
	int	j;
	int	fl;

	i = 0;
	fl = 0;
	while (rgb[i])
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

int	find_path(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] != ' ' && str[i] != '\n'
			&& !(str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

int	color_info(char *file, t_mapdata *map, int fl)
{
	int		pos;
	char	**rgb;
	char	*clean_path;

	pos = find_path(file);
	clean_path = ft_strtrim(&file[pos], " \n\t");
	rgb = ft_split(clean_path, ',');
	free(clean_path);
	if (numb_check(rgb))
	{
		if (fl)
			map->fcolor = (ft_atoi(rgb[0]) << 16)
				+ (ft_atoi(rgb[1]) << 8) + (ft_atoi(rgb[2]));
		else
			map->ccolor = (ft_atoi(rgb[0]) << 16)
				+ (ft_atoi(rgb[1]) << 8) + (ft_atoi(rgb[2]));
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
	while (file[i] && j < 3)
	{
		start[j] = file[i];
		if (file[i] && (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13)))
		{
			while (j < 3)
				start[j++] = '\0';
			break ;
		}
		j++;
		i++;
	}
	start[3] = '\0';
	return (i);
}

int	around_chr(char **map, int i, int j)
{
	int	x;

	x = 4;
	if (!map || !map[i])
		return (0);
	if ((i - 1) < 0 || (j - 1) < 0)
		return (0);
	if ((j + 1) >= (int)cb_strlen(map[i]) || i + 1 >= data()->map.height)
		return (0);
	if (j >= (int)cb_strlen(map[i + 1]) || j >= (int)cb_strlen(map[i - 1]))
		return (0);
	if (ft_strchr("01NEWS", map[i][j + 1]) == NULL || ft_strchr("01NEWS", map[i][j - 1]) == NULL)
		return (0);
	if (ft_strchr("01NEWS", map[i + 1][j]) == NULL || ft_strchr("01NEWS", map[i - 1][j]) == NULL)
		return (0);
	return (x);
}

/* checka()
{

	while(4)
		i j
		funcao que checka(i, j)		
	if(i <0 || j<0)
		return(mau)
	if(i>height-1 || j>length(i))
		return(mau)
	if(ft_strchr("01NEWS"))
} */