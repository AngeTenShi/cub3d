/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:19 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/31 15:20:14 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

int		parse_args(char **av);
void	display_error(char *type);
int		ft_strlenn(char **str);
int		is_part_of_map(char *str);
int		count_occ(char **str, char letter);
void	replace_space_by_zero(char **map);
void	free_map(char **map);
int		ft_at_least_one(char **map);
int		ft_check_doubleret(char *map);
int		index_begin_map(char **map);

#endif
