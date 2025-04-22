/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 22:23:55 by srioboo-         ###   ########.fr       */
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

void	move(mlx_image_t *img, int amount_x, int amount_y)
{
	img->instances[0].x += amount_x;
	img->instances[0].y += amount_y;
}
