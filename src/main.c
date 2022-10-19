#include "../cub3d.h"

void	display_error(char *type)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(type, 2);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		display_error("Exec with format : ./cub3d map.cub\n");
		return (0);
	}
	else
		parse_args(ac, av);
	//init_map();
	return (1);
}
