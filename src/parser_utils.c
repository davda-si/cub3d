/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/08/13 17:45:27 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	add_texture(char *type, char **file)
{
	if (!ft_strncmp(file[0], "NO", 3))
		texture_info();
	
}

int check_line(char **file)
{
	if (!ft_strncmp(file[0], "NO", 3) || !ft_strncmp(file[0], "SO", 3)
		|| !ft_strncmp(file[0], "WE", 3) || !ft_strncmp(file[0], "EA", 3))
		return (0);
	else if (!ft_strncmp(file[0], "F", 1) || !ft_strncmp(file[0], "C", 1))
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
