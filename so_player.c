/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/24 10:57:03 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*draw_player(mlx_t *mlx, t_game_data *game_data)
{
	mlx_image_t			*img;
	int					result;
	char				*relative_path;
	mlx_texture_t		*texture;

	relative_path = "./img/png/dolphin_64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(mlx, img,
			64 * (game_data->map->player_x),
			64 * (game_data->map->player_y));
	if (result < 0)
		error();
	return (img);
}

void	move_player(mlx_image_t *img, t_game_data *game_data,
				int steps_x, int steps_y)
{
	int	current_x;
	int	current_y;
	int pixels_x;
	int pixels_y;
	int	next_x;
	int next_y;

	pixels_x = img->instances[0].x;
	pixels_y = img->instances[0].y;
	current_x = pixels_x / (IMG_SIZE);
	current_y = pixels_y / (IMG_SIZE);
	next_x = (pixels_x + (steps_x * IMG_SIZE)) / IMG_SIZE;
	next_y = (pixels_y + (steps_y * IMG_SIZE)) / IMG_SIZE;

	if (is_move_posible(next_x, next_y) > 0)
		img->instances[0].x += (steps_x * IMG_SIZE);
	if (is_move_posible(next_x, next_y) > 0)
		img->instances[0].y += (steps_y * IMG_SIZE);

	ft_printf("X: %d - Y: %d (%d,%d) %c\n", current_x, current_y, steps_x, steps_y, game_data->player_img->enabled); // tODO - remove
}
