/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:04:00 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/31 15:19:18 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_at_least_one(char **map)
{
	if (count_occ(map, 'P') != 1 || count_occ(map, 'E') < 1
		|| count_occ(map, 'C') < 1)
		return (-1);
	return (1);
}

int	index_begin_map(char **map)
{
	int	i;

	i = 0;
	while (map[i][0] != '1')
		i++;
	return (i);
}

int	ft_check_doubleret(char *map)
{
	size_t	i;
	int		j;
	int		in_map;

	j = 0;
	i = 2;
	in_map = 0;
	while (i < ft_strlen(map))
	{
		if (map[i - 1] == '1' && map[i - 2] == '1' && map[i] == '1')
			in_map = 1;
		if (map[i] == '\n' && map[i - 1] == '\n' && in_map)
			return (0);
		i++;
	}
	return (1);
}
