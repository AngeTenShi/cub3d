/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:27 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/29 19:05:46 by anggonza         ###   ########.fr       */
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
	int		read_val;
	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		display_error("File doesn't exist this may be a folder\n"); 
	read_val = read(fd, buffer, 65535);
	if (read_val < 0 || !check_format(av[1]))
		display_error("Bad file format .cub\n");
	map = ft_split(buffer, '\n');
	replace_space_by_zero(map);
	if (!ft_at_least_one(map))
		display_error("Invalid map");
	for (int i = 0; i < ft_strlenn(map); i++)
	{
		printf("%s\n",map[i]);
	}
	free_map(map);
	return (1);
}
