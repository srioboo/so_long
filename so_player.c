/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/07 13:30:38 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_player(mlx_t *mlx)
{
	int				result;
	char			*relative_path;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	relative_path = "./img/png/dolphin_32x32.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(mlx, img, 30, 30);
	if (result < 0)
		error();
	return (result);
}

/* TODO - enable moviment */
static void	move(mlx_t *mlx, mlx_image_t *img, int amount_x, int amount_y)
{
	mlx_image_to_window(mlx, img, 800 + amount_x, 100 + amount_y);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;
	mlx = param;

	printf("param: %p\n", param);
	if (keydata.key == MLX_KEY_D)
	{
		printf("move: %d\n", keydata.key);
		// move(mlx, *img, 10, 0);
	}
	if (keydata.key == MLX_KEY_A)
		printf("move: %d\n", keydata.key);
	if (keydata.key == MLX_KEY_W)
		printf("move: %d\n", keydata.key);
	if (keydata.key == MLX_KEY_S)
		printf("move: %d\n", keydata.key);
}
