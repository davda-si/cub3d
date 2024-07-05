/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:17 by david             #+#    #+#             */
/*   Updated: 2024/07/05 12:37:27 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		//parsing of the file, then of the map
		calculus(/*map*/NULL);
		//run game with all the calculus
	}
	else
		ft_printf("Wrong number of arguments, try again\n");
}
