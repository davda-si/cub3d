/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:32:38 by guest             #+#    #+#             */
/*   Updated: 2024/09/23 18:18:08 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	safeguard(int value, int flag)//0=x, 1=y
{
	if (value < 0)
		return (0);
	if (flag == 1 && value >= data()->map.height)
		return (0);
	if (flag == 0 && value >= (int)ft_strlen(data()->map.map[safeguard((int)data()->pos_y, 1)]))
		return (0);
	return (1);
}

size_t	cb_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0' && s[a] != '\n')
	{
		a++;
	}
	return (a);
}

/* int	safeguard(int value, int flag)//0=x, 1=y
{
	if (value < 0)
		return (0);
	if (flag == 1 && value >= data()->map.height)
		return (data()->map.height - 1);
	if (flag == 0 && value >= (int)ft_strlen(data()->map.map[safeguard((int)data()->pos_y, 1)]))
		return (ft_strlen(data()->map.map[safeguard((int)data()->pos_y, 1)]) - 1);
	return (value);
} */