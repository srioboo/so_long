/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/02 22:49:30 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	draw_all(t_game_data *game_data, char type, int x, int y)
{
	int	result;

	result = 0;
	if (game_data->redraw == 0)
	{
		result += draw_ocean(game_data, type, x, y);
		result += draw_wall(game_data, type, x, y);
		result += draw_exit(game_data, type, x, y);
	}
	result += draw_fish(game_data, type, x, y);
	return (result);
}

int	draw_scene(t_game_data *game_data)
{
	int		result;
	int		y;
	int		x;
	char	**lines;
	int		nbr_lines;

	result = 0;
	y = 0;
	lines = game_data->map->lines;
	nbr_lines = game_data->map->map_height;
	game_data = get_objects_images(game_data);
	while (y < (nbr_lines - 1))
	{
		x = 0;
		while (lines[y][x] != 0)
		{
			result = draw_all(game_data, lines[y][x], x, y);
			x++;
		}
		y++;
	}
	return (result);
}
