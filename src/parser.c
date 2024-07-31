/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:55:48 by david             #+#    #+#             */
/*   Updated: 2024/07/31 04:39:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	check_map(char **line, int fd, t_data *game)
{
	int flag;

	flag = 0;
	if (check_str(*line))
		flag = 1;
	game->map->map = maplines_add(game, *line);
	// after, add the line to the map, get a new line, more height and if flag is 1 free stuff and we good to go
	
}

static char	**read_file(int fd, t_data *game)
{
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	**file;

	file = NULL;
	line = get_next_line(fd);
	while(1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		line = tmp2;
		free(tmp2);
	}
	file = ft_split(line, '\n');
	free(line);
	return (file);
}

void	check_file(char *file, t_data *game)
{
	int		fd;
	char	**file;

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
	file = read_file(fd, game);
}
