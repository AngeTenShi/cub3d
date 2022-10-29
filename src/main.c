/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:13 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/29 16:14:14 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_error(char *type)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(type, 2);
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		display_error("Exec with format : ./cub3d map.cub\n");
	parse_args(av);
	//init_map();
	return (1);
}
