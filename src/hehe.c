/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hehe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:03:33 by phanta            #+#    #+#             */
/*   Updated: 2024/09/17 19:16:30 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	set_data(t_data *game)
{
	t_data	**data_ptr;

	data_ptr = (t_data **)data();
	*data_ptr = game;
}
