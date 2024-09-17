/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:30 by phanta            #+#    #+#             */
/*   Updated: 2024/09/17 13:06:47 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void print_matrix(char **map)
{
    int i;
    int j;
    
    i=-1;
    if(!map)
        printf("mata-te\n");
    while(map[++i])
    {
        j=-1;
        while (map[i][++j])
            printf("%c ", map[i][j]);
        printf("\n");
    }
    data()->map.height=i;
    data()->map.length=j;
    printf("i=%i, j=%i\n", i, j);
}

void getmatrix(char *file)
{
    int		fd;
    int i;
    char **map;
    
    data()->map=(t_mapdata *)malloc(sizeof(t_mapdata));
    fd = open(file, O_RDONLY);
    i=0;
    map=(char **)malloc(sizeof(char *)*1000);
    map[i] = get_next_line(fd);
    while(map[i])
        map[++i]=get_next_line(fd);
    data()->map->map=map;
    print_matrix(data()->map->map);
}

