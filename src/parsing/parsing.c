
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

int	parse_args(int ac, char **av)
{
	if (!check_format(av[1]))
		return (0);
	return (1);
}
