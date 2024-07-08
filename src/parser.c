/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/07/07 02:10:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	check_file(char *file, t_data *game)
{
	int	fd;

	if ((fd = open(file, __O_DIRECTORY)) != -1)
		error_handle(0);
	if ((fd = open(file, O_RDONLY)) == -1)
		error_handle(0);
	
}