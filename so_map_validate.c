/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/08 11:31:23 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*set_data_count(t_map *map)
{
	int		x;
	int		y;

	map->nbr_player = 0;
	map->nbr_exit = 0;
	map->nbr_ocean = 0;
	map->nbr_fish = 0;
	y = 0;
	while (map->lines[y] != NULL)
	{
		x = 0;
		while (map->lines[y][x] != '\0')
		{
			if (map->lines[y][x] == 'E')
				map->nbr_exit++;
			if (map->lines[y][x] == 'C')
				map->nbr_fish++;
			if (map->lines[y][x] == '0')
				map->nbr_ocean++;
			x++;
		}
		y++;
	}
	return (map);
}

static void	fill(char **tab, t_map_pos map_size,
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

int	is_valid_data(t_map *map)
{
	int		result;
	char	target;

	result = TRUE;
	if (map->player_y <= 0 || map->player_x <= 0)
		return (error_msg("No player found"), FALSE);
	target = map->lines[map->player_y][map->player_x];
	fill(map->lines, (t_map_pos){map->map_with - 1, map->map_height - 1, '\0'},
		target, (t_map_pos){map->player_x, map->player_y, '\0'});
	if (map->nbr_player != 1)
		return (error_msg("More than one player is not allowed"), FALSE);
	if (map->nbr_fish == 0)
		return (error_msg("No fish found"), FALSE);
	if (map->nbr_exit != 1)
		return (error_msg("No exit or exit number greater than one"), FALSE);
	map = set_data_count(map);
	if (map->nbr_ocean > 1)
		return (error_msg("Exit route not found"), FALSE);
	return (result);
}

int	is_valid_map_shape(t_map *map)
{
	int		y;
	int		x;
	size_t	initial_len;

	y = 0;
	initial_len = ft_strlen(map->lines[0]);
	while (map->lines[y] != NULL)
	{
		x = 0;
		while (map->lines[y][x] != '\n')
			x++;
		if (ft_strlen(map->lines[y]) != initial_len)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	is_valid_map_borders(t_map *map)
{
	int		y;
	int		x;
	int		initial_len;

	y = 0;
	initial_len = ft_strlen(map->lines[0]);
	while (map->lines[y] != NULL)
	{
		x = 0;
		while (map->lines[y][x] != '\n')
		{
			if (((y == 0 || y == (map->map_height - 2))
					&& (map->lines[y][x] != '1'))
				|| ((y > 0 && y < (map->map_height - 2))
				&& (x == 0 || x == (initial_len - 2))
				&& map->lines[y][x] != '1'))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}
