/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/16 11:41:45 by srioboo-         ###   ########.fr       */
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

t_game_data	*get_objects_images(t_game_data *game_data)
{
	game_data->wall_img = get_image(game_data,
			"./textures/wall_64.png");
	game_data->ocean_img = get_image(game_data,
			"./textures/ocean_64.png");
	game_data->exit_img = get_image(game_data,
			"./textures/luffys_flag_64.png");
	game_data->fish_img = get_image(game_data,
			"./textures/clown-fish_64.png");
	return (game_data);
}

int	draw_wall(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type == '1')
		result = mlx_image_to_window(game_data->mlx,
				game_data->wall_img, x * IMG_SIZE, y * IMG_SIZE);
	if (result < 0)
		error_msg("Can't draw the walls");
	return (result);
}

int	draw_ocean(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type == '0' || type == 'C' || type == 'P' || type == 'X')
		result = mlx_image_to_window(game_data->mlx,
				game_data->ocean_img, x * IMG_SIZE, y * IMG_SIZE);
	if (result < 0)
		error_msg("Can't draw the ocean");
	return (result);
}

int	draw_exit(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type == 'E')
		result = mlx_image_to_window(game_data->mlx,
				game_data->exit_img, x * IMG_SIZE, y * IMG_SIZE);
	if (result < 0)
		error_msg("Can't draw the exit");
	return (result);
}
