/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/07/29 19:14:27 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	add_texture(char *type, char **file)
{
	if (!ft_strcmp(file[0], "NO"))
		check_texture(file[1]);
	
}

int check_line(char **file)
{
	if (!ft_strcmp(file[0], "NO") || !ft_strcmp(file[0], "SO")
		|| !ft_strcmp(file[0], "WE") || !ft_strcmp(file[0], "EA"))
		return (0);
	else if (!ft_strcmp(file[0], "F") || !ft_strcmp(file[0], "C"))
		return (0);
	return (1);
}

int	check_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != NULL)
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'S' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
