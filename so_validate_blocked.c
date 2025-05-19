/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_validate_blocked.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/20 09:07:59 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_exit_blocked(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		map->exit_blocked = TRUE;
}

void	is_player_blocked(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		map->player_blocked = TRUE;
}

void	is_fish_blocked(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		map->fish_blocked = TRUE;
}
