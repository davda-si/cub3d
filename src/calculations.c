/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:30 by phanta            #+#    #+#             */
/*   Updated: 2024/09/03 17:01:16 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void setplayer(char c, int y, int x)
{
    data()->posX=x*MULTIPLIER;
    data()->posY=y*MULTIPLIER;

    if(c=='N')
    {
        data()->dirX=0;
        data()->dirY=-1;
        data()->planeX=0.66;//not scalable, change
        data()->planeY=0;
    }
    if(c=='S')
    {
        data()->dirX=0;
        data()->dirY=1;
        data()->planeX=-0.66;
        data()->planeY=0;
    }
    if(c=='E')
    {
        data()->dirX=1;
        data()->dirY=0;
        data()->planeX=0;
        data()->planeY=0.66;
    }
    if(c=='W')
    {
        data()->dirX=-1;
        data()->dirY=0;
        data()->planeX=0;
        data()->planeY=-0.66;
    }
}

void drawRay(int x, int start, int end, unsigned long color)
{
	t_img	img;
	img.img = mlx_new_image(data()->mlx, RESW, RESH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while(++start>=end)
        my_mlx_pixel_put(&img, x, start, color);
    data()->current_frame=img;
}

void raycastLoop()
{
    int x=-1;
    int stepX;
    int stepY;
    int mapX = (double)data()->posX/MULTIPLIER;
    int mapY = (double)data()->posY/MULTIPLIER;
    int hit=0;
    int side;
    double sideDistX;
    double sideDistY;
    unsigned long color;
    
    while(++x<RESW)
    {
        data()->cameraX=2*x/((double)RESW)-1;
        data()->rayDirX=data()->dirX+data()->planeX*data()->cameraX;
        data()->rayDirY=data()->dirY+data()->planeY*data()->cameraX;
        if(data()->rayDirX==0)
            data()->deltaDistX=1e30;
        else
            data()->deltaDistX = fabs(1 / data()->rayDirX);
        if(data()->rayDirY==0)
            data()->deltaDistY=1e30;
        else
            data()->deltaDistY = fabs(1 / data()->rayDirY);
        if(data()->rayDirX<0)
        {
            stepX=-1;
            sideDistX=(data()->posX-mapX)*data()->deltaDistX;
        }
        else
        {
            stepX=1;
            sideDistX=(mapX+1-data()->posX)*data()->deltaDistX;
        }
        if(data()->rayDirY<0)
        {
            stepX=-1;
            sideDistY=(data()->posY-mapY)*data()->deltaDistY;
        }
        else
        {
            stepY=1;
            sideDistY=(mapY + 1 - data()->posY) * data()->deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += data()->deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += data()->deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (data()->map->map[mapX][mapY] > 0) 
                hit = 1;
        }
        if(side == 0)
            data()->perpWallDist=(sideDistX-data()->deltaDistX);
        else
            data()->perpWallDist=(sideDistY-data()->deltaDistY);
        
        int lineHeight=(int)(RESW/data()->perpWallDist);

        int drawStart=RESH/2-(lineHeight/2);
        if(drawStart<0)
            drawStart=0;
        int drawEnd=RESH/2+(lineHeight/2);
        if(drawEnd>=RESH)
            drawEnd=RESH-1;
        
        if(side==0 && data()->rayDirX<0)//E
            color=0xFF0000;
        if(side==0 && data()->rayDirX>0)//W
            color=0x0000FF;
        if(side==1 && data()->rayDirY<0)//S
            color=0x00FF00;
        if(side==1 && data()->rayDirY>0)//N
            color=0xFFFF00;
        else
            color=0xFFFFFF;
        if (side == 1)
            color = color / 2;
        drawRay(x, drawStart-1, drawEnd, color);
    }
    mlx_put_image_to_window(data()->mlx, data()->win, data()->current_frame.img, 0, 0);
    mlx_destroy_image(data()->mlx, data()->current_frame.img);
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
