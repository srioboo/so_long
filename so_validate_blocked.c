/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_validate_blocked.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/21 12:59:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_sourrounded(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		return (TRUE);
	return (FALSE);
}

int	is_exit_route_blocked(t_map *map, char **map_content)
{
	map = data_count(map, map_content);
	if (map->nbr_ocean > 0 || map->nbr_fish > 0 || map->nbr_exit > 0)
		return (TRUE);
	return (FALSE);
}

int	is_player_blocked(t_map *map, int y, int x)
{
	map->player_blocked = is_sourrounded (map, y, x);
	return (map->player_blocked);
}
