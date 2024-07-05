/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hehe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:03:33 by phanta            #+#    #+#             */
/*   Updated: 2024/07/05 13:10:09 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_mapdata	*mapdata(void)
{
	static t_mapdata	mapdata;

	return (&mapdata);
}
