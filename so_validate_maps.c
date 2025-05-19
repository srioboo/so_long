/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_validate_maps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/20 09:32:03 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_data(t_map *map)
{
	int		result;
	char	target;

	result = TRUE;
	if (map->player_y <= 0 || map->player_x <= 0)
		return (close_map(map, "No player found"), FALSE);
	target = map->lines[map->player_y][map->player_x];
	is_player_blocked(map, map->player_y, map->player_x);
	if (map->player_blocked == TRUE)
		return (close_map(map, "PLAYER BLOCKED!!"), FALSE);
	fill(map->lines, (t_map_pos){map->map_with - 1, map->map_height - 1, '\0'},
		target, (t_map_pos){map->player_x, map->player_y, '\0'});
	if (map->nbr_player != 1)
		return (close_map(map, "More than one player is not allowed"), FALSE);
	if (map->nbr_fish == 0 || map->fish_blocked == TRUE)
		return (close_map(map, "No fish found or some fish are blocked"),
			FALSE);
	if (map->nbr_exit != 1 || map->exit_blocked == TRUE)
		return (close_map(map, "No exit, exit blocked or more than one exit"),
			FALSE);
	map = set_data_count(map);
	if (map->nbr_ocean > 1)
		return (close_map(map, "Exit route not found"), FALSE);
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

int	is_valid_extension(const char *file_name)
{
	char	*ext;

	ext = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (ext == NULL)
		return (FALSE);
	if (ft_strncmp(ext, ".ber", ft_strlen(ext)) == 0)
		return (TRUE);
	return (FALSE);
}
