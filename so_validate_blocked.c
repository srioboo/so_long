/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_validate_blocked.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/20 10:43:18 by srioboo-         ###   ########.fr       */
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

void	is_exit_blocked(t_map *map, int y, int x)
{
	map->exit_blocked = is_sourrounded (map, y, x);
}

void	is_player_blocked(t_map *map, int y, int x)
{
	map->player_blocked = is_sourrounded (map, y, x);
}

void	is_fish_blocked(t_map *map, int y, int x)
{
	map->fish_blocked = is_sourrounded (map, y, x);
}
