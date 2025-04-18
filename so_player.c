/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/21 22:40:42 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*g_img; // TODO - error

int	draw_player(mlx_t *mlx)
{
	int				result;
	char			*relative_path;
	mlx_texture_t	*texture;

	relative_path = "./img/png/dolphin_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	g_img = mlx_texture_to_image(mlx, texture);
	if (!g_img)
		error();
	result = mlx_image_to_window(mlx, g_img, 64 * 5, 64 * 5);
	if (result < 0)
		error();
	return (result);
}

static void	move(int amount_x, int amount_y)
{
	g_img->instances[0].x += amount_x;
	g_img->instances[0].y += amount_y;
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;
	int		step;

	mlx = param;
	step = 64;
	if ((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		move(step, 0);
	if ((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		move(-step, 0);
	if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		move(0, -step);
	if ((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		move(0, step);
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
