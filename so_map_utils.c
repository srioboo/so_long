/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/20 09:06:26 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*set_data_count(t_map *map)
{
	int		x;
	int		y;

	map->nbr_ocean = 0;
	y = -1;
	while (map->lines[++y] != NULL)
	{
		x = -1;
		while (map->lines[y][++x] != '\0')
		{
			if (map->lines[y][x] == 'E')
			{
				is_exit_blocked(map, y, x);
				map->nbr_exit++;
			}
			if (map->lines[y][x] == 'C')
			{
				is_fish_blocked(map, y, x);
				map->nbr_fish++;
			}
			if (map->lines[y][x] == '0')
				map->nbr_ocean++;
		}
	}
	return (map);
}

void	fill(char **tab, t_map_pos map_size,
			char target, t_map_pos player_pos)
{
	int		row;
	int		col;
	char	c;

	row = player_pos.y;
	col = player_pos.x;
	c = tab[row][col];
	if (row < 0 || col < 0 || row >= map_size.y || col >= map_size.x)
		return ;
	if ((tab[row][col] == 'X' || tab[row][col] != target) && (c != '0'))
		return ;
	tab[row][col] = 'X';
	fill(tab, map_size, target, (t_map_pos){col - 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col + 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row - 1, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row + 1, '\0'});
}
