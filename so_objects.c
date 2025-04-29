/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/29 16:51:55 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_data	*get_objects_images(t_game_data *game_data)
{
	char	*path_wall;
	char	*path_ocean;
	char	*path_exit;
	char	*path_fish;

	path_wall = "./img/wall_64.png";
	game_data->wall_img = get_image(game_data->mlx, path_wall);
	path_ocean = "./img/ocean_64.png";
	game_data->ocean_img = get_image(game_data->mlx, path_ocean);
	path_exit = "./img/luffys_flag_64.png";
	game_data->exit_img = get_image(game_data->mlx, path_exit);
	path_fish = "./img/clown-fish_64.png";
	game_data->fish_img = get_image(game_data->mlx, path_fish);
	// TODO - asign and free memory
	// free(path_wall);
	// free(path_ocean);
	// free(path_exit);

	return (game_data);
}

int	draw_wall(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type == '1')
		result = mlx_image_to_window(game_data->mlx,
				game_data->wall_img, x * IMG_SIZE, y * IMG_SIZE);
	// mlx_set_instance_depth(game_data->wall_img->instances, 10);
	if (result < 0)
		error();
	return (result);
}

int	draw_ocean(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type != 'x')
		result = mlx_image_to_window(game_data->mlx,
				game_data->ocean_img, x * IMG_SIZE, y * IMG_SIZE);
	// mlx_set_instance_depth(game_data->ocean_img->instances, 0);
	if (result < 0)
		error();
	return (result);
}

int	draw_exit(t_game_data *game_data, char type, int x, int y)
{
	int		result;

	result = 0;
	if (type == 'E')
		result = mlx_image_to_window(game_data->mlx,
				game_data->exit_img, x * IMG_SIZE, y * IMG_SIZE);
	// mlx_set_instance_depth(game_data->exit_img->instances, 100);
	if (result < 0)
		error();
	return (result);
}
