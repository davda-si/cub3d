/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:35 by guest             #+#    #+#             */
/*   Updated: 2024/07/08 18:00:12 by guest            ###   ########.fr       */
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
	{
		add_texture(file[0], file);
		return (0);
	}
	else if (!ft_strcmp(file[0], "F") || !ft_strcmp(file[0], "C"))
	{
		add_color(file[0], file);
		return (0);
	}
	else if (!ft_strcmp(file[0], "\n"))
		return (0);
	return (1);
}
