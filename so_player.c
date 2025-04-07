/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/07 20:25:51 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t		*img; // TODO - is this allowed?

int	draw_player(mlx_t *mlx)
{
	int				result;
	char			*relative_path;
	// mlx_image_t		*img;
	mlx_texture_t	*texture;

	relative_path = "./img/png/dolphin_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(mlx, img, 64 * 5, 64 * 5);
	if (result < 0)
		error();
	return (result);
}

/* TODO - enable moviment */
// static void	move(mlx_t *mlx, mlx_image_t *img, int amount_x, int amount_y)
static void	move(int amount_x, int amount_y)
{
	//mlx_image_to_window(mlx, img, 800 + amount_x, 100 + amount_y);
	printf("%d %d %d", img->instances[0].x , amount_x, amount_y);
	// img->instances[0].x += amount_x;
	// img->instances[0].y += amount_y;
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	printf("key: %d\n", keydata.key);
	if ((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		move(5, 0);
	if ((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		move(5, 0);
	if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		move(0, 5);
	if ((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		move(0, 5);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
