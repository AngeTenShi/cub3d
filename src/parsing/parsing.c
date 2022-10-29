/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:27 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/29 16:14:31 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_format(char *map_path)
{
	int	size;

	size = ft_strlen(map_path) - 1;
	if (!(map_path[size] == 'b' && map_path[size - 1] == 'u'
			&& map_path[size - 2] == 'c' && map_path[size - 3] == '.'))
	{
		display_error("It's not a .cub\n");
		return (0);
	}
	return (1);
}

int	parse_args(char **av)
{
	int	fd;
	char	buffer[65535];
	char	**map;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		display_error(""); 
	read(fd, buffer, 65535);
	if (read < 0 || !check_format(av[1]))
		display_error("Bad file format .cub");
	map = ft_split(buffer, "\n");
	

	return (1);
}
