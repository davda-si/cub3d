/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:30 by phanta            #+#    #+#             */
/*   Updated: 2024/07/05 13:10:28 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void setplayer(char c, int y, int x)
{
    data()->posX=x;
    data()->posY=y;
    if(c=='N')
    {
        data()->dirX=0;
        data()->dirY=-1;
    }
    if(c=='S')
    {
        data()->dirX=0;
        data()->dirY=1;
    }
    if(c=='E')
    {
        data()->dirX=1;
        data()->dirY=0;
    }
    if(c=='W')
    {
        data()->dirX=-1;
        data()->dirY=0;
    }
}

void calculus(char **map)//eu sei que aqui passei mas é para nao ter de estar a fazer mapdata()->map[i][j] everytime lmao
{
    int i;
    int j;

    i=0;
    j=0;
    while(map[i][j])
    {
        while(map[i][j])
        {
            if(map[i][j]=='N' ||map[i][j]=='S' ||map[i][j]=='E' ||map[i][j]=='W')//we can replace this by !isdigit se filtrarmos o mapa recebido para rejeitar outras letras
            {
                setplayer(map[i][j], i, j);
            }
            j++;
        }
        j=0;
        i++;
    }
}