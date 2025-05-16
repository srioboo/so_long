/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_fish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/16 11:40:21 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_fish_blocked(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		map->fish_blocked = TRUE;
}

void	delete_fish_instance(t_game_data *game_data, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game_data->fish_img->count)
	{
		if (game_data->fish_img->instances[i].x == (x * IMG_SIZE)
			&& game_data->fish_img->instances[i].y == (y * IMG_SIZE))
			game_data->fish_img->enabled = 0;
		i++;
	}
}

int	draw_fish(t_game_data *game_data, char type, int x, int y)
{
	int			result;

	result = 0;
	if (type == 'C')
		result = mlx_image_to_window(game_data->mlx, game_data->fish_img,
				x * IMG_SIZE, y * IMG_SIZE);
	if (result < 0)
		error_msg("Can't draw the fish");
	return (result);
}
