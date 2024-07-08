/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/07/08 17:27:13 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void read_file(int fd, t_data *game)
{
	char	*line;
	char	**split;
	int		flag;

	flag = 0;
	line = get_next_line(fd);
	while(!flag && line)
	{
		split = ft_split(line, " ");
		if (check_line(split))
		{
			free(line);
			freesplit(split);
			error_handle(1, "Not a valid texture.\n", game);
		}
	}
}

void	check_file(char *file, t_data *game)
{
	int	fd;

	if ((fd = open(file, __O_DIRECTORY)) != -1)
	{
		close(fd);
		error_handle(1, "file's a directory\n", game);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		close(fd);
		error_handle(1, "can't open file\n", game);
	}
	fd = open(file, O_RDONLY);
	read_file(fd, game);
}
