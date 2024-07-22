/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/07/22 04:18:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	check_map(char **line, int fd, t_data *game)
{
	int flag;

	flag = 0;
	if (check_chr(*line))
		flag = 1;
	// after, add the line to the map, get a new line, more height and if flag is 1 free stuff and we good to go
	
}

static void read_file(int fd, t_data *game)
{
	char	*line;
	char	**split;
	int		flag;

	flag = 0;
	line = get_next_line(fd);
	while(line)
	{
		split = ft_split(line, " ");
		if (check_line(split))
			check_map(&line, fd, game);
		else
		{
			flag++;
			add_txture();
		}
		if (flag < 6 && line == NULL)
			free_stuff();
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
