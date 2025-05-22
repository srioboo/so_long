/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/22 11:49:08 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	restart_count(t_map *map)
{
	map->nbr_player = 0;
	map->nbr_exit = 0;
	map->nbr_fish = 0;
	map->nbr_ocean = 0;
}

t_map	*data_count(t_map *map, char **map_content)
{
	int	y;
	int	x;

	restart_count(map);
	y = -1;
	while (map_content[++y] != NULL)
	{
		x = -1;
		while (map_content[y][++x] != '\0')
		{
			if (map_content[y][x] == 'E')
				map->nbr_exit++;
			if (map_content[y][x] == 'C')
				map->nbr_fish++;
			if (map_content[y][x] == '0')
				map->nbr_ocean++;
			if (is_char_allowed(map_content[y][x]) == FALSE)
				map->nbr_wrong++;
		}
	}
	return (map);
}

t_map	*set_data_count(t_map *map)
{
	map = data_count(map, map->lines);
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
	if ((tab[row][col] == 'X' || tab[row][col] != target)
		&& (c != '0' && c != 'C' && c != 'E'))
		return ;
	tab[row][col] = 'X';
	fill(tab, map_size, target, (t_map_pos){col - 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col + 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row - 1, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row + 1, '\0'});
}

char	**ft_dupmap(t_map *map)
{
	int		y;
	char	**lines;

	lines = (char **)malloc((map->map_height + 1) * sizeof(char *));
	y = 0;
	while (map->lines[y] != NULL)
	{
		lines[y] = ft_strdup(map->lines[y]);
		y++;
	}
	return (lines);
}
