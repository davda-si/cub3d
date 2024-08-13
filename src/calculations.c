/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:30 by phanta            #+#    #+#             */
/*   Updated: 2024/08/09 19:19:05 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void setplayer(char c, int y, int x)
{
    data()->posX=x*MULTIPLIER;
    data()->posY=y*MULTIPLIER;

    data()->planeX=0;
    data()->planeY=0.66;
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

void raycastLoop()
{
    int x=-1;
    int stepX;
    int stepY;
    int mapX = (double)data()->posX/MULTIPLIER;
    int mapY = (double)data()->posY/MULTIPLIER;
    double sideDistX;
    double sideDistY;

    while(++x<RESW)
    {
        data()->cameraX=2*x/((double)RESW)-1;
        data()->rayDirX=data()->dirX+data()->planeX*data()->cameraX;
        data()->rayDirY=data()->dirY+data()->planeY*data()->cameraX;
        if(data()->rayDirX==0)
            data()->deltaDistX=1e30;
        else
            data()->deltaDistX = abs(1 / data()->rayDirX);
        if(data()->rayDirY==0)
            data()->deltaDistY=1e30;
        else
            data()->deltaDistY = abs(1 / data()->rayDirY);


    }
}

void calculus(char **map)//eu sei que aqui passei mas é para nao ter de estar a fazer mapdata()->map[i][j] everytime lmao
{
    int i;
    int j;

    i=0;
    j=0;
    while(i<(mapdata()->height/MULTIPLIER))
    {
        while(j<(mapdata()->length/MULTIPLIER))
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
    data()->time=0;
    data()->oldTime=0;
    raycastLoop();
}
