/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:27 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/31 15:07:33 by anggonza         ###   ########.fr       */
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

int	check_wall(char **map, int i, int begin, int left)
{
	int	size;

	size = begin;
	if (left)
	{
		if (i == ft_strlenn(map))
			return (1);
		else if (map[i][begin] != '1')
			return (0);
		else
			return (check_wall(map, i + 1, begin, left));
	}
	else
	{
		if (i == ft_strlenn(map) - index_begin_map(map))
			return (1);
		if (map[i][begin] != '1')
			return (0);
		while (map[i][size] == '1')
			size++;
		return (check_wall(map, i + 1, size - 1, 0));
	}
}

static int	ft_check_line_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_wall(char **map)
{
	int	i;

	i = 0;
	while (i < ft_strlenn(map))
	{
		if (i == 0 || i == ft_strlenn(map) - 1)
		{
			if (ft_check_line_wall(map[i]) == -1)
				return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_args(char **av)
{
	int		fd;
	char	buffer[65535];
	char	**map;
	int		read_val;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		display_error("File doesn't exist this may be a folder\n");
	read_val = read(fd, buffer, 65535);
	if (read_val < 0 || !check_format(av[1]))
		display_error("Bad file format .cub\n");
	if (!ft_check_doubleret(buffer))
		display_error("Jumping a line\n");
	map = ft_split(buffer, '\n');
	replace_space_by_zero(map);
	if (!ft_at_least_one(map))
		display_error("Invalid map\n");
	//if (!ft_check_wall(map))
	//display_error("Map not close\n");
	if (!check_wall(map, index_begin_map(map), 0, 0)
		|| !check_wall(map, index_begin_map(map), 0, 1))
		display_error("Map not close !\n");
	free_map(map);
	return (1);
}
