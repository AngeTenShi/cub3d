/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:14:22 by anggonza          #+#    #+#             */
/*   Updated: 2022/10/29 19:22:29 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int ft_strlenn(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int count_occ(char **str, char letter)
{
    int i;
    int occ;
    int j;

    j = 0;
    i = 0;
    while (str[i])
    {
        while(str[i][j])
        {
            if (str[i][j] == letter)
                occ++;
            j++;
        }
        j = 0;
        i++;
    }
    return (occ);
}

int is_part_of_map(char *str)
{
    size_t i;

    i = 0;
    while (i < ft_strlen(str))
    {
        if (str[i] != 'N' && str[i] != 'E' && str[i] != 'S'
            && str[i] != 'W' && str[i] != '0' && str[i] != '1'  && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}
int is_wall_before_or_after(char *str, int i_actual)
{
    int i;
    int before;
    int after;

    after = 0;
    before = 0;
    i = 0;
    while (i < i_actual && before == 0)
    {
        if (str[i] == '1')
            before = 1;
        i++;
    }
    i = i_actual;
    while (str[i] && after == 0)
    {
        if (str[i] == '1')
            after = 1;
        i++;
    }
    return (after == 1 && before == 1);
}

void replace_space_by_zero(char **map)
{
    int i;
    size_t j;

    i = 0;
    while (i < ft_strlenn(map))
    {
        while (j < ft_strlen(map[i]))
        {
            if(!is_part_of_map(map[i]))
                break;
            if (map[i][j] == ' ')
            {
                if (is_wall_before_or_after(map[i], j))
                    map[i][j] = '0';
            }
            j++;
        }
        j = 0;
        i++;
    }
}